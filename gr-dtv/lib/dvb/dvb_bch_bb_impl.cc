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
#include "dvb_bch_bb_impl.h"

namespace gr {
  namespace dtv {

    dvb_bch_bb::sptr
    dvb_bch_bb::make(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate)
    {
      return gnuradio::get_initial_sptr
        (new dvb_bch_bb_impl(standard, framesize, rate));
    }

    /*
     * The private constructor
     */
    dvb_bch_bb_impl::dvb_bch_bb_impl(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate)
      : gr::block("dvb_bch_bb",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
      if (framesize == FECFRAME_NORMAL) {
        switch (rate) {
          case C1_4:
            kbch = 16008;
            nbch = 16200;
            bch_code = BCH_CODE_N12;
            break;
          case C1_3:
            kbch = 21408;
            nbch = 21600;
            bch_code = BCH_CODE_N12;
            break;
          case C2_5:
            kbch = 25728;
            nbch = 25920;
            bch_code = BCH_CODE_N12;
            break;
          case C1_2:
            kbch = 32208;
            nbch = 32400;
            bch_code = BCH_CODE_N12;
            break;
          case C3_5:
            kbch = 38688;
            nbch = 38880;
            bch_code = BCH_CODE_N12;
            break;
          case C2_3:
            kbch = 43040;
            nbch = 43200;
            bch_code = BCH_CODE_N10;
            break;
          case C3_4:
            kbch = 48408;
            nbch = 48600;
            bch_code = BCH_CODE_N12;
            break;
          case C4_5:
            kbch = 51648;
            nbch = 51840;
            bch_code = BCH_CODE_N12;
            break;
          case C5_6:
            kbch = 53840;
            nbch = 54000;
            bch_code = BCH_CODE_N10;
            break;
          case C8_9:
            kbch = 57472;
            nbch = 57600;
            bch_code = BCH_CODE_N8;
            break;
          case C9_10:
            kbch = 58192;
            nbch = 58320;
            bch_code = BCH_CODE_N8;
            break;
          case C2_9_VLSNR:
            kbch = 14208;
            nbch = 14400;
            bch_code = BCH_CODE_N12;
            break;
          case C13_45:
            kbch = 18528;
            nbch = 18720;
            bch_code = BCH_CODE_N12;
            break;
          case C9_20:
            kbch = 28968;
            nbch = 29160;
            bch_code = BCH_CODE_N12;
            break;
          case C90_180:
            kbch = 32208;
            nbch = 32400;
            bch_code = BCH_CODE_N12;
            break;
          case C96_180:
            kbch = 34368;
            nbch = 34560;
            bch_code = BCH_CODE_N12;
            break;
          case C11_20:
            kbch = 35448;
            nbch = 35640;
            bch_code = BCH_CODE_N12;
            break;
          case C100_180:
            kbch = 35808;
            nbch = 36000;
            bch_code = BCH_CODE_N12;
            break;
          case C104_180:
            kbch = 37248;
            nbch = 37440;
            bch_code = BCH_CODE_N12;
            break;
          case C26_45:
            kbch = 37248;
            nbch = 37440;
            bch_code = BCH_CODE_N12;
            break;
          case C18_30:
            kbch = 38688;
            nbch = 38880;
            bch_code = BCH_CODE_N12;
            break;
          case C28_45:
            kbch = 40128;
            nbch = 40320;
            bch_code = BCH_CODE_N12;
            break;
          case C23_36:
            kbch = 41208;
            nbch = 41400;
            bch_code = BCH_CODE_N12;
            break;
          case C116_180:
            kbch = 41568;
            nbch = 41760;
            bch_code = BCH_CODE_N12;
            break;
          case C20_30:
            kbch = 43008;
            nbch = 43200;
            bch_code = BCH_CODE_N12;
            break;
          case C124_180:
            kbch = 44448;
            nbch = 44640;
            bch_code = BCH_CODE_N12;
            break;
          case C25_36:
            kbch = 44808;
            nbch = 45000;
            bch_code = BCH_CODE_N12;
            break;
          case C128_180:
            kbch = 45888;
            nbch = 46080;
            bch_code = BCH_CODE_N12;
            break;
          case C13_18:
            kbch = 46608;
            nbch = 46800;
            bch_code = BCH_CODE_N12;
            break;
          case C132_180:
            kbch = 47328;
            nbch = 47520;
            bch_code = BCH_CODE_N12;
            break;
          case C22_30:
            kbch = 47328;
            nbch = 47520;
            bch_code = BCH_CODE_N12;
            break;
          case C135_180:
            kbch = 48408;
            nbch = 48600;
            bch_code = BCH_CODE_N12;
            break;
          case C140_180:
            kbch = 50208;
            nbch = 50400;
            bch_code = BCH_CODE_N12;
            break;
          case C7_9:
            kbch = 50208;
            nbch = 50400;
            bch_code = BCH_CODE_N12;
            break;
          case C154_180:
            kbch = 55248;
            nbch = 55440;
            bch_code = BCH_CODE_N12;
            break;
          default:
            kbch = 0;
            nbch = 0;
            bch_code = 0;
            break;
        }
      }
      else if (framesize == FECFRAME_SHORT) {
        switch (rate) {
          case C1_4:
            kbch = 3072;
            nbch = 3240;
            bch_code = BCH_CODE_S12;
            break;
          case C1_3:
            kbch = 5232;
            nbch = 5400;
            bch_code = BCH_CODE_S12;
            break;
          case C2_5:
            kbch = 6312;
            nbch = 6480;
            bch_code = BCH_CODE_S12;
            break;
          case C1_2:
            kbch = 7032;
            nbch = 7200;
            bch_code = BCH_CODE_S12;
            break;
          case C3_5:
            kbch = 9552;
            nbch = 9720;
            bch_code = BCH_CODE_S12;
            break;
          case C2_3:
            kbch = 10632;
            nbch = 10800;
            bch_code = BCH_CODE_S12;
            break;
          case C3_4:
            kbch = 11712;
            nbch = 11880;
            bch_code = BCH_CODE_S12;
            break;
          case C4_5:
            kbch = 12432;
            nbch = 12600;
            bch_code = BCH_CODE_S12;
            break;
          case C5_6:
            kbch = 13152;
            nbch = 13320;
            bch_code = BCH_CODE_S12;
            break;
          case C8_9:
            kbch = 14232;
            nbch = 14400;
            bch_code = BCH_CODE_S12;
            break;
          case C11_45:
            kbch = 3792;
            nbch = 3960;
            bch_code = BCH_CODE_S12;
            break;
          case C4_15:
            kbch = 4152;
            nbch = 4320;
            bch_code = BCH_CODE_S12;
            break;
          case C14_45:
            kbch = 4872;
            nbch = 5040;
            bch_code = BCH_CODE_S12;
            break;
          case C7_15:
            kbch = 7392;
            nbch = 7560;
            bch_code = BCH_CODE_S12;
            break;
          case C8_15:
            kbch = 8472;
            nbch = 8640;
            bch_code = BCH_CODE_S12;
            break;
          case C26_45:
            kbch = 9192;
            nbch = 9360;
            bch_code = BCH_CODE_S12;
            break;
          case C32_45:
            kbch = 11352;
            nbch = 11520;
            bch_code = BCH_CODE_S12;
            break;
          case C1_5_VLSNR_SF2:
            kbch = 2512;
            nbch = 2680;
            bch_code = BCH_CODE_S12;
            break;
          case C11_45_VLSNR_SF2:
            kbch = 3792;
            nbch = 3960;
            bch_code = BCH_CODE_S12;
            break;
          case C1_5_VLSNR:
            kbch = 3072;
            nbch = 3240;
            bch_code = BCH_CODE_S12;
            break;
          case C4_15_VLSNR:
            kbch = 4152;
            nbch = 4320;
            bch_code = BCH_CODE_S12;
            break;
          case C1_3_VLSNR:
            kbch = 5232;
            nbch = 5400;
            bch_code = BCH_CODE_S12;
            break;
          default:
            kbch = 0;
            nbch = 0;
            bch_code = 0;
            break;
        }
      }
      else {
        switch (rate) {
          case C1_5_MEDIUM:
            kbch = 5660;
            nbch = 5840;
            bch_code = BCH_CODE_M12;
            break;
          case C11_45_MEDIUM:
            kbch = 7740;
            nbch = 7920;
            bch_code = BCH_CODE_M12;
            break;
          case C1_3_MEDIUM:
            kbch = 10620;
            nbch = 10800;
            bch_code = BCH_CODE_M12;
            break;
          default:
            kbch = 0;
            nbch = 0;
            bch_code = 0;
            break;
        }
      }

      //bch_poly_build_tables();
      set_output_multiple(nbch);
    }

