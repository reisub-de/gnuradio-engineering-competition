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
      ninput_items_required[0] = (noutput_items / nbch) * kbch;
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

    //Ordering of bits: MSB(sr[0]) ... LSB(sr[0]) MSB(sr[1]) ... LSB(sr[1]) ... LSB(sr[3, 4 or 5])
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

    int
    dvb_bch_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {

     /* std::stringstream ss1;
      ss1 << "starting general_work " << clock();
      GR_LOG_DEBUG(LOG, ss1.str());
     */ 
      
      
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      unsigned char b, temp;
      unsigned int shift[6];
      int consumed = 0;

      switch (bch_code) {
        case BCH_CODE_N12:
          for (int i = 0; i < noutput_items; i += nbch) {
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 6);
            // MSB of the codeword first
            for (int j = 0; j < (int)kbch; j++) {
              temp = *in++;
              temp &= 1;
              *out++ = temp;
              consumed++;
              
              //          vvvvv LSB vvvv
              b = (temp ^ (shift[5] & 1));
              reg_6_shift(shift);
              if (b) {
                shift[0] ^= m_poly_n_12_0;
                shift[1] ^= m_poly_n_12_1;
                shift[2] ^= m_poly_n_12_2;
                shift[3] ^= m_poly_n_12_3;
                shift[4] ^= m_poly_n_12_4;
                shift[5] ^= m_poly_n_12_5;
              }
            }
            // Now add the parity bits to the output
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
              temp &= 1;
              *out++ = temp;
              consumed++;
              b = (temp ^ (shift[4] & 1));
              reg_5_shift(shift);
              if (b) {
                shift[0] ^= m_poly_n_10_0;
                shift[1] ^= m_poly_n_10_1;
                shift[2] ^= m_poly_n_10_2;
                shift[3] ^= m_poly_n_10_3;
                shift[4] ^= m_poly_n_10_4;
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
              temp &= 1;
              *out++ = temp;
              consumed++;
              b = temp ^ (shift[3] & 1);
              reg_4_shift(shift);
              if (b) {
                shift[0] ^= m_poly_n_8_0;
                shift[1] ^= m_poly_n_8_1;
                shift[2] ^= m_poly_n_8_2;
                shift[3] ^= m_poly_n_8_3;
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
              temp &= 1;
              *out++ = temp;
              consumed++;
              b = (temp ^ ((shift[5] & 0x01000000) ? 1 : 0));
              reg_6_shift(shift);
              if (b) {
                shift[0] ^= m_poly_s_12_0;
                shift[1] ^= m_poly_s_12_1;
                shift[2] ^= m_poly_s_12_2;
                shift[3] ^= m_poly_s_12_3;
                shift[4] ^= m_poly_s_12_4;
                shift[5] ^= m_poly_s_12_5;
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
              temp &= 1;
              *out++ = temp;
              consumed++;
              b = (temp ^ ((shift[5] & 0x00001000) ? 1 : 0));
              reg_6_shift(shift);
              if (b) {
                shift[0] ^= m_poly_m_12_0;
                shift[1] ^= m_poly_m_12_1;
                shift[2] ^= m_poly_m_12_2;
                shift[3] ^= m_poly_m_12_3;
                shift[4] ^= m_poly_m_12_4;
                shift[5] ^= m_poly_m_12_5;
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
/*
      std::stringstream ss2;
      ss2 << "ending general_work" << clock();
      GR_LOG_DEBUG(LOG, ss2.str());
    */  

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace dtv */
} /* namespace gr */

