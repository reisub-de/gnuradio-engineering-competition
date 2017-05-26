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
     *Shift a 128 bit register
     */
    inline void
    dvb_bch_bb_impl::reg_4_shift(unsigned int *sr)
    {
      sr[3] = (sr[3] << 1) | (sr[2] >> 31);
      sr[2] = (sr[2] << 1) | (sr[1] >> 31);
      sr[1] = (sr[1] << 1) | (sr[0] >> 31);
      sr[0] = (sr[0] << 1);
    }

    /*
     * Shift 160 bits
     */
    inline void
    dvb_bch_bb_impl::reg_5_shift(unsigned int *sr)
    {
      sr[4] = (sr[4] << 1) | (sr[3] >> 31);
      sr[3] = (sr[3] << 1) | (sr[2] >> 31);
      sr[2] = (sr[2] << 1) | (sr[1] >> 31);
      sr[1] = (sr[1] << 1) | (sr[0] >> 31);
      sr[0] = (sr[0] << 1);
    }

    /*
     * Shift 192 bits
     */
    inline void
    dvb_bch_bb_impl::reg_6_shift(unsigned int *sr)
    {
      sr[5] = (sr[5] << 1) | (sr[4] >> 31);
      sr[4] = (sr[4] << 1) | (sr[3] >> 31);
      sr[3] = (sr[3] << 1) | (sr[2] >> 31);
      sr[2] = (sr[2] << 1) | (sr[1] >> 31);
      sr[1] = (sr[1] << 1) | (sr[0] >> 31);
      sr[0] = (sr[0] << 1);
    }

    /*
     * Shift 192 bits by 8 bits
     */
    inline void
    dvb_bch_bb_impl::reg_6_shift_8(unsigned int *sr)
    {
      sr[5] = (sr[5] << 8) | (sr[4] >> 24);
      sr[4] = (sr[4] << 8) | (sr[3] >> 24);
      sr[3] = (sr[3] << 8) | (sr[2] >> 24);
      sr[2] = (sr[2] << 8) | (sr[1] >> 24);
      sr[1] = (sr[1] << 8) | (sr[0] >> 24);
      sr[0] = (sr[0] << 8);
    }

    int
    dvb_bch_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      unsigned char b;
      unsigned int shift[6];
      int consumed = 0;

      switch (bch_code) {
        case BCH_CODE_N12:
          for (int i = 0; i < noutput_items; i += nbch) {
            // Copy block from input to output buffer in one operation
            //memcpy(out, in, kbch);
            //out += kbch;
            for (int j = 0; j < (int)kbch/8; j++) {
              for (int k = 7; k >= 0; k--) {
                *out++ = (in[j] >> k) & 1;
              }
            }
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 6);
            // http://www.repairfaq.org/filipg/LINK/F_crc_v3.html
            for (int j = 0; j < (int)kbch/8; j++) {
              b = (*in++ ^ ((shift[5] >> 24) & 0xFF));
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
              *out++ = ((shift[5] >> 31) & 1);
              reg_6_shift(shift);
            }
          }
          break;
        /* Not adapted yet
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
          */
      }

      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (consumed);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