    /*
     * Our virtual destructor.
     */
    dvb_bch_bb_impl::~dvb_bch_bb_impl()
    {
    }

    void
    dvb_bch_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      ninput_items_required[0] = (noutput_items / nbch) * kbch / 8;
    }

    /*
     * Polynomial calculation routines
     * multiply polynomials
     */
    int
    dvb_bch_bb_impl::poly_mult(const int *ina, int lena, const int *inb, int lenb, int *out)
    {
      memset(out, 0, sizeof(int) * (lena + lenb));

      for (int i = 0; i < lena; i++) {
        for (int j = 0; j < lenb; j++) {
          if (ina[i] * inb[j] > 0 ) {
            out[i + j]++;    // count number of terms for this pwr of x
          }
        }
      }
      int max = 0;
      for (int i = 0; i < lena + lenb; i++) {
        out[i] = out[i] & 1;    // If even ignore the term
        if(out[i]) {
          max = i;
        }
      }
      // return the size of array to house the result.
      return max + 1;
    }

    /*
     * Pack the polynomial into a 32 bit array
     */
    void
    dvb_bch_bb_impl::poly_pack(const int *pin, unsigned int* pout, int len)
    {
      int lw = len / 32;
      int ptr = 0;
      unsigned int temp;
      if (len % 32) {
        lw++;
      }

      for (int i = 0; i < lw; i++) {
        temp = 0x80000000;
        pout[i] = 0;
        for (int j = 0; j < 32; j++) {
          if (pin[ptr++]) {
            pout[i] |= temp;
          }
          temp >>= 1;
        }
      }
    }

    void
    dvb_bch_bb_impl::poly_reverse(int *pin, int *pout, int len)
    {
      int c;
      c = len - 1;

      for (int i = 0; i < len; i++) {
        pout[c--] = pin[i];
      }
    }

    /*
     *Shift a 128 bit register
     */
    inline void
    dvb_bch_bb_impl::reg_4_shift(unsigned int *sr)
    {
      sr[3] = (sr[3] >> 1) | (sr[2] << 31);
      sr[2] = (sr[2] >> 1) | (sr[1] << 31);
      sr[1] = (sr[1] >> 1) | (sr[0] << 31);
      sr[0] = (sr[0] >> 1);
    }

    /*
     * Shift 160 bits
     */
    inline void
    dvb_bch_bb_impl::reg_5_shift(unsigned int *sr)
    {
      sr[4] = (sr[4] >> 1) | (sr[3] << 31);
      sr[3] = (sr[3] >> 1) | (sr[2] << 31);
      sr[2] = (sr[2] >> 1) | (sr[1] << 31);
      sr[1] = (sr[1] >> 1) | (sr[0] << 31);
      sr[0] = (sr[0] >> 1);
    }

    /*
     * Shift 192 bits
     */
    inline void
    dvb_bch_bb_impl::reg_6_shift(unsigned int *sr)
    {
      sr[5] = (sr[5] >> 1) | (sr[4] << 31);
      sr[4] = (sr[4] >> 1) | (sr[3] << 31);
      sr[3] = (sr[3] >> 1) | (sr[2] << 31);
      sr[2] = (sr[2] >> 1) | (sr[1] << 31);
      sr[1] = (sr[1] >> 1) | (sr[0] << 31);
      sr[0] = (sr[0] >> 1);
    }

    /*
     * Shift 192 bits by 8 bits
     */
    inline void
    dvb_bch_bb_impl::reg_6_shift_8(unsigned int *sr)
    {
      sr[5] = (sr[5] >> 8) | (sr[4] << 24);
      sr[4] = (sr[4] >> 8) | (sr[3] << 24);
      sr[3] = (sr[3] >> 8) | (sr[2] << 24);
      sr[2] = (sr[2] >> 8) | (sr[1] << 24);
      sr[1] = (sr[1] >> 8) | (sr[0] << 24);
      sr[0] = (sr[0] >> 8);
    }

    int
    dvb_bch_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in_orig = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      unsigned char b, temp;
      unsigned int shift[6];
      int consumed = 0;

      unsigned char *in = new unsigned char[ninput_items[0]*8];
      for (int i = 0; i < ninput_items[0]; i++) {
        for (int j = 0; j < 8; j++) {
          in[8*i+j] = (in_orig[i] >> (7-j)) & 1;
        }
      }

