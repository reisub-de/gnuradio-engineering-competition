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
#include <boost/range/algorithm/rotate.hpp>
#include <algorithm>
#include "immintrin.h"

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
      int rows, index;
      int offset;//,offset1,offset2,offset3,offset4,offset5,offset6,offset7,offset8,offset9,offset10,offset11,offset12,offset13,offset14,offset15;
      uint16_t pack;
      const int *twist;
      const int *mux;

      switch (signal_constellation) {
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
          //just calc it once
          
          rows = frame_size / (mod * 2);
          for (int i = 0; i < noutput_items; i += packed_items) {
            
            const uint16_t *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
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
            //for (int col = 0; col < (mod * 2); col++) {
              offset = twist[0];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 0)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[1];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 1)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[2];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 2)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[3];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 3)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[4];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 4)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[5];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 5)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[6];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 6)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[7];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 7)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }
            //}
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
            for (int d = 0; d < rows; d++) {
              pack = 0;
              //for (int e = 0; e < (mod * 2); e++) {
                offset = mux[0];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[1];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[2];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[3];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[4];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[5];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[6];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[7];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);
              //}
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
          
          rows = frame_size / (mod * 2);
          for (int i = 0; i < noutput_items; i += packed_items) {
            const uint16_t *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8, *c9, *c10, *c11, *c12;
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
            //memcpy(tempu, in, nbch);
            //in += nbch;
            for (int t = 0; t < q_val; t++) {
              for (int s = 0; s < 360; s++) {
                tempu[nbch + (360 * t) + s] = in[(q_val * s) + t];
              }
            }
            in = in + (q_val * 360);
            index = 0;
            //for (int col = 0; col < (mod * 2); col++) {
              offset = twist[0];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 0)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[1];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 1)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }
              offset = twist[2];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 2)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[3];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 3)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[4];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 4)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[5];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 5)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[6];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 6)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[7];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 7)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[8];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 8)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[9];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 9)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[10];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 10)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }

              offset = twist[11];
              for (int row = 0; row < rows; row++) {
                tempv[offset + (rows * 11)] = tempu[index++];
                offset++;
                if (offset == rows) {
                  offset = 0;
                }
              }
            //}
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
            for (int d = 0; d < rows; d++) {
              pack = 0;
              //for (int e = 0; e < (mod * 2); e++) {
                offset = mux[0];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[1];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[2];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[3];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[4];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[5];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[6];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[7];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[8];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[9];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[10];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);

                offset = mux[11];
                pack |= tempu[index++] << (((mod * 2) - 1) - offset);
              }
              out[produced++] = pack >> 6;
              out[produced++] = pack & 0x3f;
              consumed += (mod * 2);
            //}
          }
          break;
        case MOD_256QAM:

          if (frame_size == FRAME_SIZE_NORMAL) {
            if (code_rate == C3_5) {
              mux = &mux256_35[0];
            }
            else if (code_rate == C2_3) {
              mux = &mux256_23[0];
            }
            else {
              mux = &mux256[0];
            }
            
            rows = frame_size / (mod * 2);
            for (int i = 0; i < noutput_items; i += packed_items) {
              
              const uint16_t *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
              const uint16_t *c9, *c10, *c11, *c12, *c13, *c14, *c15, *c16;
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
              c13 = &tempv[rows * 12];
              c14 = &tempv[rows * 13];
              c15 = &tempv[rows * 14];
              c16 = &tempv[rows * 15];

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

              //for small loop counts do loop unrolling
              //for (int col = 0; col < mod2; col++) {

              
                //offset = twist256n[0];
              //use given rotation function from std library instead of the loops
                std::rotate_copy(tempu, tempu+ ((rows - twist256n[0])%rows), tempu+rows,tempv);
                std::rotate_copy(tempu + (rows * 1), tempu + (rows * 1) + ((rows - twist256n[1])%rows), tempu + (rows * 2),tempv + (rows * 1));
                std::rotate_copy(tempu + (rows * 2), tempu + (rows * 2) + ((rows - twist256n[2])%rows), tempu + (rows * 3),tempv + (rows * 2));
                std::rotate_copy(tempu + (rows * 3), tempu + (rows * 3) + ((rows - twist256n[3])%rows), tempu + (rows * 4),tempv + (rows * 3));
                std::rotate_copy(tempu + (rows * 4), tempu + (rows * 4) + ((rows - twist256n[4])%rows), tempu + (rows * 5),tempv + (rows * 4));
                std::rotate_copy(tempu + (rows * 5), tempu + (rows * 5) + ((rows - twist256n[5])%rows), tempu + (rows * 6),tempv + (rows * 5));
                std::rotate_copy(tempu + (rows * 6), tempu + (rows * 6) + ((rows - twist256n[6])%rows), tempu + (rows * 7),tempv + (rows * 6));
                std::rotate_copy(tempu + (rows * 7), tempu + (rows * 7) + ((rows - twist256n[7])%rows), tempu + (rows * 8),tempv + (rows * 7));
                std::rotate_copy(tempu + (rows * 8), tempu + (rows * 8) + ((rows - twist256n[8])%rows), tempu + (rows * 9),tempv + (rows * 8));
                std::rotate_copy(tempu + (rows * 9), tempu + (rows * 9) + ((rows - twist256n[9])%rows), tempu + (rows * 10),tempv + (rows * 9));
                std::rotate_copy(tempu + (rows * 10), tempu + (rows * 10) + ((rows - twist256n[10])%rows), tempu + (rows * 11),tempv + (rows * 10));
                std::rotate_copy(tempu + (rows * 11), tempu + (rows * 11) + ((rows - twist256n[11])%rows), tempu + (rows * 12),tempv + (rows * 11));
                std::rotate_copy(tempu + (rows * 12), tempu + (rows * 12) + ((rows - twist256n[12])%rows), tempu + (rows * 13),tempv + (rows * 12));
                std::rotate_copy(tempu + (rows * 13), tempu + (rows * 13) + ((rows - twist256n[13])%rows), tempu + (rows * 14),tempv + (rows * 13));
                std::rotate_copy(tempu + (rows * 14), tempu + (rows * 14) + ((rows - twist256n[14])%rows), tempu + (rows * 15),tempv + (rows * 14));
                std::rotate_copy(tempu + (rows * 15), tempu + (rows * 15) + ((rows - twist256n[15])%rows), tempu + (rows * 16),tempv + (rows * 15));/**/

              index = 0;

              unsigned char modulo_val;

#define AVX_OFF 0
#if AVX_OFF    
              modulo_val = 8;
              __m128i in1_128;
              __m128i in2_128;
              __m128i in3_128;
              __m128i in4_128;
              __m128i in5_128;
              __m128i in6_128;
              __m128i in7_128;
              __m128i in8_128;
              __m128i in9_128;
              __m128i in10_128;
              __m128i in11_128;
              __m128i in12_128;
              __m128i in13_128;
              __m128i in14_128;
              __m128i in15_128;
              __m128i in16_128;

              __m128i in1_128_shifted;
              __m128i in2_128_shifted;
              __m128i in3_128_shifted;
              __m128i in4_128_shifted;
              __m128i in5_128_shifted;
              __m128i in6_128_shifted;
              __m128i in7_128_shifted;
              __m128i in8_128_shifted;
              __m128i in9_128_shifted;
              __m128i in10_128_shifted;
              __m128i in11_128_shifted;
              __m128i in12_128_shifted;
              __m128i in13_128_shifted;
              __m128i in14_128_shifted;
              __m128i in15_128_shifted;
              __m128i in16_128_shifted;

		      __m128i out_128;
		      __m128i out2_128;

              for (int d = 0; d < rows - (rows%modulo_val); d+=modulo_val) {
                uint16_t packs[8] = {0};
                
                //better do loop unrolling for small number of loops
                //for (int e = 0; e < mod2; e++) {

				in1_128 = _mm_loadu_si128((__m128i*) &c1[d]);
				in2_128 = _mm_loadu_si128((__m128i*) &c2[d]);
				in3_128 = _mm_loadu_si128((__m128i*) &c3[d]);
				in4_128 = _mm_loadu_si128((__m128i*) &c4[d]);
				in5_128 = _mm_loadu_si128((__m128i*) &c5[d]);
				in6_128 = _mm_loadu_si128((__m128i*) &c6[d]);
				in7_128 = _mm_loadu_si128((__m128i*) &c7[d]);
				in8_128 = _mm_loadu_si128((__m128i*) &c8[d]);
				in9_128 = _mm_loadu_si128((__m128i*) &c9[d]);
				in10_128 = _mm_loadu_si128((__m128i*) &c10[d]);
				in11_128 = _mm_loadu_si128((__m128i*) &c11[d]);
				in12_128 = _mm_loadu_si128((__m128i*) &c12[d]);
				in13_128 = _mm_loadu_si128((__m128i*) &c13[d]);
				in14_128 = _mm_loadu_si128((__m128i*) &c14[d]);
				in15_128 = _mm_loadu_si128((__m128i*) &c15[d]);
				in16_128 = _mm_loadu_si128((__m128i*) &c16[d]);

				in1_128_shifted = _mm_slli_epi16(in1_128, 15 - mux[0]);				
				in2_128_shifted = _mm_slli_epi16(in2_128, 15 - mux[1]);				
				in3_128_shifted = _mm_slli_epi16(in3_128, 15 - mux[2]);
				in4_128_shifted = _mm_slli_epi16(in4_128, 15 - mux[3]);
				in5_128_shifted = _mm_slli_epi16(in5_128, 15 - mux[4]);
				in6_128_shifted = _mm_slli_epi16(in6_128, 15 - mux[5]);
				in7_128_shifted = _mm_slli_epi16(in7_128, 15 - mux[6]);
				in8_128_shifted = _mm_slli_epi16(in8_128, 15 - mux[7]);
				in9_128_shifted = _mm_slli_epi16(in9_128, 15 - mux[8]);
				in10_128_shifted = _mm_slli_epi16(in10_128, 15 - mux[9]);
				in11_128_shifted = _mm_slli_epi16(in11_128, 15 - mux[10]);
				in12_128_shifted = _mm_slli_epi16(in12_128, 15 - mux[11]);
				in13_128_shifted = _mm_slli_epi16(in13_128, 15 - mux[12]);
				in14_128_shifted = _mm_slli_epi16(in14_128, 15 - mux[13]);
				in15_128_shifted = _mm_slli_epi16(in15_128, 15 - mux[14]);
				in16_128_shifted = _mm_slli_epi16(in16_128, 15 - mux[15]);

		        out_128 = _mm_or_si128(in1_128_shifted, in2_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in3_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in4_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in5_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in6_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in7_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in8_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in9_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in10_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in11_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in12_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in13_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in14_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in15_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in16_128_shifted);

		        _mm_storeu_si128((__m128i*)&packs, out_128);

                //}
                *out++ = packs[0] >> 8;
                *out++ = packs[0] & 0xff;

                *out++ = packs[1] >> 8;
                *out++ = packs[1] & 0xff;

                *out++ = packs[2] >> 8;
                *out++ = packs[2] & 0xff;

                *out++ = packs[3] >> 8;
                *out++ = packs[3] & 0xff;

                *out++ = packs[4] >> 8;
                *out++ = packs[4] & 0xff;

                *out++ = packs[5] >> 8;
                *out++ = packs[5] & 0xff;

                *out++ = packs[6] >> 8;
                *out++ = packs[6] & 0xff;

                *out++ = packs[7] >> 8;
                *out++ = packs[7] & 0xff;



                /*uint16_t packs2[8] = {0};

                in1_128 = _mm_loadu_si128((__m128i*) &c1[d + 8]);
				in2_128 = _mm_loadu_si128((__m128i*) &c2[d + 8]);
				in3_128 = _mm_loadu_si128((__m128i*) &c3[d + 8]);
				in4_128 = _mm_loadu_si128((__m128i*) &c4[d + 8]);
				in5_128 = _mm_loadu_si128((__m128i*) &c5[d + 8]);
				in6_128 = _mm_loadu_si128((__m128i*) &c6[d + 8]);
				in7_128 = _mm_loadu_si128((__m128i*) &c7[d + 8]);
				in8_128 = _mm_loadu_si128((__m128i*) &c8[d + 8]);
				in9_128 = _mm_loadu_si128((__m128i*) &c9[d + 8]);
				in10_128 = _mm_loadu_si128((__m128i*) &c10[d + 8]);
				in11_128 = _mm_loadu_si128((__m128i*) &c11[d + 8]);
				in12_128 = _mm_loadu_si128((__m128i*) &c12[d + 8]);
				in13_128 = _mm_loadu_si128((__m128i*) &c13[d + 8]);
				in14_128 = _mm_loadu_si128((__m128i*) &c14[d + 8]);
				in15_128 = _mm_loadu_si128((__m128i*) &c15[d + 8]);
				in16_128 = _mm_loadu_si128((__m128i*) &c16[d + 8]);

				in1_128_shifted = _mm_slli_epi16(in1_128, 15 - mux[0]);				
				in2_128_shifted = _mm_slli_epi16(in2_128, 15 - mux[1]);				
				in3_128_shifted = _mm_slli_epi16(in3_128, 15 - mux[2]);
				in4_128_shifted = _mm_slli_epi16(in4_128, 15 - mux[3]);
				in5_128_shifted = _mm_slli_epi16(in5_128, 15 - mux[4]);
				in6_128_shifted = _mm_slli_epi16(in6_128, 15 - mux[5]);
				in7_128_shifted = _mm_slli_epi16(in7_128, 15 - mux[6]);
				in8_128_shifted = _mm_slli_epi16(in8_128, 15 - mux[7]);
				in9_128_shifted = _mm_slli_epi16(in9_128, 15 - mux[8]);
				in10_128_shifted = _mm_slli_epi16(in10_128, 15 - mux[9]);
				in11_128_shifted = _mm_slli_epi16(in11_128, 15 - mux[10]);
				in12_128_shifted = _mm_slli_epi16(in12_128, 15 - mux[11]);
				in13_128_shifted = _mm_slli_epi16(in13_128, 15 - mux[12]);
				in14_128_shifted = _mm_slli_epi16(in14_128, 15 - mux[13]);
				in15_128_shifted = _mm_slli_epi16(in15_128, 15 - mux[14]);
				in16_128_shifted = _mm_slli_epi16(in16_128, 15 - mux[15]);

		        out_128 = _mm_or_si128(in1_128_shifted, in2_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in3_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in4_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in5_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in6_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in7_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in8_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in9_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in10_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in11_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in12_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in13_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in14_128_shifted);
		        out2_128 = _mm_or_si128(out_128, in15_128_shifted);
		        out_128 = _mm_or_si128(out2_128, in16_128_shifted);

		        _mm_storeu_si128((__m128i*)&packs2, out_128);

                //}
                *out++ = packs2[0] >> 8;
                *out++ = packs2[0] & 0xff;

                *out++ = packs2[1] >> 8;
                *out++ = packs2[1] & 0xff;

                *out++ = packs2[2] >> 8;
                *out++ = packs2[2] & 0xff;

                *out++ = packs2[3] >> 8;
                *out++ = packs2[3] & 0xff;

                *out++ = packs2[4] >> 8;
                *out++ = packs2[4] & 0xff;

                *out++ = packs2[5] >> 8;
                *out++ = packs2[5] & 0xff;

                *out++ = packs2[6] >> 8;
                *out++ = packs2[6] & 0xff;

                *out++ = packs2[7] >> 8;
                *out++ = packs2[7] & 0xff;*/

                
                consumed += (mod * 2 * modulo_val);
              }
#else

              modulo_val = 16;
			  __m256i in1_256;
              __m256i in2_256;
              __m256i in3_256;
              __m256i in4_256;
              __m256i in5_256;
              __m256i in6_256;
              __m256i in7_256;
              __m256i in8_256;
              __m256i in9_256;
              __m256i in10_256;
              __m256i in11_256;
              __m256i in12_256;
              __m256i in13_256;
              __m256i in14_256;
              __m256i in15_256;
              __m256i in16_256;

              __m256i in1_256_shifted;
              __m256i in2_256_shifted;
              __m256i in3_256_shifted;
              __m256i in4_256_shifted;
              __m256i in5_256_shifted;
              __m256i in6_256_shifted;
              __m256i in7_256_shifted;
              __m256i in8_256_shifted;
              __m256i in9_256_shifted;
              __m256i in10_256_shifted;
              __m256i in11_256_shifted;
              __m256i in12_256_shifted;
              __m256i in13_256_shifted;
              __m256i in14_256_shifted;
              __m256i in15_256_shifted;
              __m256i in16_256_shifted;

		      __m256i out_256;
		      __m256i out2_256;

              for (int d = 0; d < rows-(rows%modulo_val); d+=modulo_val) {
                uint16_t packs[16] = {0};
                //better do loop unrolling for small number of loops
                //for (int e = 0; e < mod2; e++) {

				in1_256 = _mm256_loadu_si256((__m256i*) &c1[d]);
				in2_256 = _mm256_loadu_si256((__m256i*) &c2[d]);
				in3_256 = _mm256_loadu_si256((__m256i*) &c3[d]);
				in4_256 = _mm256_loadu_si256((__m256i*) &c4[d]);
				in5_256 = _mm256_loadu_si256((__m256i*) &c5[d]);
				in6_256 = _mm256_loadu_si256((__m256i*) &c6[d]);
				in7_256 = _mm256_loadu_si256((__m256i*) &c7[d]);
				in8_256 = _mm256_loadu_si256((__m256i*) &c8[d]);
				in9_256 = _mm256_loadu_si256((__m256i*) &c9[d]);
				in10_256 = _mm256_loadu_si256((__m256i*) &c10[d]);
				in11_256 = _mm256_loadu_si256((__m256i*) &c11[d]);
				in12_256 = _mm256_loadu_si256((__m256i*) &c12[d]);
				in13_256 = _mm256_loadu_si256((__m256i*) &c13[d]);
				in14_256 = _mm256_loadu_si256((__m256i*) &c14[d]);
				in15_256 = _mm256_loadu_si256((__m256i*) &c15[d]);
				in16_256 = _mm256_loadu_si256((__m256i*) &c16[d]);

				in1_256_shifted = _mm256_slli_epi16(in1_256, 15 - mux[0]);				
				in2_256_shifted = _mm256_slli_epi16(in2_256, 15 - mux[1]);				
				in3_256_shifted = _mm256_slli_epi16(in3_256, 15 - mux[2]);
				in4_256_shifted = _mm256_slli_epi16(in4_256, 15 - mux[3]);
				in5_256_shifted = _mm256_slli_epi16(in5_256, 15 - mux[4]);
				in6_256_shifted = _mm256_slli_epi16(in6_256, 15 - mux[5]);
				in7_256_shifted = _mm256_slli_epi16(in7_256, 15 - mux[6]);
				in8_256_shifted = _mm256_slli_epi16(in8_256, 15 - mux[7]);
				in9_256_shifted = _mm256_slli_epi16(in9_256, 15 - mux[8]);
				in10_256_shifted = _mm256_slli_epi16(in10_256, 15 - mux[9]);
				in11_256_shifted = _mm256_slli_epi16(in11_256, 15 - mux[10]);
				in12_256_shifted = _mm256_slli_epi16(in12_256, 15 - mux[11]);
				in13_256_shifted = _mm256_slli_epi16(in13_256, 15 - mux[12]);
				in14_256_shifted = _mm256_slli_epi16(in14_256, 15 - mux[13]);
				in15_256_shifted = _mm256_slli_epi16(in15_256, 15 - mux[14]);
				in16_256_shifted = _mm256_slli_epi16(in16_256, 15 - mux[15]);

		        out_256 = _mm256_or_si256(in1_256_shifted, in2_256_shifted);
		        out2_256 = _mm256_or_si256(out_256, in3_256_shifted);
		        out_256 = _mm256_or_si256(out2_256, in4_256_shifted);
		        out2_256 = _mm256_or_si256(out_256, in5_256_shifted);
		        out_256 = _mm256_or_si256(out2_256, in6_256_shifted);
		        out2_256 = _mm256_or_si256(out_256, in7_256_shifted);
		        out_256 = _mm256_or_si256(out2_256, in8_256_shifted);
		        out2_256 = _mm256_or_si256(out_256, in9_256_shifted);
		        out_256 = _mm256_or_si256(out2_256, in10_256_shifted);
		        out2_256 = _mm256_or_si256(out_256, in11_256_shifted);
		        out_256 = _mm256_or_si256(out2_256, in12_256_shifted);
		        out2_256 = _mm256_or_si256(out_256, in13_256_shifted);
		        out_256 = _mm256_or_si256(out2_256, in14_256_shifted);
		        out2_256 = _mm256_or_si256(out_256, in15_256_shifted);
		        out_256 = _mm256_or_si256(out2_256, in16_256_shifted);

		        _mm256_storeu_si256((__m256i*)&packs, out_256);

                //}
                *out++ = packs[0] >> 8;
                *out++ = packs[0] & 0xff;

                *out++ = packs[1] >> 8;
                *out++ = packs[1] & 0xff;

                *out++ = packs[2] >> 8;
                *out++ = packs[2] & 0xff;

                *out++ = packs[3] >> 8;
                *out++ = packs[3] & 0xff;

                *out++ = packs[4] >> 8;
                *out++ = packs[4] & 0xff;

                *out++ = packs[5] >> 8;
                *out++ = packs[5] & 0xff;

                *out++ = packs[6] >> 8;
                *out++ = packs[6] & 0xff;

                *out++ = packs[7] >> 8;
                *out++ = packs[7] & 0xff;

                *out++ = packs[8] >> 8;
                *out++ = packs[8] & 0xff;

                *out++ = packs[9] >> 8;
                *out++ = packs[9] & 0xff;

                *out++ = packs[10] >> 8;
                *out++ = packs[10] & 0xff;

                *out++ = packs[11] >> 8;
                *out++ = packs[11] & 0xff;

                *out++ = packs[12] >> 8;
                *out++ = packs[12] & 0xff;

                *out++ = packs[13] >> 8;
                *out++ = packs[13] & 0xff;

                *out++ = packs[14] >> 8;
                *out++ = packs[14] & 0xff;

                *out++ = packs[15] >> 8;
                *out++ = packs[15] & 0xff;
                
                consumed += (mod * 2 * modulo_val);
              }

#endif

              for (int d = (rows%modulo_val); d > 0; d--)
              {
              	pack = 0;

              	offset = mux[0];
                pack |= c1[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[1];
                pack |= c2[rows - d] << (((mod * 2) - 1) - offset);


                offset = mux[2];
                pack |= c3[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[3];
                pack |= c4[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[4];
                pack |= c5[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[5];
                pack |= c6[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[6];
                pack |= c7[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[7];
                pack |= c8[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[8];
                pack |= c9[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[9];
                pack |= c10[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[10];
                pack |= c11[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[11];
                pack |= c12[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[12];
                pack |= c13[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[13];
                pack |= c14[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[14];
                pack |= c15[rows - d] << (((mod * 2) - 1) - offset);

                offset = mux[15];
                pack |= c16[rows - d] << (((mod * 2) - 1) - offset);

                //printf("%d\n", pack);

                *out++ = pack >> 8;
                *out++ = pack & 0xff;

                consumed += (mod * 2);
              }
            }
          }
          else {
            if (code_rate == C1_3) {
              mux = &mux256s_13[0];
            }
            else if (code_rate == C2_5) {
              mux = &mux256s_25[0];
            }
            else {
              mux = &mux256s[0];
            }
            rows = frame_size / mod;
            for (int i = 0; i < noutput_items; i += packed_items) {
              
              const uint16_t *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
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
              //memcpy(tempu, in, nbch);
              for (int t = 0; t < q_val; t++) {
                for (int s = 0; s < 360; s++) {
                  tempu[nbch + (360 * t) + s] = in[(q_val * s) + t];
                }
              }
              in = in + (q_val * 360);
              index = 0;
              //for (int col = 0; col < mod; col++) {
                offset = twist256s[0];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 0)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }

                offset = twist256s[1];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 1)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }

                offset = twist256s[2];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 2)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }

                offset = twist256s[3];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 3)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }

                offset = twist256s[4];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 4)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }

                offset = twist256s[5];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 5)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }

                offset = twist256s[6];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 6)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }

                offset = twist256s[7];
                for (int row = 0; row < rows; row++) {
                  tempv[offset + (rows * 7)] = tempu[index++];
                  offset++;
                  if (offset == rows) {
                    offset = 0;
                  }
                }
              //}
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
              for (int d = 0; d < rows; d++) {
                pack = 0;
                //for (int e = 0; e < mod; e++) {
                offset = mux[0];
                pack |= tempu[index++] << ((mod - 1) - offset);

                offset = mux[1];
                pack |= tempu[index++] << ((mod - 1) - offset);

                offset = mux[2];
                pack |= tempu[index++] << ((mod - 1) - offset);

                offset = mux[3];
                pack |= tempu[index++] << ((mod - 1) - offset);

                offset = mux[4];
                pack |= tempu[index++] << ((mod - 1) - offset);

                offset = mux[5];
                pack |= tempu[index++] << ((mod - 1) - offset);

                offset = mux[6];
                pack |= tempu[index++] << ((mod - 1) - offset);

                offset = mux[7];
                pack |= tempu[index++] << ((mod - 1) - offset);

                //}
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

    const int dvbt2_interleaver_bb_impl::mux256_35[16] =
    {
      2, 11, 3, 4, 0, 9, 1, 8, 10, 13, 7, 14, 6, 15, 5, 12
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