//    /*
//     * Polynomial calculation routines
//     * multiply polynomials
//     */
//    int
//    dvb_bch_bb_impl::poly_mult(const int *ina, int lena, const int *inb, int lenb, int *out)
//    {
//      memset(out, 0, sizeof(int) * (lena + lenb));
//
//      for (int i = 0; i < lena; i++) {
//        for (int j = 0; j < lenb; j++) {
//          if (ina[i] * inb[j] > 0 ) {
//            out[i + j]++;    // count number of terms for this pwr of x
//          }
//        }
//      }
//      int max = 0;
//      for (int i = 0; i < lena + lenb; i++) {
//        out[i] = out[i] & 1;    // If even ignore the term
//        if(out[i]) {
//          max = i;
//        }
//      }
//      // return the size of array to house the result.
//      return max + 1;
//    }
//
//    /*
//     * Pack the polynomial into a 32 bit array
//     */
//    void
//    dvb_bch_bb_impl::poly_pack(const int *pin, unsigned int* pout, int len)
//    {
//      int lw = len / 32;
//      int ptr = 0;
//      unsigned int temp;
//      if (len % 32) {
//        lw++;
//      }
//      for (int i = 0; i < lw; i++) {
//        temp = 1;
//        pout[i] = 0;
//        for (int j = 0; j < 32; j++) {
//          if (pin[ptr++]) {
//            pout[i] |= temp;
//          }
//          temp <<= 1;
//        }
//      }
//    }
//
//    // The code used to generate the polynomials and lookup table
//    void
//    dvb_bch_bb_impl::bch_poly_build_tables(void)
//    {
//      // Normal polynomials
//      const int polyn01[]={1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1};
//      const int polyn02[]={1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1};
//      const int polyn03[]={1,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1};
//      const int polyn04[]={1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1};
//      const int polyn05[]={1,1,1,1,0,1,0,0,1,1,1,1,1,0,0,0,1};
//      const int polyn06[]={1,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1};
//      const int polyn07[]={1,0,1,0,0,1,1,0,1,1,1,1,0,1,0,1,1};
//      const int polyn08[]={1,1,1,0,0,1,1,0,1,1,0,0,1,1,1,0,1};
//      const int polyn09[]={1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,0,1};
//      const int polyn10[]={1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,0,1};
//      const int polyn11[]={1,0,1,1,0,1,0,0,0,1,0,1,1,1,0,0,1};
//      const int polyn12[]={1,1,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1};
//
//      // Medium polynomials
//      const int polym01[]={1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1};
//      const int polym02[]={1,1,0,0,1,0,0,1,0,0,1,1,0,0,0,1};
//      const int polym03[]={1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1};
//      const int polym04[]={1,0,1,1,0,1,1,0,1,0,1,1,0,0,0,1};
//      const int polym05[]={1,1,1,0,1,0,1,1,0,0,1,0,1,0,0,1};
//      const int polym06[]={1,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1};
//      const int polym07[]={1,0,1,0,1,1,0,1,0,0,0,1,1,0,1,1};
//      const int polym08[]={1,0,1,0,1,0,1,0,1,1,0,1,0,0,1,1};
//      const int polym09[]={1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1};
//      const int polym10[]={1,1,1,1,1,0,0,1,0,0,1,1,1,1,0,1};
//      const int polym11[]={1,1,1,0,1,0,0,0,0,1,0,1,0,0,0,1};
//      const int polym12[]={1,0,1,0,1,0,0,0,1,0,1,1,0,1,1,1};
//
//      // Short polynomials
//      const int polys01[]={1,1,0,1,0,1,0,0,0,0,0,0,0,0,1};
//      const int polys02[]={1,0,0,0,0,0,1,0,1,0,0,1,0,0,1};
//      const int polys03[]={1,1,1,0,0,0,1,0,0,1,1,0,0,0,1};
//      const int polys04[]={1,0,0,0,1,0,0,1,1,0,1,0,1,0,1};
//      const int polys05[]={1,0,1,0,1,0,1,0,1,1,0,1,0,1,1};
//      const int polys06[]={1,0,0,1,0,0,0,1,1,1,0,0,0,1,1};
//      const int polys07[]={1,0,1,0,0,1,1,1,0,0,1,1,0,1,1};
//      const int polys08[]={1,0,0,0,0,1,0,0,1,1,1,1,0,0,1};
//      const int polys09[]={1,1,1,1,0,0,0,0,0,1,1,0,0,0,1};
//      const int polys10[]={1,0,0,1,0,0,1,0,0,1,0,1,1,0,1};
//      const int polys11[]={1,0,0,0,1,0,0,0,0,0,0,1,1,0,1};
//      const int polys12[]={1,1,1,1,0,1,1,1,1,0,1,0,0,1,1};
//
//      int len;
//      int polyout[2][200];
//
//      len = poly_mult(polyn01, 17, polyn02,    17,  polyout[0]);
//      len = poly_mult(polyn03, 17, polyout[0], len, polyout[1]);
//      len = poly_mult(polyn04, 17, polyout[1], len, polyout[0]);
//      len = poly_mult(polyn05, 17, polyout[0], len, polyout[1]);
//      len = poly_mult(polyn06, 17, polyout[1], len, polyout[0]);
//      len = poly_mult(polyn07, 17, polyout[0], len, polyout[1]);
//      len = poly_mult(polyn08, 17, polyout[1], len, polyout[0]);
//      poly_pack(polyout[0], m_poly_n_8, 128);
//
//      len = poly_mult(polyn09, 17, polyout[0], len, polyout[1]);
//      len = poly_mult(polyn10, 17, polyout[1], len, polyout[0]);
//      poly_pack(polyout[0], m_poly_n_10, 160);
//
//      len = poly_mult(polyn11, 17, polyout[0], len, polyout[1]);
//      len = poly_mult(polyn12, 17, polyout[1], len, polyout[0]);
//      unsigned int m_poly_n_12[6];
//      poly_pack(polyout[0], m_poly_n_12, 192);
//
//      len = poly_mult(polys01, 15, polys02,    15,  polyout[0]);
//      len = poly_mult(polys03, 15, polyout[0], len, polyout[1]);
//      len = poly_mult(polys04, 15, polyout[1], len, polyout[0]);
//      len = poly_mult(polys05, 15, polyout[0], len, polyout[1]);
//      len = poly_mult(polys06, 15, polyout[1], len, polyout[0]);
//      len = poly_mult(polys07, 15, polyout[0], len, polyout[1]);
//      len = poly_mult(polys08, 15, polyout[1], len, polyout[0]);
//      len = poly_mult(polys09, 15, polyout[0], len, polyout[1]);
//      len = poly_mult(polys10, 15, polyout[1], len, polyout[0]);
//      len = poly_mult(polys11, 15, polyout[0], len, polyout[1]);
//      len = poly_mult(polys12, 15, polyout[1], len, polyout[0]);
//      poly_pack(polyout[0], m_poly_s_12, 168);
//
//      len = poly_mult(polym01, 16, polym02,    16,  polyout[0]);
//      len = poly_mult(polym03, 16, polyout[0], len, polyout[1]);
//      len = poly_mult(polym04, 16, polyout[1], len, polyout[0]);
//      len = poly_mult(polym05, 16, polyout[0], len, polyout[1]);
//      len = poly_mult(polym06, 16, polyout[1], len, polyout[0]);
//      len = poly_mult(polym07, 16, polyout[0], len, polyout[1]);
//      len = poly_mult(polym08, 16, polyout[1], len, polyout[0]);
//      len = poly_mult(polym09, 16, polyout[0], len, polyout[1]);
//      len = poly_mult(polym10, 16, polyout[1], len, polyout[0]);
//      len = poly_mult(polym11, 16, polyout[0], len, polyout[1]);
//      len = poly_mult(polym12, 16, polyout[1], len, polyout[0]);
//      poly_pack(polyout[0], m_poly_m_12, 180);
//
//      // Print polys ready for pasting
//      printf("const unsigned int dvb_bch_bb_impl::m_poly_n_8[%i] = {\n\t", 4);
//      for (int i = 0; i < 4-1; i++) {
//        printf("0x%08X, ", m_poly_n_8[i]);
//      }
//      printf("0x%08X", m_poly_n_8[3]);
//      printf("\n};\n\n");
//
//      printf("const unsigned int dvb_bch_bb_impl::m_poly_n_10[%i] = {\n\t", 5);
//      for (int i = 0; i < 5-1; i++) {
//        printf("0x%08X, ", m_poly_n_10[i]);
//      }
//      printf("0x%08X", m_poly_n_10[4]);
//      printf("\n};\n\n");
//
//      printf("const unsigned int dvb_bch_bb_impl::m_poly_s_12[%i] = {\n\t", 6);
//      for (int i = 0; i < 6-1; i++) {
//        printf("0x%08X, ", m_poly_s_12[i]);
//      }
//      printf("0x%08X", m_poly_s_12[5]);
//      printf("\n};\n\n");
//
//      printf("const unsigned int dvb_bch_bb_impl::m_poly_m_12[%i] = {\n\t", 6);
//      for (int i = 0; i < 6-1; i++) {
//        printf("0x%08X, ", m_poly_m_12[i]);
//      }
//      printf("0x%08X", m_poly_m_12[5]);
//      printf("\n};\n\n");
//
//      // Calculate lookup tables for bch encoding
//      unsigned int tabval[6];
//      unsigned char ctrl_bit;
//      for (unsigned int b = 0; b < 256; b++) {
//        memset(tabval, 0, sizeof(unsigned int) * 6);
//        for (int i = 7; i >= 0; i--) {
//          ctrl_bit = ((b >> i) & 1) ^ ((tabval[5] >> 31) & 1);
//          reg_6_shift(tabval);
//          if (ctrl_bit){
//            tabval[0] ^= m_poly_n_12[0];
//            tabval[1] ^= m_poly_n_12[1];
//            tabval[2] ^= m_poly_n_12[2];
//            tabval[3] ^= m_poly_n_12[3];
//            tabval[4] ^= m_poly_n_12[4];
//            tabval[5] ^= m_poly_n_12[5];
//          }
//        }
//        for (int i = 0; i < 6; i++) {
//          m_lut_mod8_n_12[6*b + i] = tabval[i];
//        }
//      }
//      // Print LUT ready for pasting
//      printf("const unsigned int dvb_bch_bb_impl::m_lut_mod8_n_12[%i] = {\n", 256*6);
//      for (int i = 0; i < 6*256; i+=6) {
//        printf("\t");
//        for (int j = 0; j < 6-1; j++) {
//          printf("0x%08X, ", m_lut_mod8_n_12[i+j]);
//        }
//        printf("0x%08X", m_lut_mod8_n_12[i+5]);
//        if (i+6 != 6*256) {
//          printf(",");
//        }
//        printf("\n");
//      }
//      printf("};\n\n");
//    }

    const unsigned int dvb_bch_bb_impl::m_poly_n_8[4] = {
    	0x04F9662B, 0x19FC6D75, 0x712797BD, 0x1C07255F
    };

    const unsigned int dvb_bch_bb_impl::m_poly_n_10[5] = {
    	0xB8BB6591, 0xEFD12301, 0x6A785703, 0xFC2A331F, 0x60150CED
    };

    const unsigned int dvb_bch_bb_impl::m_poly_s_12[6] = {
    	0xD11905A5, 0x528FE7D7, 0x23A39069, 0x69B262CD, 0x62DBEA98, 0x4E260D40
    };

    const unsigned int dvb_bch_bb_impl::m_poly_m_12[6] = {
    	0xC3D8410B, 0x5635742F, 0xF6A08533, 0x0982039B, 0x7DB0018D, 0x4E1A84BB
    };

    const unsigned int dvb_bch_bb_impl::m_lut_mod8_n_12[1536] = {
    	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    	0x660255E7, 0x034785F7, 0xDC350889, 0x50CF2CD8, 0x845C511C, 0x4E260E83,
    	0xCC04ABCE, 0x068F0BEE, 0xB86A1112, 0xA19E59B1, 0x08B8A238, 0x9C4C1D07,
    	0xAA06FE29, 0x05C88E19, 0x645F199B, 0xF1517569, 0x8CE4F324, 0xD26A1384,
    	0xFE0B027B, 0x0E59922A, 0xACE12AAD, 0x13F39FBB, 0x952D156D, 0x76BE348D,
    	0x9809579C, 0x0D1E17DD, 0x70D42224, 0x433CB363, 0x11714471, 0x38983A0E,
    	0x320FA9B5, 0x08D699C4, 0x148B3BBF, 0xB26DC60A, 0x9D95B755, 0xEAF2298A,
    	0x540DFC52, 0x0B911C33, 0xC8BE3336, 0xE2A2EAD2, 0x19C9E649, 0xA4D42709,
    	0xFC1604F6, 0x1CB32455, 0x59C2555A, 0x27E73F77, 0x2A5A2ADA, 0xED7C691B,
    	0x9A145111, 0x1FF4A1A2, 0x85F75DD3, 0x772813AF, 0xAE067BC6, 0xA35A6798,
    	0x3012AF38, 0x1A3C2FBB, 0xE1A84448, 0x867966C6, 0x22E288E2, 0x7130741C,
    	0x5610FADF, 0x197BAA4C, 0x3D9D4CC1, 0xD6B64A1E, 0xA6BED9FE, 0x3F167A9F,
    	0x021D068D, 0x12EAB67F, 0xF5237FF7, 0x3414A0CC, 0xBF773FB7, 0x9BC25D96,
    	0x641F536A, 0x11AD3388, 0x2916777E, 0x64DB8C14, 0x3B2B6EAB, 0xD5E45315,
    	0xCE19AD43, 0x1465BD91, 0x4D496EE5, 0x958AF97D, 0xB7CF9D8F, 0x078E4091,
    	0xA81BF8A4, 0x17223866, 0x917C666C, 0xC545D5A5, 0x3393CC93, 0x49A84E12,
    	0x9E2E5C0B, 0x3A21CD5C, 0x6FB1A23D, 0x1F015236, 0xD0E804A8, 0x94DEDCB5,
    	0xF82C09EC, 0x396648AB, 0xB384AAB4, 0x4FCE7EEE, 0x54B455B4, 0xDAF8D236,
    	0x522AF7C5, 0x3CAEC6B2, 0xD7DBB32F, 0xBE9F0B87, 0xD850A690, 0x0892C1B2,
    	0x3428A222, 0x3FE94345, 0x0BEEBBA6, 0xEE50275F, 0x5C0CF78C, 0x46B4CF31,
    	0x60255E70, 0x34785F76, 0xC3508890, 0x0CF2CD8D, 0x45C511C5, 0xE260E838,
    	0x06270B97, 0x373FDA81, 0x1F658019, 0x5C3DE155, 0xC19940D9, 0xAC46E6BB,
    	0xAC21F5BE, 0x32F75498, 0x7B3A9982, 0xAD6C943C, 0x4D7DB3FD, 0x7E2CF53F,
    	0xCA23A059, 0x31B0D16F, 0xA70F910B, 0xFDA3B8E4, 0xC921E2E1, 0x300AFBBC,
    	0x623858FD, 0x2692E909, 0x3673F767, 0x38E66D41, 0xFAB22E72, 0x79A2B5AE,
    	0x043A0D1A, 0x25D56CFE, 0xEA46FFEE, 0x68294199, 0x7EEE7F6E, 0x3784BB2D,
    	0xAE3CF333, 0x201DE2E7, 0x8E19E675, 0x997834F0, 0xF20A8C4A, 0xE5EEA8A9,
    	0xC83EA6D4, 0x235A6710, 0x522CEEFC, 0xC9B71828, 0x7656DD56, 0xABC8A62A,
    	0x9C335A86, 0x28CB7B23, 0x9A92DDCA, 0x2B15F2FA, 0x6F9F3B1F, 0x0F1C8123,
    	0xFA310F61, 0x2B8CFED4, 0x46A7D543, 0x7BDADE22, 0xEBC36A03, 0x413A8FA0,
    	0x5037F148, 0x2E4470CD, 0x22F8CCD8, 0x8A8BAB4B, 0x67279927, 0x93509C24,
    	0x3635A4AF, 0x2D03F53A, 0xFECDC451, 0xDA448793, 0xE37BC83B, 0xDD7692A7,
    	0x5A5EEDF1, 0x77041F4E, 0x03564CF3, 0x6ECD88B4, 0x258C584C, 0x679BB7E8,
    	0x3C5CB816, 0x74439AB9, 0xDF63447A, 0x3E02A46C, 0xA1D00950, 0x29BDB96B,
    	0x965A463F, 0x718B14A0, 0xBB3C5DE1, 0xCF53D105, 0x2D34FA74, 0xFBD7AAEF,
    	0xF05813D8, 0x72CC9157, 0x67095568, 0x9F9CFDDD, 0xA968AB68, 0xB5F1A46C,
    	0xA455EF8A, 0x795D8D64, 0xAFB7665E, 0x7D3E170F, 0xB0A14D21, 0x11258365,
    	0xC257BA6D, 0x7A1A0893, 0x73826ED7, 0x2DF13BD7, 0x34FD1C3D, 0x5F038DE6,
    	0x68514444, 0x7FD2868A, 0x17DD774C, 0xDCA04EBE, 0xB819EF19, 0x8D699E62,
    	0x0E5311A3, 0x7C95037D, 0xCBE87FC5, 0x8C6F6266, 0x3C45BE05, 0xC34F90E1,
    	0xA648E907, 0x6BB73B1B, 0x5A9419A9, 0x492AB7C3, 0x0FD67296, 0x8AE7DEF3,
    	0xC04ABCE0, 0x68F0BEEC, 0x86A11120, 0x19E59B1B, 0x8B8A238A, 0xC4C1D070,
    	0x6A4C42C9, 0x6D3830F5, 0xE2FE08BB, 0xE8B4EE72, 0x076ED0AE, 0x16ABC3F4,
    	0x0C4E172E, 0x6E7FB502, 0x3ECB0032, 0xB87BC2AA, 0x833281B2, 0x588DCD77,
    	0x5843EB7C, 0x65EEA931, 0xF6753304, 0x5AD92878, 0x9AFB67FB, 0xFC59EA7E,
    	0x3E41BE9B, 0x66A92CC6, 0x2A403B8D, 0x0A1604A0, 0x1EA736E7, 0xB27FE4FD,
    	0x944740B2, 0x6361A2DF, 0x4E1F2216, 0xFB4771C9, 0x9243C5C3, 0x6015F779,
    	0xF2451555, 0x60262728, 0x922A2A9F, 0xAB885D11, 0x161F94DF, 0x2E33F9FA,
    	0xC470B1FA, 0x4D25D212, 0x6CE7EECE, 0x71CCDA82, 0xF5645CE4, 0xF3456B5D,
    	0xA272E41D, 0x4E6257E5, 0xB0D2E647, 0x2103F65A, 0x71380DF8, 0xBD6365DE,
    	0x08741A34, 0x4BAAD9FC, 0xD48DFFDC, 0xD0528333, 0xFDDCFEDC, 0x6F09765A,
    	0x6E764FD3, 0x48ED5C0B, 0x08B8F755, 0x809DAFEB, 0x7980AFC0, 0x212F78D9,
    	0x3A7BB381, 0x437C4038, 0xC006C463, 0x623F4539, 0x60494989, 0x85FB5FD0,
    	0x5C79E666, 0x403BC5CF, 0x1C33CCEA, 0x32F069E1, 0xE4151895, 0xCBDD5153,
    	0xF67F184F, 0x45F34BD6, 0x786CD571, 0xC3A11C88, 0x68F1EBB1, 0x19B742D7,
    	0x907D4DA8, 0x46B4CE21, 0xA459DDF8, 0x936E3050, 0xECADBAAD, 0x57914C54,
    	0x3866B50C, 0x5196F647, 0x3525BB94, 0x562BE5F5, 0xDF3E763E, 0x1E390246,
    	0x5E64E0EB, 0x52D173B0, 0xE910B31D, 0x06E4C92D, 0x5B622722, 0x501F0CC5,
    	0xF4621EC2, 0x5719FDA9, 0x8D4FAA86, 0xF7B5BC44, 0xD786D406, 0x82751F41,
    	0x92604B25, 0x545E785E, 0x517AA20F, 0xA77A909C, 0x53DA851A, 0xCC5311C2,
    	0xC66DB777, 0x5FCF646D, 0x99C49139, 0x45D87A4E, 0x4A136353, 0x688736CB,
    	0xA06FE290, 0x5C88E19A, 0x45F199B0, 0x15175696, 0xCE4F324F, 0x26A13848,
    	0x0A691CB9, 0x59406F83, 0x21AE802B, 0xE44623FF, 0x42ABC16B, 0xF4CB2BCC,
    	0x6C6B495E, 0x5A07EA74, 0xFD9B88A2, 0xB4890F27, 0xC6F79077, 0xBAED254F,
    	0xB4BDDBE2, 0xEE083E9C, 0x06AC99E6, 0xDD9B1168, 0x4B18B098, 0xCF376FD0,
    	0xD2BF8E05, 0xED4FBB6B, 0xDA99916F, 0x8D543DB0, 0xCF44E184, 0x81116153,
    	0x78B9702C, 0xE8873572, 0xBEC688F4, 0x7C0548D9, 0x43A012A0, 0x537B72D7,
    	0x1EBB25CB, 0xEBC0B085, 0x62F3807D, 0x2CCA6401, 0xC7FC43BC, 0x1D5D7C54,
    	0x4AB6D999, 0xE051ACB6, 0xAA4DB34B, 0xCE688ED3, 0xDE35A5F5, 0xB9895B5D,
    	0x2CB48C7E, 0xE3162941, 0x7678BBC2, 0x9EA7A20B, 0x5A69F4E9, 0xF7AF55DE,
    	0x86B27257, 0xE6DEA758, 0x1227A259, 0x6FF6D762, 0xD68D07CD, 0x25C5465A,
    	0xE0B027B0, 0xE59922AF, 0xCE12AAD0, 0x3F39FBBA, 0x52D156D1, 0x6BE348D9,
    	0x48ABDF14, 0xF2BB1AC9, 0x5F6ECCBC, 0xFA7C2E1F, 0x61429A42, 0x224B06CB,
    	0x2EA98AF3, 0xF1FC9F3E, 0x835BC435, 0xAAB302C7, 0xE51ECB5E, 0x6C6D0848,
    	0x84AF74DA, 0xF4341127, 0xE704DDAE, 0x5BE277AE, 0x69FA387A, 0xBE071BCC,
    	0xE2AD213D, 0xF77394D0, 0x3B31D527, 0x0B2D5B76, 0xEDA66966, 0xF021154F,
    	0xB6A0DD6F, 0xFCE288E3, 0xF38FE611, 0xE98FB1A4, 0xF46F8F2F, 0x54F53246,
    	0xD0A28888, 0xFFA50D14, 0x2FBAEE98, 0xB9409D7C, 0x7033DE33, 0x1AD33CC5,
    	0x7AA476A1, 0xFA6D830D, 0x4BE5F703, 0x4811E815, 0xFCD72D17, 0xC8B92F41,
    	0x1CA62346, 0xF92A06FA, 0x97D0FF8A, 0x18DEC4CD, 0x788B7C0B, 0x869F21C2,
    	0x2A9387E9, 0xD429F3C0, 0x691D3BDB, 0xC29A435E, 0x9BF0B430, 0x5BE9B365,
    	0x4C91D20E, 0xD76E7637, 0xB5283352, 0x92556F86, 0x1FACE52C, 0x15CFBDE6,
    	0xE6972C27, 0xD2A6F82E, 0xD1772AC9, 0x63041AEF, 0x93481608, 0xC7A5AE62,
    	0x809579C0, 0xD1E17DD9, 0x0D422240, 0x33CB3637, 0x17144714, 0x8983A0E1,
    	0xD4988592, 0xDA7061EA, 0xC5FC1176, 0xD169DCE5, 0x0EDDA15D, 0x2D5787E8,
    	0xB29AD075, 0xD937E41D, 0x19C919FF, 0x81A6F03D, 0x8A81F041, 0x6371896B,
    	0x189C2E5C, 0xDCFF6A04, 0x7D960064, 0x70F78554, 0x06650365, 0xB11B9AEF,
    	0x7E9E7BBB, 0xDFB8EFF3, 0xA1A308ED, 0x2038A98C, 0x82395279, 0xFF3D946C,
    	0xD685831F, 0xC89AD795, 0x30DF6E81, 0xE57D7C29, 0xB1AA9EEA, 0xB695DA7E,
    	0xB087D6F8, 0xCBDD5262, 0xECEA6608, 0xB5B250F1, 0x35F6CFF6, 0xF8B3D4FD,
    	0x1A8128D1, 0xCE15DC7B, 0x88B57F93, 0x44E32598, 0xB9123CD2, 0x2AD9C779,
    	0x7C837D36, 0xCD52598C, 0x5480771A, 0x142C0940, 0x3D4E6DCE, 0x64FFC9FA,
    	0x288E8164, 0xC6C345BF, 0x9C3E442C, 0xF68EE392, 0x24878B87, 0xC02BEEF3,
    	0x4E8CD483, 0xC584C048, 0x400B4CA5, 0xA641CF4A, 0xA0DBDA9B, 0x8E0DE070,
    	0xE48A2AAA, 0xC04C4E51, 0x2454553E, 0x5710BA23, 0x2C3F29BF, 0x5C67F3F4,
    	0x82887F4D, 0xC30BCBA6, 0xF8615DB7, 0x07DF96FB, 0xA86378A3, 0x1241FD77,
    	0xEEE33613, 0x990C21D2, 0x05FAD515, 0xB35699DC, 0x6E94E8D4, 0xA8ACD838,
    	0x88E163F4, 0x9A4BA425, 0xD9CFDD9C, 0xE399B504, 0xEAC8B9C8, 0xE68AD6BB,
    	0x22E79DDD, 0x9F832A3C, 0xBD90C407, 0x12C8C06D, 0x662C4AEC, 0x34E0C53F,
    	0x44E5C83A, 0x9CC4AFCB, 0x61A5CC8E, 0x4207ECB5, 0xE2701BF0, 0x7AC6CBBC,
    	0x10E83468, 0x9755B3F8, 0xA91BFFB8, 0xA0A50667, 0xFBB9FDB9, 0xDE12ECB5,
    	0x76EA618F, 0x9412360F, 0x752EF731, 0xF06A2ABF, 0x7FE5ACA5, 0x9034E236,
    	0xDCEC9FA6, 0x91DAB816, 0x1171EEAA, 0x013B5FD6, 0xF3015F81, 0x425EF1B2,
    	0xBAEECA41, 0x929D3DE1, 0xCD44E623, 0x51F4730E, 0x775D0E9D, 0x0C78FF31,
    	0x12F532E5, 0x85BF0587, 0x5C38804F, 0x94B1A6AB, 0x44CEC20E, 0x45D0B123,
    	0x74F76702, 0x86F88070, 0x800D88C6, 0xC47E8A73, 0xC0929312, 0x0BF6BFA0,
    	0xDEF1992B, 0x83300E69, 0xE452915D, 0x352FFF1A, 0x4C766036, 0xD99CAC24,
    	0xB8F3CCCC, 0x80778B9E, 0x386799D4, 0x65E0D3C2, 0xC82A312A, 0x97BAA2A7,
    	0xECFE309E, 0x8BE697AD, 0xF0D9AAE2, 0x87423910, 0xD1E3D763, 0x336E85AE,
    	0x8AFC6579, 0x88A1125A, 0x2CECA26B, 0xD78D15C8, 0x55BF867F, 0x7D488B2D,
    	0x20FA9B50, 0x8D699C43, 0x48B3BBF0, 0x26DC60A1, 0xD95B755B, 0xAF2298A9,
    	0x46F8CEB7, 0x8E2E19B4, 0x9486B379, 0x76134C79, 0x5D072447, 0xE104962A,
    	0x70CD6A18, 0xA32DEC8E, 0x6A4B7728, 0xAC57CBEA, 0xBE7CEC7C, 0x3C72048D,
    	0x16CF3FFF, 0xA06A6979, 0xB67E7FA1, 0xFC98E732, 0x3A20BD60, 0x72540A0E,
    	0xBCC9C1D6, 0xA5A2E760, 0xD221663A, 0x0DC9925B, 0xB6C44E44, 0xA03E198A,
    	0xDACB9431, 0xA6E56297, 0x0E146EB3, 0x5D06BE83, 0x32981F58, 0xEE181709,
    	0x8EC66863, 0xAD747EA4, 0xC6AA5D85, 0xBFA45451, 0x2B51F911, 0x4ACC3000,
    	0xE8C43D84, 0xAE33FB53, 0x1A9F550C, 0xEF6B7889, 0xAF0DA80D, 0x04EA3E83,
    	0x42C2C3AD, 0xABFB754A, 0x7EC04C97, 0x1E3A0DE0, 0x23E95B29, 0xD6802D07,
    	0x24C0964A, 0xA8BCF0BD, 0xA2F5441E, 0x4EF52138, 0xA7B50A35, 0x98A62384,
    	0x8CDB6EEE, 0xBF9EC8DB, 0x33892272, 0x8BB0F49D, 0x9426C6A6, 0xD10E6D96,
    	0xEAD93B09, 0xBCD94D2C, 0xEFBC2AFB, 0xDB7FD845, 0x107A97BA, 0x9F286315,
    	0x40DFC520, 0xB911C335, 0x8BE33360, 0x2A2EAD2C, 0x9C9E649E, 0x4D427091,
    	0x26DD90C7, 0xBA5646C2, 0x57D63BE9, 0x7AE181F4, 0x18C23582, 0x03647E12,
    	0x72D06C95, 0xB1C75AF1, 0x9F6808DF, 0x98436B26, 0x010BD3CB, 0xA7B0591B,
    	0x14D23972, 0xB280DF06, 0x435D0056, 0xC88C47FE, 0x855782D7, 0xE9965798,
    	0xBED4C75B, 0xB748511F, 0x270219CD, 0x39DD3297, 0x09B371F3, 0x3BFC441C,
    	0xD8D692BC, 0xB40FD4E8, 0xFB371144, 0x69121E4F, 0x8DEF20EF, 0x75DA4A9F,
    	0x0F79E223, 0xDF57F8CE, 0xD16C3B44, 0xEBF90E08, 0x126D302D, 0xD048D123,
    	0x697BB7C4, 0xDC107D39, 0x0D5933CD, 0xBB3622D0, 0x96316131, 0x9E6EDFA0,
    	0xC37D49ED, 0xD9D8F320, 0x69062A56, 0x4A6757B9, 0x1AD59215, 0x4C04CC24,
    	0xA57F1C0A, 0xDA9F76D7, 0xB53322DF, 0x1AA87B61, 0x9E89C309, 0x0222C2A7,
    	0xF172E058, 0xD10E6AE4, 0x7D8D11E9, 0xF80A91B3, 0x87402540, 0xA6F6E5AE,
    	0x9770B5BF, 0xD249EF13, 0xA1B81960, 0xA8C5BD6B, 0x031C745C, 0xE8D0EB2D,
    	0x3D764B96, 0xD781610A, 0xC5E700FB, 0x5994C802, 0x8FF88778, 0x3ABAF8A9,
    	0x5B741E71, 0xD4C6E4FD, 0x19D20872, 0x095BE4DA, 0x0BA4D664, 0x749CF62A,
    	0xF36FE6D5, 0xC3E4DC9B, 0x88AE6E1E, 0xCC1E317F, 0x38371AF7, 0x3D34B838,
    	0x956DB332, 0xC0A3596C, 0x549B6697, 0x9CD11DA7, 0xBC6B4BEB, 0x7312B6BB,
    	0x3F6B4D1B, 0xC56BD775, 0x30C47F0C, 0x6D8068CE, 0x308FB8CF, 0xA178A53F,
    	0x596918FC, 0xC62C5282, 0xECF17785, 0x3D4F4416, 0xB4D3E9D3, 0xEF5EABBC,
    	0x0D64E4AE, 0xCDBD4EB1, 0x244F44B3, 0xDFEDAEC4, 0xAD1A0F9A, 0x4B8A8CB5,
    	0x6B66B149, 0xCEFACB46, 0xF87A4C3A, 0x8F22821C, 0x29465E86, 0x05AC8236,
    	0xC1604F60, 0xCB32455F, 0x9C2555A1, 0x7E73F775, 0xA5A2ADA2, 0xD7C691B2,
    	0xA7621A87, 0xC875C0A8, 0x40105D28, 0x2EBCDBAD, 0x21FEFCBE, 0x99E09F31,
    	0x9157BE28, 0xE5763592, 0xBEDD9979, 0xF4F85C3E, 0xC2853485, 0x44960D96,
    	0xF755EBCF, 0xE631B065, 0x62E891F0, 0xA43770E6, 0x46D96599, 0x0AB00315,
    	0x5D5315E6, 0xE3F93E7C, 0x06B7886B, 0x5566058F, 0xCA3D96BD, 0xD8DA1091,
    	0x3B514001, 0xE0BEBB8B, 0xDA8280E2, 0x05A92957, 0x4E61C7A1, 0x96FC1E12,
    	0x6F5CBC53, 0xEB2FA7B8, 0x123CB3D4, 0xE70BC385, 0x57A821E8, 0x3228391B,
    	0x095EE9B4, 0xE868224F, 0xCE09BB5D, 0xB7C4EF5D, 0xD3F470F4, 0x7C0E3798,
    	0xA358179D, 0xEDA0AC56, 0xAA56A2C6, 0x46959A34, 0x5F1083D0, 0xAE64241C,
    	0xC55A427A, 0xEEE729A1, 0x7663AA4F, 0x165AB6EC, 0xDB4CD2CC, 0xE0422A9F,
    	0x6D41BADE, 0xF9C511C7, 0xE71FCC23, 0xD31F6349, 0xE8DF1E5F, 0xA9EA648D,
    	0x0B43EF39, 0xFA829430, 0x3B2AC4AA, 0x83D04F91, 0x6C834F43, 0xE7CC6A0E,
    	0xA1451110, 0xFF4A1A29, 0x5F75DD31, 0x72813AF8, 0xE067BC67, 0x35A6798A,
    	0xC74744F7, 0xFC0D9FDE, 0x8340D5B8, 0x224E1620, 0x643BED7B, 0x7B807709,
    	0x934AB8A5, 0xF79C83ED, 0x4BFEE68E, 0xC0ECFCF2, 0x7DF20B32, 0xDF545000,
    	0xF548ED42, 0xF4DB061A, 0x97CBEE07, 0x9023D02A, 0xF9AE5A2E, 0x91725E83,
    	0x5F4E136B, 0xF1138803, 0xF394F79C, 0x6172A543, 0x754AA90A, 0x43184D07,
    	0x394C468C, 0xF2540DF4, 0x2FA1FF15, 0x31BD899B, 0xF116F816, 0x0D3E4384,
    	0x55270FD2, 0xA853E780, 0xD23A77B7, 0x853486BC, 0x37E16861, 0xB7D366CB,
    	0x33255A35, 0xAB146277, 0x0E0F7F3E, 0xD5FBAA64, 0xB3BD397D, 0xF9F56848,
    	0x9923A41C, 0xAEDCEC6E, 0x6A5066A5, 0x24AADF0D, 0x3F59CA59, 0x2B9F7BCC,
    	0xFF21F1FB, 0xAD9B6999, 0xB6656E2C, 0x7465F3D5, 0xBB059B45, 0x65B9754F,
    	0xAB2C0DA9, 0xA60A75AA, 0x7EDB5D1A, 0x96C71907, 0xA2CC7D0C, 0xC16D5246,
    	0xCD2E584E, 0xA54DF05D, 0xA2EE5593, 0xC60835DF, 0x26902C10, 0x8F4B5CC5,
    	0x6728A667, 0xA0857E44, 0xC6B14C08, 0x375940B6, 0xAA74DF34, 0x5D214F41,
    	0x012AF380, 0xA3C2FBB3, 0x1A844481, 0x67966C6E, 0x2E288E28, 0x130741C2,
    	0xA9310B24, 0xB4E0C3D5, 0x8BF822ED, 0xA2D3B9CB, 0x1DBB42BB, 0x5AAF0FD0,
    	0xCF335EC3, 0xB7A74622, 0x57CD2A64, 0xF21C9513, 0x99E713A7, 0x14890153,
    	0x6535A0EA, 0xB26FC83B, 0x339233FF, 0x034DE07A, 0x1503E083, 0xC6E312D7,
    	0x0337F50D, 0xB1284DCC, 0xEFA73B76, 0x5382CCA2, 0x915FB19F, 0x88C51C54,
    	0x573A095F, 0xBAB951FF, 0x27190840, 0xB1202670, 0x889657D6, 0x2C113B5D,
    	0x31385CB8, 0xB9FED408, 0xFB2C00C9, 0xE1EF0AA8, 0x0CCA06CA, 0x623735DE,
    	0x9B3EA291, 0xBC365A11, 0x9F731952, 0x10BE7FC1, 0x802EF5EE, 0xB05D265A,
    	0xFD3CF776, 0xBF71DFE6, 0x434611DB, 0x40715319, 0x0472A4F2, 0xFE7B28D9,
    	0xCB0953D9, 0x92722ADC, 0xBD8BD58A, 0x9A35D48A, 0xE7096CC9, 0x230DBA7E,
    	0xAD0B063E, 0x9135AF2B, 0x61BEDD03, 0xCAFAF852, 0x63553DD5, 0x6D2BB4FD,
    	0x070DF817, 0x94FD2132, 0x05E1C498, 0x3BAB8D3B, 0xEFB1CEF1, 0xBF41A779,
    	0x610FADF0, 0x97BAA4C5, 0xD9D4CC11, 0x6B64A1E3, 0x6BED9FED, 0xF167A9FA,
    	0x350251A2, 0x9C2BB8F6, 0x116AFF27, 0x89C64B31, 0x722479A4, 0x55B38EF3,
    	0x53000445, 0x9F6C3D01, 0xCD5FF7AE, 0xD90967E9, 0xF67828B8, 0x1B958070,
    	0xF906FA6C, 0x9AA4B318, 0xA900EE35, 0x28581280, 0x7A9CDB9C, 0xC9FF93F4,
    	0x9F04AF8B, 0x99E336EF, 0x7535E6BC, 0x78973E58, 0xFEC08A80, 0x87D99D77,
    	0x371F572F, 0x8EC10E89, 0xE44980D0, 0xBDD2EBFD, 0xCD534613, 0xCE71D365,
    	0x511D02C8, 0x8D868B7E, 0x387C8859, 0xED1DC725, 0x490F170F, 0x8057DDE6,
    	0xFB1BFCE1, 0x884E0567, 0x5C2391C2, 0x1C4CB24C, 0xC5EBE42B, 0x523DCE62,
    	0x9D19A906, 0x8B098090, 0x8016994B, 0x4C839E94, 0x41B7B537, 0x1C1BC0E1,
    	0xC9145554, 0x80989CA3, 0x48A8AA7D, 0xAE217446, 0x587E537E, 0xB8CFE7E8,
    	0xAF1600B3, 0x83DF1954, 0x949DA2F4, 0xFEEE589E, 0xDC220262, 0xF6E9E96B,
    	0x0510FE9A, 0x8617974D, 0xF0C2BB6F, 0x0FBF2DF7, 0x50C6F146, 0x2483FAEF,
    	0x6312AB7D, 0x855012BA, 0x2CF7B3E6, 0x5F70012F, 0xD49AA05A, 0x6AA5F46C,
    	0xBBC439C1, 0x315FC652, 0xD7C0A2A2, 0x36621F60, 0x597580B5, 0x1F7FBEF3,
    	0xDDC66C26, 0x321843A5, 0x0BF5AA2B, 0x66AD33B8, 0xDD29D1A9, 0x5159B070,
    	0x77C0920F, 0x37D0CDBC, 0x6FAAB3B0, 0x97FC46D1, 0x51CD228D, 0x8333A3F4,
    	0x11C2C7E8, 0x3497484B, 0xB39FBB39, 0xC7336A09, 0xD5917391, 0xCD15AD77,
    	0x45CF3BBA, 0x3F065478, 0x7B21880F, 0x259180DB, 0xCC5895D8, 0x69C18A7E,
    	0x23CD6E5D, 0x3C41D18F, 0xA7148086, 0x755EAC03, 0x4804C4C4, 0x27E784FD,
    	0x89CB9074, 0x39895F96, 0xC34B991D, 0x840FD96A, 0xC4E037E0, 0xF58D9779,
    	0xEFC9C593, 0x3ACEDA61, 0x1F7E9194, 0xD4C0F5B2, 0x40BC66FC, 0xBBAB99FA,
    	0x47D23D37, 0x2DECE207, 0x8E02F7F8, 0x11852017, 0x732FAA6F, 0xF203D7E8,
    	0x21D068D0, 0x2EAB67F0, 0x5237FF71, 0x414A0CCF, 0xF773FB73, 0xBC25D96B,
    	0x8BD696F9, 0x2B63E9E9, 0x3668E6EA, 0xB01B79A6, 0x7B970857, 0x6E4FCAEF,
    	0xEDD4C31E, 0x28246C1E, 0xEA5DEE63, 0xE0D4557E, 0xFFCB594B, 0x2069C46C,
    	0xB9D93F4C, 0x23B5702D, 0x22E3DD55, 0x0276BFAC, 0xE602BF02, 0x84BDE365,
    	0xDFDB6AAB, 0x20F2F5DA, 0xFED6D5DC, 0x52B99374, 0x625EEE1E, 0xCA9BEDE6,
    	0x75DD9482, 0x253A7BC3, 0x9A89CC47, 0xA3E8E61D, 0xEEBA1D3A, 0x18F1FE62,
    	0x13DFC165, 0x267DFE34, 0x46BCC4CE, 0xF327CAC5, 0x6AE64C26, 0x56D7F0E1,
    	0x25EA65CA, 0x0B7E0B0E, 0xB871009F, 0x29634D56, 0x899D841D, 0x8BA16246,
    	0x43E8302D, 0x08398EF9, 0x64440816, 0x79AC618E, 0x0DC1D501, 0xC5876CC5,
    	0xE9EECE04, 0x0DF100E0, 0x001B118D, 0x88FD14E7, 0x81252625, 0x17ED7F41,
    	0x8FEC9BE3, 0x0EB68517, 0xDC2E1904, 0xD832383F, 0x05797739, 0x59CB71C2,
    	0xDBE167B1, 0x05279924, 0x14902A32, 0x3A90D2ED, 0x1CB09170, 0xFD1F56CB,
    	0xBDE33256, 0x06601CD3, 0xC8A522BB, 0x6A5FFE35, 0x98ECC06C, 0xB3395848,
    	0x17E5CC7F, 0x03A892CA, 0xACFA3B20, 0x9B0E8B5C, 0x14083348, 0x61534BCC,
    	0x71E79998, 0x00EF173D, 0x70CF33A9, 0xCBC1A784, 0x90546254, 0x2F75454F,
    	0xD9FC613C, 0x17CD2F5B, 0xE1B355C5, 0x0E847221, 0xA3C7AEC7, 0x66DD0B5D,
    	0xBFFE34DB, 0x148AAAAC, 0x3D865D4C, 0x5E4B5EF9, 0x279BFFDB, 0x28FB05DE,
    	0x15F8CAF2, 0x114224B5, 0x59D944D7, 0xAF1A2B90, 0xAB7F0CFF, 0xFA91165A,
    	0x73FA9F15, 0x1205A142, 0x85EC4C5E, 0xFFD50748, 0x2F235DE3, 0xB4B718D9,
    	0x27F76347, 0x1994BD71, 0x4D527F68, 0x1D77ED9A, 0x36EABBAA, 0x10633FD0,
    	0x41F536A0, 0x1AD33886, 0x916777E1, 0x4DB8C142, 0xB2B6EAB6, 0x5E453153,
    	0xEBF3C889, 0x1F1BB69F, 0xF5386E7A, 0xBCE9B42B, 0x3E521992, 0x8C2F22D7,
    	0x8DF19D6E, 0x1C5C3368, 0x290D66F3, 0xEC2698F3, 0xBA0E488E, 0xC2092C54,
    	0xE19AD430, 0x465BD91C, 0xD496EE51, 0x58AF97D4, 0x7CF9D8F9, 0x78E4091B,
    	0x879881D7, 0x451C5CEB, 0x08A3E6D8, 0x0860BB0C, 0xF8A589E5, 0x36C20798,
    	0x2D9E7FFE, 0x40D4D2F2, 0x6CFCFF43, 0xF931CE65, 0x74417AC1, 0xE4A8141C,
    	0x4B9C2A19, 0x43935705, 0xB0C9F7CA, 0xA9FEE2BD, 0xF01D2BDD, 0xAA8E1A9F,
    	0x1F91D64B, 0x48024B36, 0x7877C4FC, 0x4B5C086F, 0xE9D4CD94, 0x0E5A3D96,
    	0x799383AC, 0x4B45CEC1, 0xA442CC75, 0x1B9324B7, 0x6D889C88, 0x407C3315,
    	0xD3957D85, 0x4E8D40D8, 0xC01DD5EE, 0xEAC251DE, 0xE16C6FAC, 0x92162091,
    	0xB5972862, 0x4DCAC52F, 0x1C28DD67, 0xBA0D7D06, 0x65303EB0, 0xDC302E12,
    	0x1D8CD0C6, 0x5AE8FD49, 0x8D54BB0B, 0x7F48A8A3, 0x56A3F223, 0x95986000,
    	0x7B8E8521, 0x59AF78BE, 0x5161B382, 0x2F87847B, 0xD2FFA33F, 0xDBBE6E83,
    	0xD1887B08, 0x5C67F6A7, 0x353EAA19, 0xDED6F112, 0x5E1B501B, 0x09D47D07,
    	0xB78A2EEF, 0x5F207350, 0xE90BA290, 0x8E19DDCA, 0xDA470107, 0x47F27384,
    	0xE387D2BD, 0x54B16F63, 0x21B591A6, 0x6CBB3718, 0xC38EE74E, 0xE326548D,
    	0x8585875A, 0x57F6EA94, 0xFD80992F, 0x3C741BC0, 0x47D2B652, 0xAD005A0E,
    	0x2F837973, 0x523E648D, 0x99DF80B4, 0xCD256EA9, 0xCB364576, 0x7F6A498A,
    	0x49812C94, 0x5179E17A, 0x45EA883D, 0x9DEA4271, 0x4F6A146A, 0x314C4709,
    	0x7FB4883B, 0x7C7A1440, 0xBB274C6C, 0x47AEC5E2, 0xAC11DC51, 0xEC3AD5AE,
    	0x19B6DDDC, 0x7F3D91B7, 0x671244E5, 0x1761E93A, 0x284D8D4D, 0xA21CDB2D,
    	0xB3B023F5, 0x7AF51FAE, 0x034D5D7E, 0xE6309C53, 0xA4A97E69, 0x7076C8A9,
    	0xD5B27612, 0x79B29A59, 0xDF7855F7, 0xB6FFB08B, 0x20F52F75, 0x3E50C62A,
    	0x81BF8A40, 0x7223866A, 0x17C666C1, 0x545D5A59, 0x393CC93C, 0x9A84E123,
    	0xE7BDDFA7, 0x7164039D, 0xCBF36E48, 0x04927681, 0xBD609820, 0xD4A2EFA0,
    	0x4DBB218E, 0x74AC8D84, 0xAFAC77D3, 0xF5C303E8, 0x31846B04, 0x06C8FC24,
    	0x2BB97469, 0x77EB0873, 0x73997F5A, 0xA50C2F30, 0xB5D83A18, 0x48EEF2A7,
    	0x83A28CCD, 0x60C93015, 0xE2E51936, 0x6049FA95, 0x864BF68B, 0x0146BCB5,
    	0xE5A0D92A, 0x638EB5E2, 0x3ED011BF, 0x3086D64D, 0x0217A797, 0x4F60B236,
    	0x4FA62703, 0x66463BFB, 0x5A8F0824, 0xC1D7A324, 0x8EF354B3, 0x9D0AA1B2,
    	0x29A472E4, 0x6501BE0C, 0x86BA00AD, 0x91188FFC, 0x0AAF05AF, 0xD32CAF31,
    	0x7DA98EB6, 0x6E90A23F, 0x4E04339B, 0x73BA652E, 0x1366E3E6, 0x77F88838,
    	0x1BABDB51, 0x6DD727C8, 0x92313B12, 0x237549F6, 0x973AB2FA, 0x39DE86BB,
    	0xB1AD2578, 0x681FA9D1, 0xF66E2289, 0xD2243C9F, 0x1BDE41DE, 0xEBB4953F,
    	0xD7AF709F, 0x6B582C26, 0x2A5B2A00, 0x82EB1047, 0x9F8210C2, 0xA5929BBC
    };

  } /* namespace dtv */
} /* namespace gr */