      switch (bch_code) {
        case BCH_CODE_N12:
          for (int i = 0; i < noutput_items; i += nbch) {
            // Copy block from input to output buffer in one operation
            memcpy(out, in, kbch);
            out += kbch;
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 6);
            // http://www.repairfaq.org/filipg/LINK/F_crc_v3.html
            for (int j = 0; j < (int)kbch/8; j++) {
              // Only temporarily, until we switch from bit items to bytes
              unsigned char in_byte = 0;
              for (int i = 0; i < 8; i++) {
                in_byte |= (*in++ & 1) << i;
              }

              b = (in_byte ^ (shift[5] & 0xFF));
              // todo: replace by sse instruction if possible
              reg_6_shift_8(shift);

              shift[0] ^= m_lut_mod8_n_12[6*b + 0];
              shift[1] ^= m_lut_mod8_n_12[6*b + 1];
              shift[2] ^= m_lut_mod8_n_12[6*b + 2];
              shift[3] ^= m_lut_mod8_n_12[6*b + 3];
              shift[4] ^= m_lut_mod8_n_12[6*b + 4];
              shift[5] ^= m_lut_mod8_n_12[6*b + 5];
            }
            consumed += kbch/8;
            // Now add the parity bits to the output
            // todo: update for bytewise data if possible
            for (int n = 0; n < 192; n++) {
              *out++ = (shift[5] & 1);
              reg_6_shift(shift);
            }
          }
          break;
        case BCH_CODE_N10:
          for (int i = 0; i < noutput_items; i += nbch) {
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 5);
            // MSB of the codeword first
            for (int j = 0; j < (int)kbch; j++) {
              temp = *in++;
              *out++ = temp;
              consumed++;
              b = (temp ^ (shift[4] & 1));
              reg_5_shift(shift);
              if (b) {
                shift[0] ^= m_poly_n_10[0];
                shift[1] ^= m_poly_n_10[1];
                shift[2] ^= m_poly_n_10[2];
                shift[3] ^= m_poly_n_10[3];
                shift[4] ^= m_poly_n_10[4];
              }
            }
            // Now add the parity bits to the output
            for( int n = 0; n < 160; n++ ) {
              *out++ = (shift[4] & 1);
              reg_5_shift(shift);
            }
          }
          break;
        case BCH_CODE_N8:
          for (int i = 0; i < noutput_items; i += nbch) {
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 4);
            // MSB of the codeword first
            for (int j = 0; j < (int)kbch; j++) {
              temp = *in++;
              *out++ = temp;
              consumed++;
              b = temp ^ (shift[3] & 1);
              reg_4_shift(shift);
              if (b) {
                shift[0] ^= m_poly_n_8[0];
                shift[1] ^= m_poly_n_8[1];
                shift[2] ^= m_poly_n_8[2];
                shift[3] ^= m_poly_n_8[3];
              }
            }
            // Now add the parity bits to the output
            for (int n = 0; n < 128; n++) {
              *out++ = shift[3] & 1;
              reg_4_shift(shift);
            }
          }
          break;
        case BCH_CODE_S12:
          for (int i = 0; i < noutput_items; i += nbch) {
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 6);
            // MSB of the codeword first
            for (int j = 0; j < (int)kbch; j++) {
              temp = *in++;
              *out++ = temp;
              consumed++;
              b = (temp ^ ((shift[5] & 0x01000000) ? 1 : 0));
              reg_6_shift(shift);
              if (b) {
                shift[0] ^= m_poly_s_12[0];
                shift[1] ^= m_poly_s_12[1];
                shift[2] ^= m_poly_s_12[2];
                shift[3] ^= m_poly_s_12[3];
                shift[4] ^= m_poly_s_12[4];
                shift[5] ^= m_poly_s_12[5];
              }
            }
            // Now add the parity bits to the output
            for (int n = 0; n < 168; n++) {
              *out++ = (shift[5] & 0x01000000) ? 1 : 0;
              reg_6_shift(shift);
            }
          }
          break;
        case BCH_CODE_M12:
          for (int i = 0; i < noutput_items; i += nbch) {
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 6);
            // MSB of the codeword first
            for (int j = 0; j < (int)kbch; j++) {
              temp = *in++;
              *out++ = temp;
              consumed++;
              b = (temp ^ ((shift[5] & 0x00001000) ? 1 : 0));
              reg_6_shift(shift);
              if (b) {
                shift[0] ^= m_poly_m_12[0];
                shift[1] ^= m_poly_m_12[1];
                shift[2] ^= m_poly_m_12[2];
                shift[3] ^= m_poly_m_12[3];
                shift[4] ^= m_poly_m_12[4];
                shift[5] ^= m_poly_m_12[5];
              }
            }
            // Now add the parity bits to the output
            for (int n = 0; n < 180; n++) {
              *out++ = (shift[5] & 0x00001000) ? 1 : 0;
              reg_6_shift(shift);
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

    // The code used to generate the polynomials and lookup table
    /*
    void
    dvb_bch_bb_impl::bch_poly_build_tables(void)
    {
      // Normal polynomials
      const int polyn01[]={1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1};
      const int polyn02[]={1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1};
      const int polyn03[]={1,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1};
      const int polyn04[]={1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1};
      const int polyn05[]={1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,0,1};
      const int polyn06[]={1,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1};
      const int polyn07[]={1,0,1,0,0,1,1,0,1,1,1,1,0,1,0,1,1};
      const int polyn08[]={1,1,1,0,0,1,1,0,1,1,0,0,1,1,1,0,1};
      const int polyn09[]={1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1};
      const int polyn10[]={1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,0,1};
      const int polyn11[]={1,0,1,1,0,1,0,0,0,1,0,1,1,1,0,0,1};
      const int polyn12[]={1,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1};

      // Medium polynomials
      const int polym01[]={1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1};
      const int polym02[]={1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,1};
      const int polym03[]={1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1};
      const int polym04[]={1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1};
      const int polym05[]={1,1,1,0,1,0,1,1,0,0,1,0,1,0,0,1};
      const int polym06[]={1,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1};
      const int polym07[]={1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,1};
      const int polym08[]={1,0,1,0,1,0,1,0,1,1,0,1,0,0,1,1};
      const int polym09[]={1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1};
      const int polym10[]={1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,1};
      const int polym11[]={1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,1};
      const int polym12[]={1,0,1,0,1,0,0,0,1,0,1,1,0,1,1,1};

      // Short polynomials
      const int polys01[]={1,1,0,1,0,1,0,0,0,0,0,0,0,0,1};
      const int polys02[]={1,0,0,0,0,0,1,0,1,0,0,1,0,0,1};
      const int polys03[]={1,1,1,0,0,0,1,0,0,1,1,0,0,0,1};
      const int polys04[]={1,0,0,0,1,0,0,1,1,0,1,0,1,0,1};
      const int polys05[]={1,0,1,0,1,0,1,0,1,1,0,1,0,1,1};
      const int polys06[]={1,0,0,1,0,0,0,1,1,1,0,0,0,1,1};
      const int polys07[]={1,0,1,0,0,1,1,1,0,0,1,1,0,1,1};
      const int polys08[]={1,0,0,0,0,1,0,0,1,1,1,1,0,0,1};
      const int polys09[]={1,1,1,1,0,0,0,0,0,1,1,0,0,0,1};
      const int polys10[]={1,0,0,1,0,0,1,0,0,1,0,1,1,0,1};
      const int polys11[]={1,0,0,0,1,0,0,0,0,0,0,1,1,0,1};
      const int polys12[]={1,1,1,1,0,1,1,1,1,0,1,0,0,1,1};

      int len;
      int polyout[2][200];

      len = poly_mult(polyn01, 17, polyn02,    17,  polyout[0]);
      len = poly_mult(polyn03, 17, polyout[0], len, polyout[1]);
      len = poly_mult(polyn04, 17, polyout[1], len, polyout[0]);
      len = poly_mult(polyn05, 17, polyout[0], len, polyout[1]);
      len = poly_mult(polyn06, 17, polyout[1], len, polyout[0]);
      len = poly_mult(polyn07, 17, polyout[0], len, polyout[1]);
      len = poly_mult(polyn08, 17, polyout[1], len, polyout[0]);
      poly_pack(polyout[0], m_poly_n_8, 128);

      len = poly_mult(polyn09, 17, polyout[0], len, polyout[1]);
      len = poly_mult(polyn10, 17, polyout[1], len, polyout[0]);
      poly_pack(polyout[0], m_poly_n_10, 160);

      len = poly_mult(polyn11, 17, polyout[0], len, polyout[1]);
      len = poly_mult(polyn12, 17, polyout[1], len, polyout[0]);
      unsigned int m_poly_n_12[6];
      poly_pack(polyout[0], m_poly_n_12, 192);

      len = poly_mult(polys01, 15, polys02,    15,  polyout[0]);
      len = poly_mult(polys03, 15, polyout[0], len, polyout[1]);
      len = poly_mult(polys04, 15, polyout[1], len, polyout[0]);
      len = poly_mult(polys05, 15, polyout[0], len, polyout[1]);
      len = poly_mult(polys06, 15, polyout[1], len, polyout[0]);
      len = poly_mult(polys07, 15, polyout[0], len, polyout[1]);
      len = poly_mult(polys08, 15, polyout[1], len, polyout[0]);
      len = poly_mult(polys09, 15, polyout[0], len, polyout[1]);
      len = poly_mult(polys10, 15, polyout[1], len, polyout[0]);
      len = poly_mult(polys11, 15, polyout[0], len, polyout[1]);
      len = poly_mult(polys12, 15, polyout[1], len, polyout[0]);
      poly_pack(polyout[0], m_poly_s_12, 168);

      len = poly_mult(polym01, 16, polym02,    16,  polyout[0]);
      len = poly_mult(polym03, 16, polyout[0], len, polyout[1]);
      len = poly_mult(polym04, 16, polyout[1], len, polyout[0]);
      len = poly_mult(polym05, 16, polyout[0], len, polyout[1]);
      len = poly_mult(polym06, 16, polyout[1], len, polyout[0]);
      len = poly_mult(polym07, 16, polyout[0], len, polyout[1]);
      len = poly_mult(polym08, 16, polyout[1], len, polyout[0]);
      len = poly_mult(polym09, 16, polyout[0], len, polyout[1]);
      len = poly_mult(polym10, 16, polyout[1], len, polyout[0]);
      len = poly_mult(polym11, 16, polyout[0], len, polyout[1]);
      len = poly_mult(polym12, 16, polyout[1], len, polyout[0]);
      poly_pack(polyout[0], m_poly_m_12, 180);

      // Print polys ready for pasting
      printf("const unsigned int dvb_bch_bb_impl::m_poly_n_8[%i] = {\n\t", 4);
      for (int i = 0; i < 4-1; i++) {
        printf("0x%08X, ", m_poly_n_8[i]);
      }
      printf("0x%08X", m_poly_n_8[3]);
      printf("\n};\n\n");

      printf("const unsigned int dvb_bch_bb_impl::m_poly_n_10[%i] = {\n\t", 5);
      for (int i = 0; i < 5-1; i++) {
        printf("0x%08X, ", m_poly_n_10[i]);
      }
      printf("0x%08X", m_poly_n_10[4]);
      printf("\n};\n\n");

      printf("const unsigned int dvb_bch_bb_impl::m_poly_s_12[%i] = {\n\t", 6);
      for (int i = 0; i < 6-1; i++) {
        printf("0x%08X, ", m_poly_s_12[i]);
      }
      printf("0x%08X", m_poly_s_12[5]);
      printf("\n};\n\n");

      printf("const unsigned int dvb_bch_bb_impl::m_poly_m_12[%i] = {\n\t", 6);
      for (int i = 0; i < 6-1; i++) {
        printf("0x%08X, ", m_poly_m_12[i]);
      }
      printf("0x%08X", m_poly_m_12[5]);
      printf("\n};\n\n");

      // Calculate lookup tables for bch encoding
      unsigned int tabval[6];
      unsigned char ctrl_bit;
      for (unsigned int b = 0; b < 256; b++) {
        memset(tabval, 0, sizeof(unsigned int) * 6);
        for (int i = 0; i < 8; i++) {
          ctrl_bit = ((b >> i) & 1) ^ (tabval[5] & 1);
          reg_6_shift(tabval);
          if (ctrl_bit){
            tabval[0] ^= m_poly_n_12[0];
            tabval[1] ^= m_poly_n_12[1];
            tabval[2] ^= m_poly_n_12[2];
            tabval[3] ^= m_poly_n_12[3];
            tabval[4] ^= m_poly_n_12[4];
            tabval[5] ^= m_poly_n_12[5];
          }
        }
        for (int i = 0; i < 6; i++) {
          m_lut_mod8_n_12[6*b + i] = tabval[i];
        }
      }
      // Print LUT ready for pasting
      printf("const unsigned int dvb_bch_bb_impl::m_lut_mod8_n_12[%i] = {\n", 256*6);
      for (int i = 0; i < 6*256; i+=6) {
        printf("\t");
        for (int j = 0; j < 6-1; j++) {
          printf("0x%08X, ", m_lut_mod8_n_12[i+j]);
        }
        printf("0x%08X", m_lut_mod8_n_12[i+5]);
        if (i+6 != 6*256) {
          printf(",");
        }
        printf("\n");
      }
      printf("};\n\n");
    }
    */

    const unsigned int dvb_bch_bb_impl::m_poly_n_8[4] = {
    	0xD4669F20, 0xAEB63F98, 0xBDE9E48E, 0xFAA4E038
    };

    const unsigned int dvb_bch_bb_impl::m_poly_n_10[5] = {
    	0x89A6DD1D, 0x80C48BF7, 0xC0EA1E56, 0xF8CC543F, 0xB730A806
    };

    const unsigned int dvb_bch_bb_impl::m_poly_s_12[6] = {
    	0xA5A0988B, 0xEBE7F14A, 0x9609C5C4, 0xB3464D96, 0x1957DB46, 0x02B06472
    };

    const unsigned int dvb_bch_bb_impl::m_poly_m_12[6] = {
    	0xD0821BC3, 0xF42EAC6A, 0xCCA1056F, 0xD9C04190, 0xB1800DBE, 0xDD215872
    };

    const unsigned int dvb_bch_bb_impl::m_lut_mod8_n_12[1536] = {
    	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    	0xC4479EF0, 0x731FEAFB, 0x22DC368B, 0x10709FD7, 0xB40CB648, 0xC48B120B,
    	0x47DBBD2D, 0x397C1077, 0x67993560, 0x1688D9BB, 0x190D18D2, 0x0BF6ECF3,
    	0x839C23DD, 0x4A63FA8C, 0x454503EB, 0x06F8466C, 0xAD01AE9A, 0xCF7DFEF8,
    	0x8FB77A5A, 0x72F820EE, 0xCF326AC0, 0x2D11B376, 0x321A31A4, 0x17EDD9E6,
    	0x4BF0E4AA, 0x01E7CA15, 0xEDEE5C4B, 0x3D612CA1, 0x861687EC, 0xD366CBED,
    	0xC86CC777, 0x4B843099, 0xA8AB5FA0, 0x3B996ACD, 0x2B172976, 0x1C1B3515,
    	0x0C2B5987, 0x389BDA62, 0x8A77692B, 0x2BE9F51A, 0x9F1B9F3E, 0xD890271E,
    	0xD03A7479, 0x3AB3845C, 0xBC458DF6, 0x6C4A80F8, 0x1520170B, 0xAD3B7B29,
    	0x147DEA89, 0x49AC6EA7, 0x9E99BB7D, 0x7C3A1F2F, 0xA12CA143, 0x69B06922,
    	0x97E1C954, 0x03CF942B, 0xDBDCB896, 0x7AC25943, 0x0C2D0FD9, 0xA6CD97DA,
    	0x53A657A4, 0x70D07ED0, 0xF9008E1D, 0x6AB2C694, 0xB821B991, 0x624685D1,
    	0x5F8D0E23, 0x484BA4B2, 0x7377E736, 0x415B338E, 0x273A26AF, 0xBAD6A2CF,
    	0x9BCA90D3, 0x3B544E49, 0x51ABD1BD, 0x512BAC59, 0x933690E7, 0x7E5DB0C4,
    	0x1856B30E, 0x7137B4C5, 0x14EED256, 0x57D3EA35, 0x3E373E7D, 0xB1204E3C,
    	0xDC112DFE, 0x02285E3E, 0x3632E4DD, 0x47A375E2, 0x8A3B8835, 0x75AB5C37,
    	0x6F20683F, 0xAA24CD38, 0x5AAA439A, 0xEEFCE7E4, 0x5B545A54, 0xD8963EB7,
    	0xAB67F6CF, 0xD93B27C3, 0x78767511, 0xFE8C7833, 0xEF58EC1C, 0x1C1D2CBC,
    	0x28FBD512, 0x9358DD4F, 0x3D3376FA, 0xF8743E5F, 0x42594286, 0xD360D244,
    	0xECBC4BE2, 0xE04737B4, 0x1FEF4071, 0xE804A188, 0xF655F4CE, 0x17EBC04F,
    	0xE0971265, 0xD8DCEDD6, 0x9598295A, 0xC3ED5492, 0x694E6BF0, 0xCF7BE751,
    	0x24D08C95, 0xABC3072D, 0xB7441FD1, 0xD39DCB45, 0xDD42DDB8, 0x0BF0F55A,
    	0xA74CAF48, 0xE1A0FDA1, 0xF2011C3A, 0xD5658D29, 0x70437322, 0xC48D0BA2,
    	0x630B31B8, 0x92BF175A, 0xD0DD2AB1, 0xC51512FE, 0xC44FC56A, 0x000619A9,
    	0xBF1A1C46, 0x90974964, 0xE6EFCE6C, 0x82B6671C, 0x4E744D5F, 0x75AD459E,
    	0x7B5D82B6, 0xE388A39F, 0xC433F8E7, 0x92C6F8CB, 0xFA78FB17, 0xB1265795,
    	0xF8C1A16B, 0xA9EB5913, 0x8176FB0C, 0x943EBEA7, 0x5779558D, 0x7E5BA96D,
    	0x3C863F9B, 0xDAF4B3E8, 0xA3AACD87, 0x844E2170, 0xE375E3C5, 0xBAD0BB66,
    	0x30AD661C, 0xE26F698A, 0x29DDA4AC, 0xAFA7D46A, 0x7C6E7CFB, 0x62409C78,
    	0xF4EAF8EC, 0x91708371, 0x0B019227, 0xBFD74BBD, 0xC862CAB3, 0xA6CB8E73,
    	0x7776DB31, 0xDB1379FD, 0x4E4491CC, 0xB92F0DD1, 0x65636429, 0x69B6708B,
    	0xB33145C1, 0xA80C9306, 0x6C98A747, 0xA95F9206, 0xD16FD261, 0xAD3D6280,
    	0xDE40D07F, 0x54499A70, 0xB5548735, 0xDDF9CFC8, 0xB6A8B4A9, 0xB12C7D6E,
    	0x1A074E8F, 0x2756708B, 0x9788B1BE, 0xCD89501F, 0x02A402E1, 0x75A76F65,
    	0x999B6D52, 0x6D358A07, 0xD2CDB255, 0xCB711673, 0xAFA5AC7B, 0xBADA919D,
    	0x5DDCF3A2, 0x1E2A60FC, 0xF01184DE, 0xDB0189A4, 0x1BA91A33, 0x7E518396,
    	0x51F7AA25, 0x26B1BA9E, 0x7A66EDF5, 0xF0E87CBE, 0x84B2850D, 0xA6C1A488,
    	0x95B034D5, 0x55AE5065, 0x58BADB7E, 0xE098E369, 0x30BE3345, 0x624AB683,
    	0x162C1708, 0x1FCDAAE9, 0x1DFFD895, 0xE660A505, 0x9DBF9DDF, 0xAD37487B,
    	0xD26B89F8, 0x6CD24012, 0x3F23EE1E, 0xF6103AD2, 0x29B32B97, 0x69BC5A70,
    	0x0E7AA406, 0x6EFA1E2C, 0x09110AC3, 0xB1B34F30, 0xA388A3A2, 0x1C170647,
    	0xCA3D3AF6, 0x1DE5F4D7, 0x2BCD3C48, 0xA1C3D0E7, 0x178415EA, 0xD89C144C,
    	0x49A1192B, 0x57860E5B, 0x6E883FA3, 0xA73B968B, 0xBA85BB70, 0x17E1EAB4,
    	0x8DE687DB, 0x2499E4A0, 0x4C540928, 0xB74B095C, 0x0E890D38, 0xD36AF8BF,
    	0x81CDDE5C, 0x1C023EC2, 0xC6236003, 0x9CA2FC46, 0x91929206, 0x0BFADFA1,
    	0x458A40AC, 0x6F1DD439, 0xE4FF5688, 0x8CD26391, 0x259E244E, 0xCF71CDAA,
    	0xC6166371, 0x257E2EB5, 0xA1BA5563, 0x8A2A25FD, 0x889F8AD4, 0x000C3352,
    	0x0251FD81, 0x5661C44E, 0x836663E8, 0x9A5ABA2A, 0x3C933C9C, 0xC4872159,
    	0xB160B840, 0xFE6D5748, 0xEFFEC4AF, 0x3305282C, 0xEDFCEEFD, 0x69BA43D9,
    	0x752726B0, 0x8D72BDB3, 0xCD22F224, 0x2375B7FB, 0x59F058B5, 0xAD3151D2,
    	0xF6BB056D, 0xC711473F, 0x8867F1CF, 0x258DF197, 0xF4F1F62F, 0x624CAF2A,
    	0x32FC9B9D, 0xB40EADC4, 0xAABBC744, 0x35FD6E40, 0x40FD4067, 0xA6C7BD21,
    	0x3ED7C21A, 0x8C9577A6, 0x20CCAE6F, 0x1E149B5A, 0xDFE6DF59, 0x7E579A3F,
    	0xFA905CEA, 0xFF8A9D5D, 0x021098E4, 0x0E64048D, 0x6BEA6911, 0xBADC8834,
    	0x790C7F37, 0xB5E967D1, 0x47559B0F, 0x089C42E1, 0xC6EBC78B, 0x75A176CC,
    	0xBD4BE1C7, 0xC6F68D2A, 0x6589AD84, 0x18ECDD36, 0x72E771C3, 0xB12A64C7,
    	0x615ACC39, 0xC4DED314, 0x53BB4959, 0x5F4FA8D4, 0xF8DCF9F6, 0xC48138F0,
    	0xA51D52C9, 0xB7C139EF, 0x71677FD2, 0x4F3F3703, 0x4CD04FBE, 0x000A2AFB,
    	0x26817114, 0xFDA2C363, 0x34227C39, 0x49C7716F, 0xE1D1E124, 0xCF77D403,
    	0xE2C6EFE4, 0x8EBD2998, 0x16FE4AB2, 0x59B7EEB8, 0x55DD576C, 0x0BFCC608,
    	0xEEEDB663, 0xB626F3FA, 0x9C892399, 0x725E1BA2, 0xCAC6C852, 0xD36CE116,
    	0x2AAA2893, 0xC5391901, 0xBE551512, 0x622E8475, 0x7ECA7E1A, 0x17E7F31D,
    	0xA9360B4E, 0x8F5AE38D, 0xFB1016F9, 0x64D6C219, 0xD3CBD080, 0xD89A0DE5,
    	0x6D7195BE, 0xFC450976, 0xD9CC2072, 0x74A65DCE, 0x67C766C8, 0x1C111FEE,
    	0x73D52033, 0x77D0F160, 0x4888561D, 0x8D9A7985, 0x1C451D10, 0xE0B83239,
    	0xB792BEC3, 0x04CF1B9B, 0x6A546096, 0x9DEAE652, 0xA849AB58, 0x24332032,
    	0x340E9D1E, 0x4EACE117, 0x2F11637D, 0x9B12A03E, 0x054805C2, 0xEB4EDECA,
    	0xF04903EE, 0x3DB30BEC, 0x0DCD55F6, 0x8B623FE9, 0xB144B38A, 0x2FC5CCC1,
    	0xFC625A69, 0x0528D18E, 0x87BA3CDD, 0xA08BCAF3, 0x2E5F2CB4, 0xF755EBDF,
    	0x3825C499, 0x76373B75, 0xA5660A56, 0xB0FB5524, 0x9A539AFC, 0x33DEF9D4,
    	0xBBB9E744, 0x3C54C1F9, 0xE02309BD, 0xB6031348, 0x37523466, 0xFCA3072C,
    	0x7FFE79B4, 0x4F4B2B02, 0xC2FF3F36, 0xA6738C9F, 0x835E822E, 0x38281527,
    	0xA3EF544A, 0x4D63753C, 0xF4CDDBEB, 0xE1D0F97D, 0x09650A1B, 0x4D834910,
    	0x67A8CABA, 0x3E7C9FC7, 0xD611ED60, 0xF1A066AA, 0xBD69BC53, 0x89085B1B,
    	0xE434E967, 0x741F654B, 0x9354EE8B, 0xF75820C6, 0x106812C9, 0x4675A5E3,
    	0x20737797, 0x07008FB0, 0xB188D800, 0xE728BF11, 0xA464A481, 0x82FEB7E8,
    	0x2C582E10, 0x3F9B55D2, 0x3BFFB12B, 0xCCC14A0B, 0x3B7F3BBF, 0x5A6E90F6,
    	0xE81FB0E0, 0x4C84BF29, 0x192387A0, 0xDCB1D5DC, 0x8F738DF7, 0x9EE582FD,
    	0x6B83933D, 0x06E745A5, 0x5C66844B, 0xDA4993B0, 0x2272236D, 0x51987C05,
    	0xAFC40DCD, 0x75F8AF5E, 0x7EBAB2C0, 0xCA390C67, 0x967E9525, 0x95136E0E,
    	0x1CF5480C, 0xDDF43C58, 0x12221587, 0x63669E61, 0x47114744, 0x382E0C8E,
    	0xD8B2D6FC, 0xAEEBD6A3, 0x30FE230C, 0x731601B6, 0xF31DF10C, 0xFCA51E85,
    	0x5B2EF521, 0xE4882C2F, 0x75BB20E7, 0x75EE47DA, 0x5E1C5F96, 0x33D8E07D,
    	0x9F696BD1, 0x9797C6D4, 0x5767166C, 0x659ED80D, 0xEA10E9DE, 0xF753F276,
    	0x93423256, 0xAF0C1CB6, 0xDD107F47, 0x4E772D17, 0x750B76E0, 0x2FC3D568,
    	0x5705ACA6, 0xDC13F64D, 0xFFCC49CC, 0x5E07B2C0, 0xC107C0A8, 0xEB48C763,
    	0xD4998F7B, 0x96700CC1, 0xBA894A27, 0x58FFF4AC, 0x6C066E32, 0x2435399B,
    	0x10DE118B, 0xE56FE63A, 0x98557CAC, 0x488F6B7B, 0xD80AD87A, 0xE0BE2B90,
    	0xCCCF3C75, 0xE747B804, 0xAE679871, 0x0F2C1E99, 0x5231504F, 0x951577A7,
    	0x0888A285, 0x945852FF, 0x8CBBAEFA, 0x1F5C814E, 0xE63DE607, 0x519E65AC,
    	0x8B148158, 0xDE3BA873, 0xC9FEAD11, 0x19A4C722, 0x4B3C489D, 0x9EE39B54,
    	0x4F531FA8, 0xAD244288, 0xEB229B9A, 0x09D458F5, 0xFF30FED5, 0x5A68895F,
    	0x4378462F, 0x95BF98EA, 0x6155F2B1, 0x223DADEF, 0x602B61EB, 0x82F8AE41,
    	0x873FD8DF, 0xE6A07211, 0x4389C43A, 0x324D3238, 0xD427D7A3, 0x4673BC4A,
    	0x04A3FB02, 0xACC3889D, 0x06CCC7D1, 0x34B57454, 0x79267939, 0x890E42B2,
    	0xC0E465F2, 0xDFDC6266, 0x2410F15A, 0x24C5EB83, 0xCD2ACF71, 0x4D8550B9,
    	0xAD95F04C, 0x23996B10, 0xFDDCD128, 0x5063B64D, 0xAAEDA9B9, 0x51944F57,
    	0x69D26EBC, 0x508681EB, 0xDF00E7A3, 0x4013299A, 0x1EE11FF1, 0x951F5D5C,
    	0xEA4E4D61, 0x1AE57B67, 0x9A45E448, 0x46EB6FF6, 0xB3E0B16B, 0x5A62A3A4,
    	0x2E09D391, 0x69FA919C, 0xB899D2C3, 0x569BF021, 0x07EC0723, 0x9EE9B1AF,
    	0x22228A16, 0x51614BFE, 0x32EEBBE8, 0x7D72053B, 0x98F7981D, 0x467996B1,
    	0xE66514E6, 0x227EA105, 0x10328D63, 0x6D029AEC, 0x2CFB2E55, 0x82F284BA,
    	0x65F9373B, 0x681D5B89, 0x55778E88, 0x6BFADC80, 0x81FA80CF, 0x4D8F7A42,
    	0xA1BEA9CB, 0x1B02B172, 0x77ABB803, 0x7B8A4357, 0x35F63687, 0x89046849,
    	0x7DAF8435, 0x192AEF4C, 0x41995CDE, 0x3C2936B5, 0xBFCDBEB2, 0xFCAF347E,
    	0xB9E81AC5, 0x6A3505B7, 0x63456A55, 0x2C59A962, 0x0BC108FA, 0x38242675,
    	0x3A743918, 0x2056FF3B, 0x260069BE, 0x2AA1EF0E, 0xA6C0A660, 0xF759D88D,
    	0xFE33A7E8, 0x534915C0, 0x04DC5F35, 0x3AD170D9, 0x12CC1028, 0x33D2CA86,
    	0xF218FE6F, 0x6BD2CFA2, 0x8EAB361E, 0x113885C3, 0x8DD78F16, 0xEB42ED98,
    	0x365F609F, 0x18CD2559, 0xAC770095, 0x01481A14, 0x39DB395E, 0x2FC9FF93,
    	0xB5C34342, 0x52AEDFD5, 0xE932037E, 0x07B05C78, 0x94DA97C4, 0xE0B4016B,
    	0x7184DDB2, 0x21B1352E, 0xCBEE35F5, 0x17C0C3AF, 0x20D6218C, 0x243F1360,
    	0xC2B59873, 0x89BDA628, 0xA77692B2, 0xBE9F51A9, 0xF1B9F3ED, 0x890271E0,
    	0x06F20683, 0xFAA24CD3, 0x85AAA439, 0xAEEFCE7E, 0x45B545A5, 0x4D8963EB,
    	0x856E255E, 0xB0C1B65F, 0xC0EFA7D2, 0xA8178812, 0xE8B4EB3F, 0x82F49D13,
    	0x4129BBAE, 0xC3DE5CA4, 0xE2339159, 0xB86717C5, 0x5CB85D77, 0x467F8F18,
    	0x4D02E229, 0xFB4586C6, 0x6844F872, 0x938EE2DF, 0xC3A3C249, 0x9EEFA806,
    	0x89457CD9, 0x885A6C3D, 0x4A98CEF9, 0x83FE7D08, 0x77AF7401, 0x5A64BA0D,
    	0x0AD95F04, 0xC23996B1, 0x0FDDCD12, 0x85063B64, 0xDAAEDA9B, 0x951944F5,
    	0xCE9EC1F4, 0xB1267C4A, 0x2D01FB99, 0x9576A4B3, 0x6EA26CD3, 0x519256FE,
    	0x128FEC0A, 0xB30E2274, 0x1B331F44, 0xD2D5D151, 0xE499E4E6, 0x24390AC9,
    	0xD6C872FA, 0xC011C88F, 0x39EF29CF, 0xC2A54E86, 0x509552AE, 0xE0B218C2,
    	0x55545127, 0x8A723203, 0x7CAA2A24, 0xC45D08EA, 0xFD94FC34, 0x2FCFE63A,
    	0x9113CFD7, 0xF96DD8F8, 0x5E761CAF, 0xD42D973D, 0x49984A7C, 0xEB44F431,
    	0x9D389650, 0xC1F6029A, 0xD4017584, 0xFFC46227, 0xD683D542, 0x33D4D32F,
    	0x597F08A0, 0xB2E9E861, 0xF6DD430F, 0xEFB4FDF0, 0x628F630A, 0xF75FC124,
    	0xDAE32B7D, 0xF88A12ED, 0xB39840E4, 0xE94CBB9C, 0xCF8ECD90, 0x38223FDC,
    	0x1EA4B58D, 0x8B95F816, 0x9144766F, 0xF93C244B, 0x7B827BD8, 0xFCA92DD7,
    	0xE7AA4066, 0xEFA1E2C0, 0x9110AC3B, 0x1B34F30A, 0x388A3A21, 0xC1706472,
    	0x23EDDE96, 0x9CBE083B, 0xB3CC9AB0, 0x0B446CDD, 0x8C868C69, 0x05FB7679,
    	0xA071FD4B, 0xD6DDF2B7, 0xF689995B, 0x0DBC2AB1, 0x218722F3, 0xCA868881,
    	0x643663BB, 0xA5C2184C, 0xD455AFD0, 0x1DCCB566, 0x958B94BB, 0x0E0D9A8A,
    	0x681D3A3C, 0x9D59C22E, 0x5E22C6FB, 0x3625407C, 0x0A900B85, 0xD69DBD94,
    	0xAC5AA4CC, 0xEE4628D5, 0x7CFEF070, 0x2655DFAB, 0xBE9CBDCD, 0x1216AF9F,
    	0x2FC68711, 0xA425D259, 0x39BBF39B, 0x20AD99C7, 0x139D1357, 0xDD6B5167,
    	0xEB8119E1, 0xD73A38A2, 0x1B67C510, 0x30DD0610, 0xA791A51F, 0x19E0436C,
    	0x3790341F, 0xD512669C, 0x2D5521CD, 0x777E73F2, 0x2DAA2D2A, 0x6C4B1F5B,
    	0xF3D7AAEF, 0xA60D8C67, 0x0F891746, 0x670EEC25, 0x99A69B62, 0xA8C00D50,
    	0x704B8932, 0xEC6E76EB, 0x4ACC14AD, 0x61F6AA49, 0x34A735F8, 0x67BDF3A8,
    	0xB40C17C2, 0x9F719C10, 0x68102226, 0x7186359E, 0x80AB83B0, 0xA336E1A3,
    	0xB8274E45, 0xA7EA4672, 0xE2674B0D, 0x5A6FC084, 0x1FB01C8E, 0x7BA6C6BD,
    	0x7C60D0B5, 0xD4F5AC89, 0xC0BB7D86, 0x4A1F5F53, 0xABBCAAC6, 0xBF2DD4B6,
    	0xFFFCF368, 0x9E965605, 0x85FE7E6D, 0x4CE7193F, 0x06BD045C, 0x70502A4E,
    	0x3BBB6D98, 0xED89BCFE, 0xA72248E6, 0x5C9786E8, 0xB2B1B214, 0xB4DB3845,
    	0x888A2859, 0x45852FF8, 0xCBBAEFA1, 0xF5C814EE, 0x63DE6075, 0x19E65AC5,
    	0x4CCDB6A9, 0x369AC503, 0xE966D92A, 0xE5B88B39, 0xD7D2D63D, 0xDD6D48CE,
    	0xCF519574, 0x7CF93F8F, 0xAC23DAC1, 0xE340CD55, 0x7AD378A7, 0x1210B636,
    	0x0B160B84, 0x0FE6D574, 0x8EFFEC4A, 0xF3305282, 0xCEDFCEEF, 0xD69BA43D,
    	0x073D5203, 0x377D0F16, 0x04888561, 0xD8D9A798, 0x51C451D1, 0x0E0B8323,
    	0xC37ACCF3, 0x4462E5ED, 0x2654B3EA, 0xC8A9384F, 0xE5C8E799, 0xCA809128,
    	0x40E6EF2E, 0x0E011F61, 0x6311B001, 0xCE517E23, 0x48C94903, 0x05FD6FD0,
    	0x84A171DE, 0x7D1EF59A, 0x41CD868A, 0xDE21E1F4, 0xFCC5FF4B, 0xC1767DDB,
    	0x58B05C20, 0x7F36ABA4, 0x77FF6257, 0x99829416, 0x76FE777E, 0xB4DD21EC,
    	0x9CF7C2D0, 0x0C29415F, 0x552354DC, 0x89F20BC1, 0xC2F2C136, 0x705633E7,
    	0x1F6BE10D, 0x464ABBD3, 0x10665737, 0x8F0A4DAD, 0x6FF36FAC, 0xBF2BCD1F,
    	0xDB2C7FFD, 0x35555128, 0x32BA61BC, 0x9F7AD27A, 0xDBFFD9E4, 0x7BA0DF14,
    	0xD707267A, 0x0DCE8B4A, 0xB8CD0897, 0xB4932760, 0x44E446DA, 0xA330F80A,
    	0x1340B88A, 0x7ED161B1, 0x9A113E1C, 0xA4E3B8B7, 0xF0E8F092, 0x67BBEA01,
    	0x90DC9B57, 0x34B29B3D, 0xDF543DF7, 0xA21BFEDB, 0x5DE95E08, 0xA8C614F9,
    	0x549B05A7, 0x47AD71C6, 0xFD880B7C, 0xB26B610C, 0xE9E5E840, 0x6C4D06F2,
    	0x39EA9019, 0xBBE878B0, 0x24442B0E, 0xC6CD3CC2, 0x8E228E88, 0x705C191C,
    	0xFDAD0EE9, 0xC8F7924B, 0x06981D85, 0xD6BDA315, 0x3A2E38C0, 0xB4D70B17,
    	0x7E312D34, 0x829468C7, 0x43DD1E6E, 0xD045E579, 0x972F965A, 0x7BAAF5EF,
    	0xBA76B3C4, 0xF18B823C, 0x610128E5, 0xC0357AAE, 0x23232012, 0xBF21E7E4,
    	0xB65DEA43, 0xC910585E, 0xEB7641CE, 0xEBDC8FB4, 0xBC38BF2C, 0x67B1C0FA,
    	0x721A74B3, 0xBA0FB2A5, 0xC9AA7745, 0xFBAC1063, 0x08340964, 0xA33AD2F1,
    	0xF186576E, 0xF06C4829, 0x8CEF74AE, 0xFD54560F, 0xA535A7FE, 0x6C472C09,
    	0x35C1C99E, 0x8373A2D2, 0xAE334225, 0xED24C9D8, 0x113911B6, 0xA8CC3E02,
    	0xE9D0E460, 0x815BFCEC, 0x9801A6F8, 0xAA87BC3A, 0x9B029983, 0xDD676235,
    	0x2D977A90, 0xF2441617, 0xBADD9073, 0xBAF723ED, 0x2F0E2FCB, 0x19EC703E,
    	0xAE0B594D, 0xB827EC9B, 0xFF989398, 0xBC0F6581, 0x820F8151, 0xD6918EC6,
    	0x6A4CC7BD, 0xCB380660, 0xDD44A513, 0xAC7FFA56, 0x36033719, 0x121A9CCD,
    	0x66679E3A, 0xF3A3DC02, 0x5733CC38, 0x87960F4C, 0xA918A827, 0xCA8ABBD3,
    	0xA22000CA, 0x80BC36F9, 0x75EFFAB3, 0x97E6909B, 0x1D141E6F, 0x0E01A9D8,
    	0x21BC2317, 0xCADFCC75, 0x30AAF958, 0x911ED6F7, 0xB015B0F5, 0xC17C5720,
    	0xE5FBBDE7, 0xB9C0268E, 0x1276CFD3, 0x816E4920, 0x041906BD, 0x05F7452B,
    	0x56CAF826, 0x11CCB588, 0x7EEE6894, 0x2831DB26, 0xD576D4DC, 0xA8CA27AB,
    	0x928D66D6, 0x62D35F73, 0x5C325E1F, 0x384144F1, 0x617A6294, 0x6C4135A0,
    	0x1111450B, 0x28B0A5FF, 0x19775DF4, 0x3EB9029D, 0xCC7BCC0E, 0xA33CCB58,
    	0xD556DBFB, 0x5BAF4F04, 0x3BAB6B7F, 0x2EC99D4A, 0x78777A46, 0x67B7D953,
    	0xD97D827C, 0x63349566, 0xB1DC0254, 0x05206850, 0xE76CE578, 0xBF27FE4D,
    	0x1D3A1C8C, 0x102B7F9D, 0x930034DF, 0x1550F787, 0x53605330, 0x7BACEC46,
    	0x9EA63F51, 0x5A488511, 0xD6453734, 0x13A8B1EB, 0xFE61FDAA, 0xB4D112BE,
    	0x5AE1A1A1, 0x29576FEA, 0xF49901BF, 0x03D82E3C, 0x4A6D4BE2, 0x705A00B5,
    	0x86F08C5F, 0x2B7F31D4, 0xC2ABE562, 0x447B5BDE, 0xC056C3D7, 0x05F15C82,
    	0x42B712AF, 0x5860DB2F, 0xE077D3E9, 0x540BC409, 0x745A759F, 0xC17A4E89,
    	0xC12B3172, 0x120321A3, 0xA532D002, 0x52F38265, 0xD95BDB05, 0x0E07B071,
    	0x056CAF82, 0x611CCB58, 0x87EEE689, 0x42831DB2, 0x6D576D4D, 0xCA8CA27A,
    	0x0947F605, 0x5987113A, 0x0D998FA2, 0x696AE8A8, 0xF24CF273, 0x121C8564,
    	0xCD0068F5, 0x2A98FBC1, 0x2F45B929, 0x791A777F, 0x4640443B, 0xD697976F,
    	0x4E9C4B28, 0x60FB014D, 0x6A00BAC2, 0x7FE23113, 0xEB41EAA1, 0x19EA6997,
    	0x8ADBD5D8, 0x13E4EBB6, 0x48DC8C49, 0x6F92AEC4, 0x5F4D5CE9, 0xDD617B9C,
    	0x947F6055, 0x987113A0, 0xD998FA26, 0x96AE8A8F, 0x24CF2731, 0x21C8564B,
    	0x5038FEA5, 0xEB6EF95B, 0xFB44CCAD, 0x86DE1558, 0x90C39179, 0xE5434440,
    	0xD3A4DD78, 0xA10D03D7, 0xBE01CF46, 0x80265334, 0x3DC23FE3, 0x2A3EBAB8,
    	0x17E34388, 0xD212E92C, 0x9CDDF9CD, 0x9056CCE3, 0x89CE89AB, 0xEEB5A8B3,
    	0x1BC81A0F, 0xEA89334E, 0x16AA90E6, 0xBBBF39F9, 0x16D51695, 0x36258FAD,
    	0xDF8F84FF, 0x9996D9B5, 0x3476A66D, 0xABCFA62E, 0xA2D9A0DD, 0xF2AE9DA6,
    	0x5C13A722, 0xD3F52339, 0x7133A586, 0xAD37E042, 0x0FD80E47, 0x3DD3635E,
    	0x985439D2, 0xA0EAC9C2, 0x53EF930D, 0xBD477F95, 0xBBD4B80F, 0xF9587155,
    	0x4445142C, 0xA2C297FC, 0x65DD77D0, 0xFAE40A77, 0x31EF303A, 0x8CF32D62,
    	0x80028ADC, 0xD1DD7D07, 0x4701415B, 0xEA9495A0, 0x85E38672, 0x48783F69,
    	0x039EA901, 0x9BBE878B, 0x024442B0, 0xEC6CD3CC, 0x28E228E8, 0x8705C191,
    	0xC7D937F1, 0xE8A16D70, 0x2098743B, 0xFC1C4C1B, 0x9CEE9EA0, 0x438ED39A,
    	0xCBF26E76, 0xD03AB712, 0xAAEF1D10, 0xD7F5B901, 0x03F5019E, 0x9B1EF484,
    	0x0FB5F086, 0xA3255DE9, 0x88332B9B, 0xC78526D6, 0xB7F9B7D6, 0x5F95E68F,
    	0x8C29D35B, 0xE946A765, 0xCD762870, 0xC17D60BA, 0x1AF8194C, 0x90E81877,
    	0x486E4DAB, 0x9A594D9E, 0xEFAA1EFB, 0xD10DFF6D, 0xAEF4AF04, 0x54630A7C,
    	0xFB5F086A, 0x3255DE98, 0x8332B9BC, 0x78526D6B, 0x7F9B7D65, 0xF95E68FC,
    	0x3F18969A, 0x414A3463, 0xA1EE8F37, 0x6822F2BC, 0xCB97CB2D, 0x3DD57AF7,
    	0xBC84B547, 0x0B29CEEF, 0xE4AB8CDC, 0x6EDAB4D0, 0x669665B7, 0xF2A8840F,
    	0x78C32BB7, 0x78362414, 0xC677BA57, 0x7EAA2B07, 0xD29AD3FF, 0x36239604,
    	0x74E87230, 0x40ADFE76, 0x4C00D37C, 0x5543DE1D, 0x4D814CC1, 0xEEB3B11A,
    	0xB0AFECC0, 0x33B2148D, 0x6EDCE5F7, 0x453341CA, 0xF98DFA89, 0x2A38A311,
    	0x3333CF1D, 0x79D1EE01, 0x2B99E61C, 0x43CB07A6, 0x548C5413, 0xE5455DE9,
    	0xF77451ED, 0x0ACE04FA, 0x0945D097, 0x53BB9871, 0xE080E25B, 0x21CE4FE2,
    	0x2B657C13, 0x08E65AC4, 0x3F77344A, 0x1418ED93, 0x6ABB6A6E, 0x546513D5,
    	0xEF22E2E3, 0x7BF9B03F, 0x1DAB02C1, 0x04687244, 0xDEB7DC26, 0x90EE01DE,
    	0x6CBEC13E, 0x319A4AB3, 0x58EE012A, 0x02903428, 0x73B672BC, 0x5F93FF26,
    	0xA8F95FCE, 0x4285A048, 0x7A3237A1, 0x12E0ABFF, 0xC7BAC4F4, 0x9B18ED2D,
    	0xA4D20649, 0x7A1E7A2A, 0xF0455E8A, 0x39095EE5, 0x58A15BCA, 0x4388CA33,
    	0x609598B9, 0x090190D1, 0xD2996801, 0x2979C132, 0xECADED82, 0x8703D838,
    	0xE309BB64, 0x43626A5D, 0x97DC6BEA, 0x2F81875E, 0x41AC4318, 0x487E26C0,
    	0x274E2594, 0x307D80A6, 0xB5005D61, 0x3FF11889, 0xF5A0F550, 0x8CF534CB,
    	0x4A3FB02A, 0xCC3889D0, 0x6CCC7D13, 0x4B574547, 0x92679398, 0x90E42B25,
    	0x8E782EDA, 0xBF27632B, 0x4E104B98, 0x5B27DA90, 0x266B25D0, 0x546F392E,
    	0x0DE40D07, 0xF54499A7, 0x0B554873, 0x5DDF9CFC, 0x8B6A8B4A, 0x9B12C7D6,
    	0xC9A393F7, 0x865B735C, 0x29897EF8, 0x4DAF032B, 0x3F663D02, 0x5F99D5DD,
    	0xC588CA70, 0xBEC0A93E, 0xA3FE17D3, 0x6646F631, 0xA07DA23C, 0x8709F2C3,
    	0x01CF5480, 0xCDDF43C5, 0x81222158, 0x763669E6, 0x14711474, 0x4382E0C8,
    	0x8253775D, 0x87BCB949, 0xC46722B3, 0x70CE2F8A, 0xB970BAEE, 0x8CFF1E30,
    	0x4614E9AD, 0xF4A353B2, 0xE6BB1438, 0x60BEB05D, 0x0D7C0CA6, 0x48740C3B,
    	0x9A05C453, 0xF68B0D8C, 0xD089F0E5, 0x271DC5BF, 0x87478493, 0x3DDF500C,
    	0x5E425AA3, 0x8594E777, 0xF255C66E, 0x376D5A68, 0x334B32DB, 0xF9544207,
    	0xDDDE797E, 0xCFF71DFB, 0xB710C585, 0x31951C04, 0x9E4A9C41, 0x3629BCFF,
    	0x1999E78E, 0xBCE8F700, 0x95CCF30E, 0x21E583D3, 0x2A462A09, 0xF2A2AEF4,
    	0x15B2BE09, 0x84732D62, 0x1FBB9A25, 0x0A0C76C9, 0xB55DB537, 0x2A3289EA,
    	0xD1F520F9, 0xF76CC799, 0x3D67ACAE, 0x1A7CE91E, 0x0151037F, 0xEEB99BE1,
    	0x52690324, 0xBD0F3D15, 0x7822AF45, 0x1C84AF72, 0xAC50ADE5, 0x21C46519,
    	0x962E9DD4, 0xCE10D7EE, 0x5AFE99CE, 0x0CF430A5, 0x185C1BAD, 0xE54F7712,
    	0x251FD815, 0x661C44E8, 0x36663E89, 0xA5ABA2A3, 0xC933C9CC, 0x48721592,
    	0xE15846E5, 0x1503AE13, 0x14BA0802, 0xB5DB3D74, 0x7D3F7F84, 0x8CF90799,
    	0x62C46538, 0x5F60549F, 0x51FF0BE9, 0xB3237B18, 0xD03ED11E, 0x4384F961,
    	0xA683FBC8, 0x2C7FBE64, 0x73233D62, 0xA353E4CF, 0x64326756, 0x870FEB6A,
    	0xAAA8A24F, 0x14E46406, 0xF9545449, 0x88BA11D5, 0xFB29F868, 0x5F9FCC74,
    	0x6EEF3CBF, 0x67FB8EFD, 0xDB8862C2, 0x98CA8E02, 0x4F254E20, 0x9B14DE7F,
    	0xED731F62, 0x2D987471, 0x9ECD6129, 0x9E32C86E, 0xE224E0BA, 0x54692087,
    	0x29348192, 0x5E879E8A, 0xBC1157A2, 0x8E4257B9, 0x562856F2, 0x90E2328C,
    	0xF525AC6C, 0x5CAFC0B4, 0x8A23B37F, 0xC9E1225B, 0xDC13DEC7, 0xE5496EBB,
    	0x3162329C, 0x2FB02A4F, 0xA8FF85F4, 0xD991BD8C, 0x681F688F, 0x21C27CB0,
    	0xB2FE1141, 0x65D3D0C3, 0xEDBA861F, 0xDF69FBE0, 0xC51EC615, 0xEEBF8248,
    	0x76B98FB1, 0x16CC3A38, 0xCF66B094, 0xCF196437, 0x7112705D, 0x2A349043,
    	0x7A92D636, 0x2E57E05A, 0x4511D9BF, 0xE4F0912D, 0xEE09EF63, 0xF2A4B75D,
    	0xBED548C6, 0x5D480AA1, 0x67CDEF34, 0xF4800EFA, 0x5A05592B, 0x362FA556,
    	0x3D496B1B, 0x172BF02D, 0x2288ECDF, 0xF2784896, 0xF704F7B1, 0xF9525BAE,
    	0xF90EF5EB, 0x64341AD6, 0x0054DA54, 0xE208D741, 0x430841F9, 0x3DD949A5
    };

  } /* namespace dtv */
} /* namespace gr */
