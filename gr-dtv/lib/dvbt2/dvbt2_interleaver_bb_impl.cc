/* -*- c++ -*- */
/*
 * Copyright 2015,2016 Free Software Foundation, Inc.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "dvbt2_interleaver_bb_impl.h"

// intrinsics required for sse implementation
// TODO: move functionality to volk
#include <emmintrin.h>
#include <pmmintrin.h>
#include <tmmintrin.h>
#include <smmintrin.h>

// helper function for sse implementation
// takes 8 bytes from b and returns a byte of the lsbs of each b
// if n>0, take n bytes from b and 8-n bytes from a
uint8_t bits_to_byte_msb_twist(uint8_t* a, uint8_t* b, uint8_t n) {
  __m128i temp = _mm_loadl_epi64((__m128i*)(a-n)); // subtracting n gives already correctly shifted data
  if (n > 0) {
    __m128i temp2 = _mm_loadl_epi64((__m128i*)b);
    __m128i blendmask = _mm_set_epi8(128,128,128,128,128,128,128,128,
       n>7?128:0, n>6?128:0, n>5?128:0, n>4?128:0, n>3?128:0, n>2?128:0, n>1?128:0, n>0?128:0);
    temp = _mm_blendv_epi8(temp, temp2, blendmask);
  }
  __m128i shufmask = _mm_set_epi8(128,128,128,128,128,128,128,128,0,1,2,3,4,5,6,7);
  temp = _mm_shuffle_epi8(temp, shufmask);
  temp = _mm_slli_epi64(temp, 7);
  return _mm_movemask_epi8(temp) & 0xff;
}

namespace gr {
  namespace dtv {

    dvbt2_interleaver_bb::sptr
    dvbt2_interleaver_bb::make(dvb_framesize_t framesize, dvb_code_rate_t rate, dvb_constellation_t constellation)
    {
      return gnuradio::get_initial_sptr
        (new dvbt2_interleaver_bb_impl(framesize, rate, constellation));
    }

    /*
     * The private constructor
     */
    dvbt2_interleaver_bb_impl::dvbt2_interleaver_bb_impl(dvb_framesize_t framesize, dvb_code_rate_t rate, dvb_constellation_t constellation)
      : gr::block("dvbt2_interleaver_bb",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
      signal_constellation = constellation;
      code_rate = rate;
      if (framesize == FECFRAME_NORMAL) {
        frame_size = FRAME_SIZE_NORMAL;
        switch (rate) {
          case C1_2:
            nbch = 32400;
            q_val = 90;
            break;
          case C3_5:
            nbch = 38880;
            q_val = 72;
            break;
          case C2_3:
            nbch = 43200;
            q_val = 60;
            break;
          case C3_4:
            nbch = 48600;
            q_val = 45;
            break;
          case C4_5:
            nbch = 51840;
            q_val = 36;
            break;
          case C5_6:
            nbch = 54000;
            q_val = 30;
            break;
          default:
            nbch = 0;
            q_val = 0;
            break;

        }
      }
      else {
        frame_size = FRAME_SIZE_SHORT;
        switch (rate) {
          case C1_3:
            nbch = 5400;
            q_val = 30;
            break;
          case C2_5:
            nbch = 6480;
            q_val = 27;
            break;
          case C1_2:
            nbch = 7200;
            q_val = 25;
            break;
          case C3_5:
            nbch = 9720;
            q_val = 18;
            break;
          case C2_3:
            nbch = 10800;
            q_val = 15;
            break;
          case C3_4:
            nbch = 11880;
            q_val = 12;
            break;
          case C4_5:
            nbch = 12600;
            q_val = 10;
            break;
          case C5_6:
            nbch = 13320;
            q_val = 8;
            break;
          default:
            nbch = 0;
            q_val = 0;
            break;
        }
      }
      switch (constellation) {
        case MOD_QPSK:
          mod = 2;
          set_output_multiple(frame_size / mod);
          packed_items = frame_size / mod;
          break;
        case MOD_16QAM:
          mod = 4;
          set_output_multiple(frame_size / mod);
          packed_items = frame_size / mod;
          break;
        case MOD_64QAM:
          mod = 6;
          set_output_multiple(frame_size / mod);
          packed_items = frame_size / mod;
          break;
        case MOD_256QAM:
          mod = 8;
          set_output_multiple(frame_size / mod);
          packed_items = frame_size / mod;
          break;
        default:
          mod = 1;
          set_output_multiple(frame_size / mod);
          packed_items = frame_size / mod;
          break;
      }
    }

    /*
     * Our virtual destructor.
     */
    dvbt2_interleaver_bb_impl::~dvbt2_interleaver_bb_impl()
    {
    }

    void
    dvbt2_interleaver_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = noutput_items * mod;
    }

    int
    dvbt2_interleaver_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      int consumed = 0;
      int produced = 0;
      int rows, offset, index;
      unsigned int pack;
      const int *twist;
      const int *mux;
      // static bool debug_wrote_input = false;
      // static bool debug_wrote_output = false;

      switch (__builtin_expect(signal_constellation, MOD_256QAM)) { // hehe, corner-case optimization!
        case MOD_QPSK:
          for (int i = 0; i < noutput_items; i += packed_items) {
            rows = frame_size / 2;
            if (code_rate == C1_3 || code_rate == C2_5) {
              for (int k = 0; k < nbch; k++) {
                tempu[k] = *in++;
              }
              for (int t = 0; t < q_val; t++) {
                for (int s = 0; s < 360; s++) {
                  tempu[nbch + (360 * t) + s] = in[(q_val * s) + t];
                }
              }
              in = in + (q_val * 360);
              index = 0;
              for (int j = 0; j < rows; j++) {
                out[produced] = tempu[index++] << 1;
                out[produced++] |= tempu[index++];
                consumed += 2;
              }
            }
            else {
              for (int j = 0; j < rows; j++) {
                out[produced] = in[consumed++] << 1;
                out[produced++] |= in[consumed++];
              }
            }
          }
          break;
        case MOD_16QAM:
          if (frame_size == FRAME_SIZE_NORMAL) {
            twist = &twist16n[0];
          }
          else {
            twist = &twist16s[0];
          }
          if (code_rate == C3_5 && frame_size == FRAME_SIZE_NORMAL) {
            mux = &mux16_35[0];
          }
          else if (code_rate == C1_3 && frame_size == FRAME_SIZE_SHORT) {
            mux = &mux16_13[0];
          }
          else if (code_rate == C2_5 && frame_size == FRAME_SIZE_SHORT) {
            mux = &mux16_25[0];
          }
          else {
            mux = &mux16[0];
          }
          for (int i = 0; i < noutput_items; i += packed_items) {
            rows = frame_size / (mod * 2);
            const unsigned char *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
            c1 = &tempv[0];
            c2 = &tempv[rows];
            c3 = &tempv[rows * 2];
            c4 = &tempv[rows * 3];
            c5 = &tempv[rows * 4];
            c6 = &tempv[rows * 5];
            c7 = &tempv[rows * 6];
            c8 = &tempv[rows * 7];
            for (int k = 0; k < nbch; k++) {
              tempu[k] = *in++;
            }
            for (int t = 0; t < q_val; t++) {
              for (int s = 0; s < 360; s++) {
                tempu[nbch + (360 * t) + s] = in[(q_val * s) + t];
              }
            }
            in = in + (q_val * 360);
            index = 0;
            for (int col = 0; col < (mod * 2); col++) {
              offset = twist[col];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * col)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }
            }
            index = 0;
            for (int j = 0; j < rows; j++) {
              tempu[index++] = c1[j];
              tempu[index++] = c2[j];
              tempu[index++] = c3[j];
              tempu[index++] = c4[j];
              tempu[index++] = c5[j];
              tempu[index++] = c6[j];
              tempu[index++] = c7[j];
              tempu[index++] = c8[j];
            }
            index = 0;
            for (int d = 0; d < frame_size / (mod * 2); d++) {
              pack = 0;
              for (int e = 0; e < (mod * 2); e++) {
                offset = mux[e];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);
              }
              out[produced++] = pack >> 4;
              out[produced++] = pack & 0xf;
              consumed += (mod * 2);
            }
          }
          break;
        case MOD_64QAM:
          if (frame_size == FRAME_SIZE_NORMAL) {
            twist = &twist64n[0];
          }
          else {
            twist = &twist64s[0];
          }
          if (code_rate == C3_5 && frame_size == FRAME_SIZE_NORMAL) {
            mux = &mux64_35[0];
          }
          else if (code_rate == C1_3 && frame_size == FRAME_SIZE_SHORT) {
            mux = &mux64_13[0];
          }
          else if (code_rate == C2_5 && frame_size == FRAME_SIZE_SHORT) {
            mux = &mux64_25[0];
          }
          else {
            mux = &mux64[0];
          }
          for (int i = 0; i < noutput_items; i += packed_items) {
            rows = frame_size / (mod * 2);
            const unsigned char *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8, *c9, *c10, *c11, *c12;
            c1 = &tempv[0];
            c2 = &tempv[rows];
            c3 = &tempv[rows * 2];
            c4 = &tempv[rows * 3];
            c5 = &tempv[rows * 4];
            c6 = &tempv[rows * 5];
            c7 = &tempv[rows * 6];
            c8 = &tempv[rows * 7];
            c9 = &tempv[rows * 8];
            c10 = &tempv[rows * 9];
            c11 = &tempv[rows * 10];
            c12 = &tempv[rows * 11];
            for (int k = 0; k < nbch; k++) {
              tempu[k] = *in++;
            }
            for (int t = 0; t < q_val; t++) {
              for (int s = 0; s < 360; s++) {
                tempu[nbch + (360 * t) + s] = in[(q_val * s) + t];
              }
            }
            in = in + (q_val * 360);
            index = 0;
            for (int col = 0; col < (mod * 2); col++) {
              offset = twist[col];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * col)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }
            }
            index = 0;
            for (int j = 0; j < rows; j++) {
              tempu[index++] = c1[j];
              tempu[index++] = c2[j];
              tempu[index++] = c3[j];
              tempu[index++] = c4[j];
              tempu[index++] = c5[j];
              tempu[index++] = c6[j];
              tempu[index++] = c7[j];
              tempu[index++] = c8[j];
              tempu[index++] = c9[j];
              tempu[index++] = c10[j];
              tempu[index++] = c11[j];
              tempu[index++] = c12[j];
            }
            index = 0;
            for (int d = 0; d < frame_size / (mod * 2); d++) {
              pack = 0;
              for (int e = 0; e < (mod * 2); e++) {
                offset = mux[e];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);
              }
              out[produced++] = pack >> 6;
              out[produced++] = pack & 0x3f;
              consumed += (mod * 2);
            }
          }
          break;
        case MOD_256QAM:
          if (__builtin_expect(frame_size == FRAME_SIZE_NORMAL, 1)) { // hehe, corner-case optimization!
            if (code_rate == C3_5) {
              mux = &mux256_35[0];
            }
            else if (code_rate == C2_3) {
              mux = &mux256_23[0];
            }
            else {
              mux = &mux256[0];
            }
            for (int i = 0; i < noutput_items; i += packed_items) {
              // new implementation, only tested for qval=72, K=38880, channels=16, rows=4050
              // uses dirty sse instructions, move to volk in the future
              const int a=360;
              const int channels = mod*2;
              rows = frame_size/channels; // 4050
              const int full_columns = nbch/rows;
              const int full_columns_bits = full_columns*rows;
              const int last_info_column_bits = nbch-full_columns_bits;
              unsigned char* ut;
              // parity interleaving
              // only copy bytes starting at the first row which is not completely filled with information bits
              memcpy(tempu, in+full_columns*rows, last_info_column_bits);
              ut = tempu+last_info_column_bits;
              for (int t=0; t<q_val; t++)
                for (int s=0; s<a; s++)
                  *ut++ = in[nbch+q_val*s+t];
              // column twist interleaving
              for (int row = 0; row < rows; row+=8) {
                union { unsigned char c[16]; __m128i i; } a; // contains a 16 column and 8 row(bits) block
                // populate s (fetch 8 bit (from 8 bytes) for each column and assemble)
                for (int c_ind=0; c_ind<channels; c_ind++) {
                  if (c_ind >= full_columns)
                    ut = tempu + rows*(c_ind-full_columns);
                  else
                    ut = const_cast<unsigned char*>(in + rows*c_ind);
                  // TOOD: convert to full byte-wise input instead of single-bit-per-byte
                  const int twist = twist256n[c_ind];
                  uint8_t temp;
                  if (row<twist-8) {
                    temp = bits_to_byte_msb_twist(ut+rows-twist+row, 0, 0);
                  } else if (row<twist) {
                    temp = bits_to_byte_msb_twist(ut, ut+rows-twist+row, twist-row);
                  } else {
                    temp = bits_to_byte_msb_twist(ut+row-twist, 0, 0);
                  }
                  const int c = mux256_35[c_ind]; // does bitmuxing in advance
                  a.c[c] = temp;
                }
                // slice the column block and store in output buffer
                __m128i result;
                for (int s=0; s<8; s++) {
                  const uint16_t temp = _mm_movemask_epi8(a.i); // maybe need to reverse bit order
                  a.i = _mm_slli_epi64(a.i, 1);
                  result = _mm_bsrli_si128(result, 2);
                  result = _mm_insert_epi16(result, temp, 7);
                }
                // store slices (with workaround for buffers which are not aligned to 8 bytes)
                const int slice_cnt = rows-row>8 ? 8 : rows-row;
                if (slice_cnt==8)
                  _mm_storeu_si128((__m128i*)out, result);
                else {
                  memcpy(out, &result, slice_cnt*2);
                }
                out += slice_cnt*2;
              }
              consumed += frame_size;
              in += consumed;
            }
          }
          else { // -> FRAME_SIZE_SHORT (unused)
            if (code_rate == C1_3) {
              mux = &mux256s_13[0];
            }
            else if (code_rate == C2_5) {
              mux = &mux256s_25[0];
            }
            else {
              mux = &mux256s[0];
            }
            for (int i = 0; i < noutput_items; i += packed_items) {
              rows = frame_size / mod;
              const unsigned char *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
              c1 = &tempv[0];
              c2 = &tempv[rows];
              c3 = &tempv[rows * 2];
              c4 = &tempv[rows * 3];
              c5 = &tempv[rows * 4];
              c6 = &tempv[rows * 5];
              c7 = &tempv[rows * 6];
              c8 = &tempv[rows * 7];
              for (int k = 0; k < nbch; k++) {
                tempu[k] = *in++;
              }
              for (int t = 0; t < q_val; t++) {
                for (int s = 0; s < 360; s++) {
                  tempu[nbch + (360 * t) + s] = in[(q_val * s) + t];
                }
              }
              in = in + (q_val * 360);
              index = 0;
              for (int col = 0; col < mod; col++) {
                offset = twist256s[col];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * col)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }
              }
              index = 0;
              for (int j = 0; j < rows; j++) {
                tempu[index++] = c1[j];
                tempu[index++] = c2[j];
                tempu[index++] = c3[j];
                tempu[index++] = c4[j];
                tempu[index++] = c5[j];
                tempu[index++] = c6[j];
                tempu[index++] = c7[j];
                tempu[index++] = c8[j];
              }
              index = 0;
              for (int d = 0; d < frame_size / mod; d++) {
                pack = 0;
                for (int e = 0; e < mod; e++) {
                  offset = mux[e];
                  pack |= tempu[index++] << ((mod - 1) - offset);
                }
                out[produced++] = pack & 0xff;
                consumed += mod;
              }
            }
          }
          break;
      }

      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (consumed);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

    const int dvbt2_interleaver_bb_impl::twist16n[8] =
    {
      0, 0, 2, 4, 4, 5, 7, 7
    };

    const int dvbt2_interleaver_bb_impl::twist64n[12] =
    {
      0, 0, 2, 2, 3, 4, 4, 5, 5, 7, 8, 9
    };

    const int dvbt2_interleaver_bb_impl::twist256n[16] =
    {
      0, 2, 2, 2, 2, 3, 7, 15, 16, 20, 22, 22, 27, 27, 28, 32
    };

    const int dvbt2_interleaver_bb_impl::twist16s[8] =
    {
      0, 0, 0, 1, 7, 20, 20, 21
    };

    const int dvbt2_interleaver_bb_impl::twist64s[12] =
    {
      0, 0, 0, 2, 2, 2, 3, 3, 3, 6, 7, 7
    };

    const int dvbt2_interleaver_bb_impl::twist256s[8] =
    {
      0, 0, 0, 1, 7, 20, 20, 21
    };

    const int dvbt2_interleaver_bb_impl::mux16[8] =
    {
      7, 1, 4, 2, 5, 3, 6, 0
    };

    const int dvbt2_interleaver_bb_impl::mux64[12] =
    {
      11, 7, 3, 10, 6, 2, 9, 5, 1, 8, 4, 0
    };

    const int dvbt2_interleaver_bb_impl::mux256[16] =
    {
      15, 1, 13, 3, 8, 11, 9, 5, 10, 6, 4, 7, 12, 2, 14, 0
    };

    const int dvbt2_interleaver_bb_impl::mux16_35[8] =
    {
      0, 5, 1, 2, 4, 7, 3, 6
    };

    const int dvbt2_interleaver_bb_impl::mux16_13[8] =
    {
      6, 0, 3, 4, 5, 2, 1, 7
    };

    const int dvbt2_interleaver_bb_impl::mux16_25[8] =
    {
      7, 5, 4, 0, 3, 1, 2, 6
    };

    const int dvbt2_interleaver_bb_impl::mux64_35[12] =
    {
      2, 7, 6, 9, 0, 3, 1, 8, 4, 11, 5, 10
    };

    const int dvbt2_interleaver_bb_impl::mux64_13[12] =
    {
      4, 2, 0, 5, 6, 1, 3, 7, 8, 9, 10, 11
    };

    const int dvbt2_interleaver_bb_impl::mux64_25[12] =
    {
      4, 0, 1, 6, 2, 3, 5, 8, 7, 10, 9, 11
    };

    // warning: this table has been modified (inverted and byteswapped)
    // to improve the performance of the sse implementation
    const int dvbt2_interleaver_bb_impl::mux256_35[16] =
    {
      5, 12, 4, 3, 7, 14, 6, 15, 13, 10, 0, 9, 1, 8, 2, 11
    };

    const int dvbt2_interleaver_bb_impl::mux256_23[16] =
    {
      7, 2, 9, 0, 4, 6, 13, 3, 14, 10, 15, 5, 8, 12, 11, 1
    };

    const int dvbt2_interleaver_bb_impl::mux256s[8] =
    {
      7, 3, 1, 5, 2, 6, 4, 0
    };

    const int dvbt2_interleaver_bb_impl::mux256s_13[8] =
    {
      4, 0, 1, 2, 5, 3, 6, 7
    };

    const int dvbt2_interleaver_bb_impl::mux256s_25[8] =
    {
      4, 0, 5, 1, 2, 3, 6, 7
    };

  } /* namespace dtv */
} /* namespace gr */
