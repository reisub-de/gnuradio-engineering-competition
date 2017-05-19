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

      bch_poly_build_tables();
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

    void
    dvb_bch_bb_impl::bch_poly_build_tables(void)
    {
      m_poly_n_8[0] = 0xD4669F20;
      m_poly_n_8[1] = 0xAEB63F98;
      m_poly_n_8[2] = 0xBDE9E48E;
      m_poly_n_8[3] = 0xFAA4E038;
      m_poly_n_10[0] = 0x89A6DD1D;
      m_poly_n_10[1] = 0x80C48BF7;
      m_poly_n_10[2] = 0xC0EA1E56;
      m_poly_n_10[3] = 0xF8CC543F;
      m_poly_n_10[4] = 0xB730A806;
      m_poly_n_12[0] = 0xE7AA4066;
      m_poly_n_12[1] = 0xEFA1E2C0;
      m_poly_n_12[2] = 0x9110AC3B;
      m_poly_n_12[3] = 0x1B34F30A;
      m_poly_n_12[4] = 0x388A3A21;
      m_poly_n_12[5] = 0xC1706472;
      m_poly_s_12[0] = 0xA5A0988B;
      m_poly_s_12[1] = 0xEBE7F14A;
      m_poly_s_12[2] = 0x9609C5C4;
      m_poly_s_12[3] = 0xB3464D96;
      m_poly_s_12[4] = 0x1957DB46;
      m_poly_s_12[5] = 0x02B06472;
      m_poly_m_12[0] = 0xD0821BC3;
      m_poly_m_12[1] = 0xF42EAC6A;
      m_poly_m_12[2] = 0xCCA1056F;
      m_poly_m_12[3] = 0xD9C04190;
      m_poly_m_12[4] = 0xB1800DBE;
      m_poly_m_12[5] = 0xDD215872;

      m_lut_mod8_m_12[0] = 0x00000000;
      m_lut_mod8_m_12[1] = 0x00000000;
      m_lut_mod8_m_12[2] = 0x00000000;
      m_lut_mod8_m_12[3] = 0x00000000;
      m_lut_mod8_m_12[4] = 0x00000000;
      m_lut_mod8_m_12[5] = 0x00000000;
      m_lut_mod8_m_12[6] = 0xC4479EF0;
      m_lut_mod8_m_12[7] = 0x731FEAFB;
      m_lut_mod8_m_12[8] = 0x22DC368B;
      m_lut_mod8_m_12[9] = 0x10709FD7;
      m_lut_mod8_m_12[10] = 0xB40CB648;
      m_lut_mod8_m_12[11] = 0xC48B120B;
      m_lut_mod8_m_12[12] = 0x47DBBD2D;
      m_lut_mod8_m_12[13] = 0x397C1077;
      m_lut_mod8_m_12[14] = 0x67993560;
      m_lut_mod8_m_12[15] = 0x1688D9BB;
      m_lut_mod8_m_12[16] = 0x190D18D2;
      m_lut_mod8_m_12[17] = 0x0BF6ECF3;
      m_lut_mod8_m_12[18] = 0x839C23DD;
      m_lut_mod8_m_12[19] = 0x4A63FA8C;
      m_lut_mod8_m_12[20] = 0x454503EB;
      m_lut_mod8_m_12[21] = 0x06F8466C;
      m_lut_mod8_m_12[22] = 0xAD01AE9A;
      m_lut_mod8_m_12[23] = 0xCF7DFEF8;
      m_lut_mod8_m_12[24] = 0x8FB77A5A;
      m_lut_mod8_m_12[25] = 0x72F820EE;
      m_lut_mod8_m_12[26] = 0xCF326AC0;
      m_lut_mod8_m_12[27] = 0x2D11B376;
      m_lut_mod8_m_12[28] = 0x321A31A4;
      m_lut_mod8_m_12[29] = 0x17EDD9E6;
      m_lut_mod8_m_12[30] = 0x4BF0E4AA;
      m_lut_mod8_m_12[31] = 0x01E7CA15;
      m_lut_mod8_m_12[32] = 0xEDEE5C4B;
      m_lut_mod8_m_12[33] = 0x3D612CA1;
      m_lut_mod8_m_12[34] = 0x861687EC;
      m_lut_mod8_m_12[35] = 0xD366CBED;
      m_lut_mod8_m_12[36] = 0xC86CC777;
      m_lut_mod8_m_12[37] = 0x4B843099;
      m_lut_mod8_m_12[38] = 0xA8AB5FA0;
      m_lut_mod8_m_12[39] = 0x3B996ACD;
      m_lut_mod8_m_12[40] = 0x2B172976;
      m_lut_mod8_m_12[41] = 0x1C1B3515;
      m_lut_mod8_m_12[42] = 0x0C2B5987;
      m_lut_mod8_m_12[43] = 0x389BDA62;
      m_lut_mod8_m_12[44] = 0x8A77692B;
      m_lut_mod8_m_12[45] = 0x2BE9F51A;
      m_lut_mod8_m_12[46] = 0x9F1B9F3E;
      m_lut_mod8_m_12[47] = 0xD890271E;
      m_lut_mod8_m_12[48] = 0xD03A7479;
      m_lut_mod8_m_12[49] = 0x3AB3845C;
      m_lut_mod8_m_12[50] = 0xBC458DF6;
      m_lut_mod8_m_12[51] = 0x6C4A80F8;
      m_lut_mod8_m_12[52] = 0x1520170B;
      m_lut_mod8_m_12[53] = 0xAD3B7B29;
      m_lut_mod8_m_12[54] = 0x147DEA89;
      m_lut_mod8_m_12[55] = 0x49AC6EA7;
      m_lut_mod8_m_12[56] = 0x9E99BB7D;
      m_lut_mod8_m_12[57] = 0x7C3A1F2F;
      m_lut_mod8_m_12[58] = 0xA12CA143;
      m_lut_mod8_m_12[59] = 0x69B06922;
      m_lut_mod8_m_12[60] = 0x97E1C954;
      m_lut_mod8_m_12[61] = 0x03CF942B;
      m_lut_mod8_m_12[62] = 0xDBDCB896;
      m_lut_mod8_m_12[63] = 0x7AC25943;
      m_lut_mod8_m_12[64] = 0x0C2D0FD9;
      m_lut_mod8_m_12[65] = 0xA6CD97DA;
      m_lut_mod8_m_12[66] = 0x53A657A4;
      m_lut_mod8_m_12[67] = 0x70D07ED0;
      m_lut_mod8_m_12[68] = 0xF9008E1D;
      m_lut_mod8_m_12[69] = 0x6AB2C694;
      m_lut_mod8_m_12[70] = 0xB821B991;
      m_lut_mod8_m_12[71] = 0x624685D1;
      m_lut_mod8_m_12[72] = 0x5F8D0E23;
      m_lut_mod8_m_12[73] = 0x484BA4B2;
      m_lut_mod8_m_12[74] = 0x7377E736;
      m_lut_mod8_m_12[75] = 0x415B338E;
      m_lut_mod8_m_12[76] = 0x273A26AF;
      m_lut_mod8_m_12[77] = 0xBAD6A2CF;
      m_lut_mod8_m_12[78] = 0x9BCA90D3;
      m_lut_mod8_m_12[79] = 0x3B544E49;
      m_lut_mod8_m_12[80] = 0x51ABD1BD;
      m_lut_mod8_m_12[81] = 0x512BAC59;
      m_lut_mod8_m_12[82] = 0x933690E7;
      m_lut_mod8_m_12[83] = 0x7E5DB0C4;
      m_lut_mod8_m_12[84] = 0x1856B30E;
      m_lut_mod8_m_12[85] = 0x7137B4C5;
      m_lut_mod8_m_12[86] = 0x14EED256;
      m_lut_mod8_m_12[87] = 0x57D3EA35;
      m_lut_mod8_m_12[88] = 0x3E373E7D;
      m_lut_mod8_m_12[89] = 0xB1204E3C;
      m_lut_mod8_m_12[90] = 0xDC112DFE;
      m_lut_mod8_m_12[91] = 0x02285E3E;
      m_lut_mod8_m_12[92] = 0x3632E4DD;
      m_lut_mod8_m_12[93] = 0x47A375E2;
      m_lut_mod8_m_12[94] = 0x8A3B8835;
      m_lut_mod8_m_12[95] = 0x75AB5C37;
      m_lut_mod8_m_12[96] = 0x6F20683F;
      m_lut_mod8_m_12[97] = 0xAA24CD38;
      m_lut_mod8_m_12[98] = 0x5AAA439A;
      m_lut_mod8_m_12[99] = 0xEEFCE7E4;
      m_lut_mod8_m_12[100] = 0x5B545A54;
      m_lut_mod8_m_12[101] = 0xD8963EB7;
      m_lut_mod8_m_12[102] = 0xAB67F6CF;
      m_lut_mod8_m_12[103] = 0xD93B27C3;
      m_lut_mod8_m_12[104] = 0x78767511;
      m_lut_mod8_m_12[105] = 0xFE8C7833;
      m_lut_mod8_m_12[106] = 0xEF58EC1C;
      m_lut_mod8_m_12[107] = 0x1C1D2CBC;
      m_lut_mod8_m_12[108] = 0x28FBD512;
      m_lut_mod8_m_12[109] = 0x9358DD4F;
      m_lut_mod8_m_12[110] = 0x3D3376FA;
      m_lut_mod8_m_12[111] = 0xF8743E5F;
      m_lut_mod8_m_12[112] = 0x42594286;
      m_lut_mod8_m_12[113] = 0xD360D244;
      m_lut_mod8_m_12[114] = 0xECBC4BE2;
      m_lut_mod8_m_12[115] = 0xE04737B4;
      m_lut_mod8_m_12[116] = 0x1FEF4071;
      m_lut_mod8_m_12[117] = 0xE804A188;
      m_lut_mod8_m_12[118] = 0xF655F4CE;
      m_lut_mod8_m_12[119] = 0x17EBC04F;
      m_lut_mod8_m_12[120] = 0xE0971265;
      m_lut_mod8_m_12[121] = 0xD8DCEDD6;
      m_lut_mod8_m_12[122] = 0x9598295A;
      m_lut_mod8_m_12[123] = 0xC3ED5492;
      m_lut_mod8_m_12[124] = 0x694E6BF0;
      m_lut_mod8_m_12[125] = 0xCF7BE751;
      m_lut_mod8_m_12[126] = 0x24D08C95;
      m_lut_mod8_m_12[127] = 0xABC3072D;
      m_lut_mod8_m_12[128] = 0xB7441FD1;
      m_lut_mod8_m_12[129] = 0xD39DCB45;
      m_lut_mod8_m_12[130] = 0xDD42DDB8;
      m_lut_mod8_m_12[131] = 0x0BF0F55A;
      m_lut_mod8_m_12[132] = 0xA74CAF48;
      m_lut_mod8_m_12[133] = 0xE1A0FDA1;
      m_lut_mod8_m_12[134] = 0xF2011C3A;
      m_lut_mod8_m_12[135] = 0xD5658D29;
      m_lut_mod8_m_12[136] = 0x70437322;
      m_lut_mod8_m_12[137] = 0xC48D0BA2;
      m_lut_mod8_m_12[138] = 0x630B31B8;
      m_lut_mod8_m_12[139] = 0x92BF175A;
      m_lut_mod8_m_12[140] = 0xD0DD2AB1;
      m_lut_mod8_m_12[141] = 0xC51512FE;
      m_lut_mod8_m_12[142] = 0xC44FC56A;
      m_lut_mod8_m_12[143] = 0x000619A9;
      m_lut_mod8_m_12[144] = 0xBF1A1C46;
      m_lut_mod8_m_12[145] = 0x90974964;
      m_lut_mod8_m_12[146] = 0xE6EFCE6C;
      m_lut_mod8_m_12[147] = 0x82B6671C;
      m_lut_mod8_m_12[148] = 0x4E744D5F;
      m_lut_mod8_m_12[149] = 0x75AD459E;
      m_lut_mod8_m_12[150] = 0x7B5D82B6;
      m_lut_mod8_m_12[151] = 0xE388A39F;
      m_lut_mod8_m_12[152] = 0xC433F8E7;
      m_lut_mod8_m_12[153] = 0x92C6F8CB;
      m_lut_mod8_m_12[154] = 0xFA78FB17;
      m_lut_mod8_m_12[155] = 0xB1265795;
      m_lut_mod8_m_12[156] = 0xF8C1A16B;
      m_lut_mod8_m_12[157] = 0xA9EB5913;
      m_lut_mod8_m_12[158] = 0x8176FB0C;
      m_lut_mod8_m_12[159] = 0x943EBEA7;
      m_lut_mod8_m_12[160] = 0x5779558D;
      m_lut_mod8_m_12[161] = 0x7E5BA96D;
      m_lut_mod8_m_12[162] = 0x3C863F9B;
      m_lut_mod8_m_12[163] = 0xDAF4B3E8;
      m_lut_mod8_m_12[164] = 0xA3AACD87;
      m_lut_mod8_m_12[165] = 0x844E2170;
      m_lut_mod8_m_12[166] = 0xE375E3C5;
      m_lut_mod8_m_12[167] = 0xBAD0BB66;
      m_lut_mod8_m_12[168] = 0x30AD661C;
      m_lut_mod8_m_12[169] = 0xE26F698A;
      m_lut_mod8_m_12[170] = 0x29DDA4AC;
      m_lut_mod8_m_12[171] = 0xAFA7D46A;
      m_lut_mod8_m_12[172] = 0x7C6E7CFB;
      m_lut_mod8_m_12[173] = 0x62409C78;
      m_lut_mod8_m_12[174] = 0xF4EAF8EC;
      m_lut_mod8_m_12[175] = 0x91708371;
      m_lut_mod8_m_12[176] = 0x0B019227;
      m_lut_mod8_m_12[177] = 0xBFD74BBD;
      m_lut_mod8_m_12[178] = 0xC862CAB3;
      m_lut_mod8_m_12[179] = 0xA6CB8E73;
      m_lut_mod8_m_12[180] = 0x7776DB31;
      m_lut_mod8_m_12[181] = 0xDB1379FD;
      m_lut_mod8_m_12[182] = 0x4E4491CC;
      m_lut_mod8_m_12[183] = 0xB92F0DD1;
      m_lut_mod8_m_12[184] = 0x65636429;
      m_lut_mod8_m_12[185] = 0x69B6708B;
      m_lut_mod8_m_12[186] = 0xB33145C1;
      m_lut_mod8_m_12[187] = 0xA80C9306;
      m_lut_mod8_m_12[188] = 0x6C98A747;
      m_lut_mod8_m_12[189] = 0xA95F9206;
      m_lut_mod8_m_12[190] = 0xD16FD261;
      m_lut_mod8_m_12[191] = 0xAD3D6280;
      m_lut_mod8_m_12[192] = 0xDE40D07F;
      m_lut_mod8_m_12[193] = 0x54499A70;
      m_lut_mod8_m_12[194] = 0xB5548735;
      m_lut_mod8_m_12[195] = 0xDDF9CFC8;
      m_lut_mod8_m_12[196] = 0xB6A8B4A9;
      m_lut_mod8_m_12[197] = 0xB12C7D6E;
      m_lut_mod8_m_12[198] = 0x1A074E8F;
      m_lut_mod8_m_12[199] = 0x2756708B;
      m_lut_mod8_m_12[200] = 0x9788B1BE;
      m_lut_mod8_m_12[201] = 0xCD89501F;
      m_lut_mod8_m_12[202] = 0x02A402E1;
      m_lut_mod8_m_12[203] = 0x75A76F65;
      m_lut_mod8_m_12[204] = 0x999B6D52;
      m_lut_mod8_m_12[205] = 0x6D358A07;
      m_lut_mod8_m_12[206] = 0xD2CDB255;
      m_lut_mod8_m_12[207] = 0xCB711673;
      m_lut_mod8_m_12[208] = 0xAFA5AC7B;
      m_lut_mod8_m_12[209] = 0xBADA919D;
      m_lut_mod8_m_12[210] = 0x5DDCF3A2;
      m_lut_mod8_m_12[211] = 0x1E2A60FC;
      m_lut_mod8_m_12[212] = 0xF01184DE;
      m_lut_mod8_m_12[213] = 0xDB0189A4;
      m_lut_mod8_m_12[214] = 0x1BA91A33;
      m_lut_mod8_m_12[215] = 0x7E518396;
      m_lut_mod8_m_12[216] = 0x51F7AA25;
      m_lut_mod8_m_12[217] = 0x26B1BA9E;
      m_lut_mod8_m_12[218] = 0x7A66EDF5;
      m_lut_mod8_m_12[219] = 0xF0E87CBE;
      m_lut_mod8_m_12[220] = 0x84B2850D;
      m_lut_mod8_m_12[221] = 0xA6C1A488;
      m_lut_mod8_m_12[222] = 0x95B034D5;
      m_lut_mod8_m_12[223] = 0x55AE5065;
      m_lut_mod8_m_12[224] = 0x58BADB7E;
      m_lut_mod8_m_12[225] = 0xE098E369;
      m_lut_mod8_m_12[226] = 0x30BE3345;
      m_lut_mod8_m_12[227] = 0x624AB683;
      m_lut_mod8_m_12[228] = 0x162C1708;
      m_lut_mod8_m_12[229] = 0x1FCDAAE9;
      m_lut_mod8_m_12[230] = 0x1DFFD895;
      m_lut_mod8_m_12[231] = 0xE660A505;
      m_lut_mod8_m_12[232] = 0x9DBF9DDF;
      m_lut_mod8_m_12[233] = 0xAD37487B;
      m_lut_mod8_m_12[234] = 0xD26B89F8;
      m_lut_mod8_m_12[235] = 0x6CD24012;
      m_lut_mod8_m_12[236] = 0x3F23EE1E;
      m_lut_mod8_m_12[237] = 0xF6103AD2;
      m_lut_mod8_m_12[238] = 0x29B32B97;
      m_lut_mod8_m_12[239] = 0x69BC5A70;
      m_lut_mod8_m_12[240] = 0x0E7AA406;
      m_lut_mod8_m_12[241] = 0x6EFA1E2C;
      m_lut_mod8_m_12[242] = 0x09110AC3;
      m_lut_mod8_m_12[243] = 0xB1B34F30;
      m_lut_mod8_m_12[244] = 0xA388A3A2;
      m_lut_mod8_m_12[245] = 0x1C170647;
      m_lut_mod8_m_12[246] = 0xCA3D3AF6;
      m_lut_mod8_m_12[247] = 0x1DE5F4D7;
      m_lut_mod8_m_12[248] = 0x2BCD3C48;
      m_lut_mod8_m_12[249] = 0xA1C3D0E7;
      m_lut_mod8_m_12[250] = 0x178415EA;
      m_lut_mod8_m_12[251] = 0xD89C144C;
      m_lut_mod8_m_12[252] = 0x49A1192B;
      m_lut_mod8_m_12[253] = 0x57860E5B;
      m_lut_mod8_m_12[254] = 0x6E883FA3;
      m_lut_mod8_m_12[255] = 0xA73B968B;
      m_lut_mod8_m_12[256] = 0xBA85BB70;
      m_lut_mod8_m_12[257] = 0x17E1EAB4;
      m_lut_mod8_m_12[258] = 0x8DE687DB;
      m_lut_mod8_m_12[259] = 0x2499E4A0;
      m_lut_mod8_m_12[260] = 0x4C540928;
      m_lut_mod8_m_12[261] = 0xB74B095C;
      m_lut_mod8_m_12[262] = 0x0E890D38;
      m_lut_mod8_m_12[263] = 0xD36AF8BF;
      m_lut_mod8_m_12[264] = 0x81CDDE5C;
      m_lut_mod8_m_12[265] = 0x1C023EC2;
      m_lut_mod8_m_12[266] = 0xC6236003;
      m_lut_mod8_m_12[267] = 0x9CA2FC46;
      m_lut_mod8_m_12[268] = 0x91929206;
      m_lut_mod8_m_12[269] = 0x0BFADFA1;
      m_lut_mod8_m_12[270] = 0x458A40AC;
      m_lut_mod8_m_12[271] = 0x6F1DD439;
      m_lut_mod8_m_12[272] = 0xE4FF5688;
      m_lut_mod8_m_12[273] = 0x8CD26391;
      m_lut_mod8_m_12[274] = 0x259E244E;
      m_lut_mod8_m_12[275] = 0xCF71CDAA;
      m_lut_mod8_m_12[276] = 0xC6166371;
      m_lut_mod8_m_12[277] = 0x257E2EB5;
      m_lut_mod8_m_12[278] = 0xA1BA5563;
      m_lut_mod8_m_12[279] = 0x8A2A25FD;
      m_lut_mod8_m_12[280] = 0x889F8AD4;
      m_lut_mod8_m_12[281] = 0x000C3352;
      m_lut_mod8_m_12[282] = 0x0251FD81;
      m_lut_mod8_m_12[283] = 0x5661C44E;
      m_lut_mod8_m_12[284] = 0x836663E8;
      m_lut_mod8_m_12[285] = 0x9A5ABA2A;
      m_lut_mod8_m_12[286] = 0x3C933C9C;
      m_lut_mod8_m_12[287] = 0xC4872159;
      m_lut_mod8_m_12[288] = 0xB160B840;
      m_lut_mod8_m_12[289] = 0xFE6D5748;
      m_lut_mod8_m_12[290] = 0xEFFEC4AF;
      m_lut_mod8_m_12[291] = 0x3305282C;
      m_lut_mod8_m_12[292] = 0xEDFCEEFD;
      m_lut_mod8_m_12[293] = 0x69BA43D9;
      m_lut_mod8_m_12[294] = 0x752726B0;
      m_lut_mod8_m_12[295] = 0x8D72BDB3;
      m_lut_mod8_m_12[296] = 0xCD22F224;
      m_lut_mod8_m_12[297] = 0x2375B7FB;
      m_lut_mod8_m_12[298] = 0x59F058B5;
      m_lut_mod8_m_12[299] = 0xAD3151D2;
      m_lut_mod8_m_12[300] = 0xF6BB056D;
      m_lut_mod8_m_12[301] = 0xC711473F;
      m_lut_mod8_m_12[302] = 0x8867F1CF;
      m_lut_mod8_m_12[303] = 0x258DF197;
      m_lut_mod8_m_12[304] = 0xF4F1F62F;
      m_lut_mod8_m_12[305] = 0x624CAF2A;
      m_lut_mod8_m_12[306] = 0x32FC9B9D;
      m_lut_mod8_m_12[307] = 0xB40EADC4;
      m_lut_mod8_m_12[308] = 0xAABBC744;
      m_lut_mod8_m_12[309] = 0x35FD6E40;
      m_lut_mod8_m_12[310] = 0x40FD4067;
      m_lut_mod8_m_12[311] = 0xA6C7BD21;
      m_lut_mod8_m_12[312] = 0x3ED7C21A;
      m_lut_mod8_m_12[313] = 0x8C9577A6;
      m_lut_mod8_m_12[314] = 0x20CCAE6F;
      m_lut_mod8_m_12[315] = 0x1E149B5A;
      m_lut_mod8_m_12[316] = 0xDFE6DF59;
      m_lut_mod8_m_12[317] = 0x7E579A3F;
      m_lut_mod8_m_12[318] = 0xFA905CEA;
      m_lut_mod8_m_12[319] = 0xFF8A9D5D;
      m_lut_mod8_m_12[320] = 0x021098E4;
      m_lut_mod8_m_12[321] = 0x0E64048D;
      m_lut_mod8_m_12[322] = 0x6BEA6911;
      m_lut_mod8_m_12[323] = 0xBADC8834;
      m_lut_mod8_m_12[324] = 0x790C7F37;
      m_lut_mod8_m_12[325] = 0xB5E967D1;
      m_lut_mod8_m_12[326] = 0x47559B0F;
      m_lut_mod8_m_12[327] = 0x089C42E1;
      m_lut_mod8_m_12[328] = 0xC6EBC78B;
      m_lut_mod8_m_12[329] = 0x75A176CC;
      m_lut_mod8_m_12[330] = 0xBD4BE1C7;
      m_lut_mod8_m_12[331] = 0xC6F68D2A;
      m_lut_mod8_m_12[332] = 0x6589AD84;
      m_lut_mod8_m_12[333] = 0x18ECDD36;
      m_lut_mod8_m_12[334] = 0x72E771C3;
      m_lut_mod8_m_12[335] = 0xB12A64C7;
      m_lut_mod8_m_12[336] = 0x615ACC39;
      m_lut_mod8_m_12[337] = 0xC4DED314;
      m_lut_mod8_m_12[338] = 0x53BB4959;
      m_lut_mod8_m_12[339] = 0x5F4FA8D4;
      m_lut_mod8_m_12[340] = 0xF8DCF9F6;
      m_lut_mod8_m_12[341] = 0xC48138F0;
      m_lut_mod8_m_12[342] = 0xA51D52C9;
      m_lut_mod8_m_12[343] = 0xB7C139EF;
      m_lut_mod8_m_12[344] = 0x71677FD2;
      m_lut_mod8_m_12[345] = 0x4F3F3703;
      m_lut_mod8_m_12[346] = 0x4CD04FBE;
      m_lut_mod8_m_12[347] = 0x000A2AFB;
      m_lut_mod8_m_12[348] = 0x26817114;
      m_lut_mod8_m_12[349] = 0xFDA2C363;
      m_lut_mod8_m_12[350] = 0x34227C39;
      m_lut_mod8_m_12[351] = 0x49C7716F;
      m_lut_mod8_m_12[352] = 0xE1D1E124;
      m_lut_mod8_m_12[353] = 0xCF77D403;
      m_lut_mod8_m_12[354] = 0xE2C6EFE4;
      m_lut_mod8_m_12[355] = 0x8EBD2998;
      m_lut_mod8_m_12[356] = 0x16FE4AB2;
      m_lut_mod8_m_12[357] = 0x59B7EEB8;
      m_lut_mod8_m_12[358] = 0x55DD576C;
      m_lut_mod8_m_12[359] = 0x0BFCC608;
      m_lut_mod8_m_12[360] = 0xEEEDB663;
      m_lut_mod8_m_12[361] = 0xB626F3FA;
      m_lut_mod8_m_12[362] = 0x9C892399;
      m_lut_mod8_m_12[363] = 0x725E1BA2;
      m_lut_mod8_m_12[364] = 0xCAC6C852;
      m_lut_mod8_m_12[365] = 0xD36CE116;
      m_lut_mod8_m_12[366] = 0x2AAA2893;
      m_lut_mod8_m_12[367] = 0xC5391901;
      m_lut_mod8_m_12[368] = 0xBE551512;
      m_lut_mod8_m_12[369] = 0x622E8475;
      m_lut_mod8_m_12[370] = 0x7ECA7E1A;
      m_lut_mod8_m_12[371] = 0x17E7F31D;
      m_lut_mod8_m_12[372] = 0xA9360B4E;
      m_lut_mod8_m_12[373] = 0x8F5AE38D;
      m_lut_mod8_m_12[374] = 0xFB1016F9;
      m_lut_mod8_m_12[375] = 0x64D6C219;
      m_lut_mod8_m_12[376] = 0xD3CBD080;
      m_lut_mod8_m_12[377] = 0xD89A0DE5;
      m_lut_mod8_m_12[378] = 0x6D7195BE;
      m_lut_mod8_m_12[379] = 0xFC450976;
      m_lut_mod8_m_12[380] = 0xD9CC2072;
      m_lut_mod8_m_12[381] = 0x74A65DCE;
      m_lut_mod8_m_12[382] = 0x67C766C8;
      m_lut_mod8_m_12[383] = 0x1C111FEE;
      m_lut_mod8_m_12[384] = 0x73D52033;
      m_lut_mod8_m_12[385] = 0x77D0F160;
      m_lut_mod8_m_12[386] = 0x4888561D;
      m_lut_mod8_m_12[387] = 0x8D9A7985;
      m_lut_mod8_m_12[388] = 0x1C451D10;
      m_lut_mod8_m_12[389] = 0xE0B83239;
      m_lut_mod8_m_12[390] = 0xB792BEC3;
      m_lut_mod8_m_12[391] = 0x04CF1B9B;
      m_lut_mod8_m_12[392] = 0x6A546096;
      m_lut_mod8_m_12[393] = 0x9DEAE652;
      m_lut_mod8_m_12[394] = 0xA849AB58;
      m_lut_mod8_m_12[395] = 0x24332032;
      m_lut_mod8_m_12[396] = 0x340E9D1E;
      m_lut_mod8_m_12[397] = 0x4EACE117;
      m_lut_mod8_m_12[398] = 0x2F11637D;
      m_lut_mod8_m_12[399] = 0x9B12A03E;
      m_lut_mod8_m_12[400] = 0x054805C2;
      m_lut_mod8_m_12[401] = 0xEB4EDECA;
      m_lut_mod8_m_12[402] = 0xF04903EE;
      m_lut_mod8_m_12[403] = 0x3DB30BEC;
      m_lut_mod8_m_12[404] = 0x0DCD55F6;
      m_lut_mod8_m_12[405] = 0x8B623FE9;
      m_lut_mod8_m_12[406] = 0xB144B38A;
      m_lut_mod8_m_12[407] = 0x2FC5CCC1;
      m_lut_mod8_m_12[408] = 0xFC625A69;
      m_lut_mod8_m_12[409] = 0x0528D18E;
      m_lut_mod8_m_12[410] = 0x87BA3CDD;
      m_lut_mod8_m_12[411] = 0xA08BCAF3;
      m_lut_mod8_m_12[412] = 0x2E5F2CB4;
      m_lut_mod8_m_12[413] = 0xF755EBDF;
      m_lut_mod8_m_12[414] = 0x3825C499;
      m_lut_mod8_m_12[415] = 0x76373B75;
      m_lut_mod8_m_12[416] = 0xA5660A56;
      m_lut_mod8_m_12[417] = 0xB0FB5524;
      m_lut_mod8_m_12[418] = 0x9A539AFC;
      m_lut_mod8_m_12[419] = 0x33DEF9D4;
      m_lut_mod8_m_12[420] = 0xBBB9E744;
      m_lut_mod8_m_12[421] = 0x3C54C1F9;
      m_lut_mod8_m_12[422] = 0xE02309BD;
      m_lut_mod8_m_12[423] = 0xB6031348;
      m_lut_mod8_m_12[424] = 0x37523466;
      m_lut_mod8_m_12[425] = 0xFCA3072C;
      m_lut_mod8_m_12[426] = 0x7FFE79B4;
      m_lut_mod8_m_12[427] = 0x4F4B2B02;
      m_lut_mod8_m_12[428] = 0xC2FF3F36;
      m_lut_mod8_m_12[429] = 0xA6738C9F;
      m_lut_mod8_m_12[430] = 0x835E822E;
      m_lut_mod8_m_12[431] = 0x38281527;
      m_lut_mod8_m_12[432] = 0xA3EF544A;
      m_lut_mod8_m_12[433] = 0x4D63753C;
      m_lut_mod8_m_12[434] = 0xF4CDDBEB;
      m_lut_mod8_m_12[435] = 0xE1D0F97D;
      m_lut_mod8_m_12[436] = 0x09650A1B;
      m_lut_mod8_m_12[437] = 0x4D834910;
      m_lut_mod8_m_12[438] = 0x67A8CABA;
      m_lut_mod8_m_12[439] = 0x3E7C9FC7;
      m_lut_mod8_m_12[440] = 0xD611ED60;
      m_lut_mod8_m_12[441] = 0xF1A066AA;
      m_lut_mod8_m_12[442] = 0xBD69BC53;
      m_lut_mod8_m_12[443] = 0x89085B1B;
      m_lut_mod8_m_12[444] = 0xE434E967;
      m_lut_mod8_m_12[445] = 0x741F654B;
      m_lut_mod8_m_12[446] = 0x9354EE8B;
      m_lut_mod8_m_12[447] = 0xF75820C6;
      m_lut_mod8_m_12[448] = 0x106812C9;
      m_lut_mod8_m_12[449] = 0x4675A5E3;
      m_lut_mod8_m_12[450] = 0x20737797;
      m_lut_mod8_m_12[451] = 0x07008FB0;
      m_lut_mod8_m_12[452] = 0xB188D800;
      m_lut_mod8_m_12[453] = 0xE728BF11;
      m_lut_mod8_m_12[454] = 0xA464A481;
      m_lut_mod8_m_12[455] = 0x82FEB7E8;
      m_lut_mod8_m_12[456] = 0x2C582E10;
      m_lut_mod8_m_12[457] = 0x3F9B55D2;
      m_lut_mod8_m_12[458] = 0x3BFFB12B;
      m_lut_mod8_m_12[459] = 0xCCC14A0B;
      m_lut_mod8_m_12[460] = 0x3B7F3BBF;
      m_lut_mod8_m_12[461] = 0x5A6E90F6;
      m_lut_mod8_m_12[462] = 0xE81FB0E0;
      m_lut_mod8_m_12[463] = 0x4C84BF29;
      m_lut_mod8_m_12[464] = 0x192387A0;
      m_lut_mod8_m_12[465] = 0xDCB1D5DC;
      m_lut_mod8_m_12[466] = 0x8F738DF7;
      m_lut_mod8_m_12[467] = 0x9EE582FD;
      m_lut_mod8_m_12[468] = 0x6B83933D;
      m_lut_mod8_m_12[469] = 0x06E745A5;
      m_lut_mod8_m_12[470] = 0x5C66844B;
      m_lut_mod8_m_12[471] = 0xDA4993B0;
      m_lut_mod8_m_12[472] = 0x2272236D;
      m_lut_mod8_m_12[473] = 0x51987C05;
      m_lut_mod8_m_12[474] = 0xAFC40DCD;
      m_lut_mod8_m_12[475] = 0x75F8AF5E;
      m_lut_mod8_m_12[476] = 0x7EBAB2C0;
      m_lut_mod8_m_12[477] = 0xCA390C67;
      m_lut_mod8_m_12[478] = 0x967E9525;
      m_lut_mod8_m_12[479] = 0x95136E0E;
      m_lut_mod8_m_12[480] = 0x1CF5480C;
      m_lut_mod8_m_12[481] = 0xDDF43C58;
      m_lut_mod8_m_12[482] = 0x12221587;
      m_lut_mod8_m_12[483] = 0x63669E61;
      m_lut_mod8_m_12[484] = 0x47114744;
      m_lut_mod8_m_12[485] = 0x382E0C8E;
      m_lut_mod8_m_12[486] = 0xD8B2D6FC;
      m_lut_mod8_m_12[487] = 0xAEEBD6A3;
      m_lut_mod8_m_12[488] = 0x30FE230C;
      m_lut_mod8_m_12[489] = 0x731601B6;
      m_lut_mod8_m_12[490] = 0xF31DF10C;
      m_lut_mod8_m_12[491] = 0xFCA51E85;
      m_lut_mod8_m_12[492] = 0x5B2EF521;
      m_lut_mod8_m_12[493] = 0xE4882C2F;
      m_lut_mod8_m_12[494] = 0x75BB20E7;
      m_lut_mod8_m_12[495] = 0x75EE47DA;
      m_lut_mod8_m_12[496] = 0x5E1C5F96;
      m_lut_mod8_m_12[497] = 0x33D8E07D;
      m_lut_mod8_m_12[498] = 0x9F696BD1;
      m_lut_mod8_m_12[499] = 0x9797C6D4;
      m_lut_mod8_m_12[500] = 0x5767166C;
      m_lut_mod8_m_12[501] = 0x659ED80D;
      m_lut_mod8_m_12[502] = 0xEA10E9DE;
      m_lut_mod8_m_12[503] = 0xF753F276;
      m_lut_mod8_m_12[504] = 0x93423256;
      m_lut_mod8_m_12[505] = 0xAF0C1CB6;
      m_lut_mod8_m_12[506] = 0xDD107F47;
      m_lut_mod8_m_12[507] = 0x4E772D17;
      m_lut_mod8_m_12[508] = 0x750B76E0;
      m_lut_mod8_m_12[509] = 0x2FC3D568;
      m_lut_mod8_m_12[510] = 0x5705ACA6;
      m_lut_mod8_m_12[511] = 0xDC13F64D;
      m_lut_mod8_m_12[512] = 0xFFCC49CC;
      m_lut_mod8_m_12[513] = 0x5E07B2C0;
      m_lut_mod8_m_12[514] = 0xC107C0A8;
      m_lut_mod8_m_12[515] = 0xEB48C763;
      m_lut_mod8_m_12[516] = 0xD4998F7B;
      m_lut_mod8_m_12[517] = 0x96700CC1;
      m_lut_mod8_m_12[518] = 0xBA894A27;
      m_lut_mod8_m_12[519] = 0x58FFF4AC;
      m_lut_mod8_m_12[520] = 0x6C066E32;
      m_lut_mod8_m_12[521] = 0x2435399B;
      m_lut_mod8_m_12[522] = 0x10DE118B;
      m_lut_mod8_m_12[523] = 0xE56FE63A;
      m_lut_mod8_m_12[524] = 0x98557CAC;
      m_lut_mod8_m_12[525] = 0x488F6B7B;
      m_lut_mod8_m_12[526] = 0xD80AD87A;
      m_lut_mod8_m_12[527] = 0xE0BE2B90;
      m_lut_mod8_m_12[528] = 0xCCCF3C75;
      m_lut_mod8_m_12[529] = 0xE747B804;
      m_lut_mod8_m_12[530] = 0xAE679871;
      m_lut_mod8_m_12[531] = 0x0F2C1E99;
      m_lut_mod8_m_12[532] = 0x5231504F;
      m_lut_mod8_m_12[533] = 0x951577A7;
      m_lut_mod8_m_12[534] = 0x0888A285;
      m_lut_mod8_m_12[535] = 0x945852FF;
      m_lut_mod8_m_12[536] = 0x8CBBAEFA;
      m_lut_mod8_m_12[537] = 0x1F5C814E;
      m_lut_mod8_m_12[538] = 0xE63DE607;
      m_lut_mod8_m_12[539] = 0x519E65AC;
      m_lut_mod8_m_12[540] = 0x8B148158;
      m_lut_mod8_m_12[541] = 0xDE3BA873;
      m_lut_mod8_m_12[542] = 0xC9FEAD11;
      m_lut_mod8_m_12[543] = 0x19A4C722;
      m_lut_mod8_m_12[544] = 0x4B3C489D;
      m_lut_mod8_m_12[545] = 0x9EE39B54;
      m_lut_mod8_m_12[546] = 0x4F531FA8;
      m_lut_mod8_m_12[547] = 0xAD244288;
      m_lut_mod8_m_12[548] = 0xEB229B9A;
      m_lut_mod8_m_12[549] = 0x09D458F5;
      m_lut_mod8_m_12[550] = 0xFF30FED5;
      m_lut_mod8_m_12[551] = 0x5A68895F;
      m_lut_mod8_m_12[552] = 0x4378462F;
      m_lut_mod8_m_12[553] = 0x95BF98EA;
      m_lut_mod8_m_12[554] = 0x6155F2B1;
      m_lut_mod8_m_12[555] = 0x223DADEF;
      m_lut_mod8_m_12[556] = 0x602B61EB;
      m_lut_mod8_m_12[557] = 0x82F8AE41;
      m_lut_mod8_m_12[558] = 0x873FD8DF;
      m_lut_mod8_m_12[559] = 0xE6A07211;
      m_lut_mod8_m_12[560] = 0x4389C43A;
      m_lut_mod8_m_12[561] = 0x324D3238;
      m_lut_mod8_m_12[562] = 0xD427D7A3;
      m_lut_mod8_m_12[563] = 0x4673BC4A;
      m_lut_mod8_m_12[564] = 0x04A3FB02;
      m_lut_mod8_m_12[565] = 0xACC3889D;
      m_lut_mod8_m_12[566] = 0x06CCC7D1;
      m_lut_mod8_m_12[567] = 0x34B57454;
      m_lut_mod8_m_12[568] = 0x79267939;
      m_lut_mod8_m_12[569] = 0x890E42B2;
      m_lut_mod8_m_12[570] = 0xC0E465F2;
      m_lut_mod8_m_12[571] = 0xDFDC6266;
      m_lut_mod8_m_12[572] = 0x2410F15A;
      m_lut_mod8_m_12[573] = 0x24C5EB83;
      m_lut_mod8_m_12[574] = 0xCD2ACF71;
      m_lut_mod8_m_12[575] = 0x4D8550B9;
      m_lut_mod8_m_12[576] = 0xAD95F04C;
      m_lut_mod8_m_12[577] = 0x23996B10;
      m_lut_mod8_m_12[578] = 0xFDDCD128;
      m_lut_mod8_m_12[579] = 0x5063B64D;
      m_lut_mod8_m_12[580] = 0xAAEDA9B9;
      m_lut_mod8_m_12[581] = 0x51944F57;
      m_lut_mod8_m_12[582] = 0x69D26EBC;
      m_lut_mod8_m_12[583] = 0x508681EB;
      m_lut_mod8_m_12[584] = 0xDF00E7A3;
      m_lut_mod8_m_12[585] = 0x4013299A;
      m_lut_mod8_m_12[586] = 0x1EE11FF1;
      m_lut_mod8_m_12[587] = 0x951F5D5C;
      m_lut_mod8_m_12[588] = 0xEA4E4D61;
      m_lut_mod8_m_12[589] = 0x1AE57B67;
      m_lut_mod8_m_12[590] = 0x9A45E448;
      m_lut_mod8_m_12[591] = 0x46EB6FF6;
      m_lut_mod8_m_12[592] = 0xB3E0B16B;
      m_lut_mod8_m_12[593] = 0x5A62A3A4;
      m_lut_mod8_m_12[594] = 0x2E09D391;
      m_lut_mod8_m_12[595] = 0x69FA919C;
      m_lut_mod8_m_12[596] = 0xB899D2C3;
      m_lut_mod8_m_12[597] = 0x569BF021;
      m_lut_mod8_m_12[598] = 0x07EC0723;
      m_lut_mod8_m_12[599] = 0x9EE9B1AF;
      m_lut_mod8_m_12[600] = 0x22228A16;
      m_lut_mod8_m_12[601] = 0x51614BFE;
      m_lut_mod8_m_12[602] = 0x32EEBBE8;
      m_lut_mod8_m_12[603] = 0x7D72053B;
      m_lut_mod8_m_12[604] = 0x98F7981D;
      m_lut_mod8_m_12[605] = 0x467996B1;
      m_lut_mod8_m_12[606] = 0xE66514E6;
      m_lut_mod8_m_12[607] = 0x227EA105;
      m_lut_mod8_m_12[608] = 0x10328D63;
      m_lut_mod8_m_12[609] = 0x6D029AEC;
      m_lut_mod8_m_12[610] = 0x2CFB2E55;
      m_lut_mod8_m_12[611] = 0x82F284BA;
      m_lut_mod8_m_12[612] = 0x65F9373B;
      m_lut_mod8_m_12[613] = 0x681D5B89;
      m_lut_mod8_m_12[614] = 0x55778E88;
      m_lut_mod8_m_12[615] = 0x6BFADC80;
      m_lut_mod8_m_12[616] = 0x81FA80CF;
      m_lut_mod8_m_12[617] = 0x4D8F7A42;
      m_lut_mod8_m_12[618] = 0xA1BEA9CB;
      m_lut_mod8_m_12[619] = 0x1B02B172;
      m_lut_mod8_m_12[620] = 0x77ABB803;
      m_lut_mod8_m_12[621] = 0x7B8A4357;
      m_lut_mod8_m_12[622] = 0x35F63687;
      m_lut_mod8_m_12[623] = 0x89046849;
      m_lut_mod8_m_12[624] = 0x7DAF8435;
      m_lut_mod8_m_12[625] = 0x192AEF4C;
      m_lut_mod8_m_12[626] = 0x41995CDE;
      m_lut_mod8_m_12[627] = 0x3C2936B5;
      m_lut_mod8_m_12[628] = 0xBFCDBEB2;
      m_lut_mod8_m_12[629] = 0xFCAF347E;
      m_lut_mod8_m_12[630] = 0xB9E81AC5;
      m_lut_mod8_m_12[631] = 0x6A3505B7;
      m_lut_mod8_m_12[632] = 0x63456A55;
      m_lut_mod8_m_12[633] = 0x2C59A962;
      m_lut_mod8_m_12[634] = 0x0BC108FA;
      m_lut_mod8_m_12[635] = 0x38242675;
      m_lut_mod8_m_12[636] = 0x3A743918;
      m_lut_mod8_m_12[637] = 0x2056FF3B;
      m_lut_mod8_m_12[638] = 0x260069BE;
      m_lut_mod8_m_12[639] = 0x2AA1EF0E;
      m_lut_mod8_m_12[640] = 0xA6C0A660;
      m_lut_mod8_m_12[641] = 0xF759D88D;
      m_lut_mod8_m_12[642] = 0xFE33A7E8;
      m_lut_mod8_m_12[643] = 0x534915C0;
      m_lut_mod8_m_12[644] = 0x04DC5F35;
      m_lut_mod8_m_12[645] = 0x3AD170D9;
      m_lut_mod8_m_12[646] = 0x12CC1028;
      m_lut_mod8_m_12[647] = 0x33D2CA86;
      m_lut_mod8_m_12[648] = 0xF218FE6F;
      m_lut_mod8_m_12[649] = 0x6BD2CFA2;
      m_lut_mod8_m_12[650] = 0x8EAB361E;
      m_lut_mod8_m_12[651] = 0x113885C3;
      m_lut_mod8_m_12[652] = 0x8DD78F16;
      m_lut_mod8_m_12[653] = 0xEB42ED98;
      m_lut_mod8_m_12[654] = 0x365F609F;
      m_lut_mod8_m_12[655] = 0x18CD2559;
      m_lut_mod8_m_12[656] = 0xAC770095;
      m_lut_mod8_m_12[657] = 0x01481A14;
      m_lut_mod8_m_12[658] = 0x39DB395E;
      m_lut_mod8_m_12[659] = 0x2FC9FF93;
      m_lut_mod8_m_12[660] = 0xB5C34342;
      m_lut_mod8_m_12[661] = 0x52AEDFD5;
      m_lut_mod8_m_12[662] = 0xE932037E;
      m_lut_mod8_m_12[663] = 0x07B05C78;
      m_lut_mod8_m_12[664] = 0x94DA97C4;
      m_lut_mod8_m_12[665] = 0xE0B4016B;
      m_lut_mod8_m_12[666] = 0x7184DDB2;
      m_lut_mod8_m_12[667] = 0x21B1352E;
      m_lut_mod8_m_12[668] = 0xCBEE35F5;
      m_lut_mod8_m_12[669] = 0x17C0C3AF;
      m_lut_mod8_m_12[670] = 0x20D6218C;
      m_lut_mod8_m_12[671] = 0x243F1360;
      m_lut_mod8_m_12[672] = 0xC2B59873;
      m_lut_mod8_m_12[673] = 0x89BDA628;
      m_lut_mod8_m_12[674] = 0xA77692B2;
      m_lut_mod8_m_12[675] = 0xBE9F51A9;
      m_lut_mod8_m_12[676] = 0xF1B9F3ED;
      m_lut_mod8_m_12[677] = 0x890271E0;
      m_lut_mod8_m_12[678] = 0x06F20683;
      m_lut_mod8_m_12[679] = 0xFAA24CD3;
      m_lut_mod8_m_12[680] = 0x85AAA439;
      m_lut_mod8_m_12[681] = 0xAEEFCE7E;
      m_lut_mod8_m_12[682] = 0x45B545A5;
      m_lut_mod8_m_12[683] = 0x4D8963EB;
      m_lut_mod8_m_12[684] = 0x856E255E;
      m_lut_mod8_m_12[685] = 0xB0C1B65F;
      m_lut_mod8_m_12[686] = 0xC0EFA7D2;
      m_lut_mod8_m_12[687] = 0xA8178812;
      m_lut_mod8_m_12[688] = 0xE8B4EB3F;
      m_lut_mod8_m_12[689] = 0x82F49D13;
      m_lut_mod8_m_12[690] = 0x4129BBAE;
      m_lut_mod8_m_12[691] = 0xC3DE5CA4;
      m_lut_mod8_m_12[692] = 0xE2339159;
      m_lut_mod8_m_12[693] = 0xB86717C5;
      m_lut_mod8_m_12[694] = 0x5CB85D77;
      m_lut_mod8_m_12[695] = 0x467F8F18;
      m_lut_mod8_m_12[696] = 0x4D02E229;
      m_lut_mod8_m_12[697] = 0xFB4586C6;
      m_lut_mod8_m_12[698] = 0x6844F872;
      m_lut_mod8_m_12[699] = 0x938EE2DF;
      m_lut_mod8_m_12[700] = 0xC3A3C249;
      m_lut_mod8_m_12[701] = 0x9EEFA806;
      m_lut_mod8_m_12[702] = 0x89457CD9;
      m_lut_mod8_m_12[703] = 0x885A6C3D;
      m_lut_mod8_m_12[704] = 0x4A98CEF9;
      m_lut_mod8_m_12[705] = 0x83FE7D08;
      m_lut_mod8_m_12[706] = 0x77AF7401;
      m_lut_mod8_m_12[707] = 0x5A64BA0D;
      m_lut_mod8_m_12[708] = 0x0AD95F04;
      m_lut_mod8_m_12[709] = 0xC23996B1;
      m_lut_mod8_m_12[710] = 0x0FDDCD12;
      m_lut_mod8_m_12[711] = 0x85063B64;
      m_lut_mod8_m_12[712] = 0xDAAEDA9B;
      m_lut_mod8_m_12[713] = 0x951944F5;
      m_lut_mod8_m_12[714] = 0xCE9EC1F4;
      m_lut_mod8_m_12[715] = 0xB1267C4A;
      m_lut_mod8_m_12[716] = 0x2D01FB99;
      m_lut_mod8_m_12[717] = 0x9576A4B3;
      m_lut_mod8_m_12[718] = 0x6EA26CD3;
      m_lut_mod8_m_12[719] = 0x519256FE;
      m_lut_mod8_m_12[720] = 0x128FEC0A;
      m_lut_mod8_m_12[721] = 0xB30E2274;
      m_lut_mod8_m_12[722] = 0x1B331F44;
      m_lut_mod8_m_12[723] = 0xD2D5D151;
      m_lut_mod8_m_12[724] = 0xE499E4E6;
      m_lut_mod8_m_12[725] = 0x24390AC9;
      m_lut_mod8_m_12[726] = 0xD6C872FA;
      m_lut_mod8_m_12[727] = 0xC011C88F;
      m_lut_mod8_m_12[728] = 0x39EF29CF;
      m_lut_mod8_m_12[729] = 0xC2A54E86;
      m_lut_mod8_m_12[730] = 0x509552AE;
      m_lut_mod8_m_12[731] = 0xE0B218C2;
      m_lut_mod8_m_12[732] = 0x55545127;
      m_lut_mod8_m_12[733] = 0x8A723203;
      m_lut_mod8_m_12[734] = 0x7CAA2A24;
      m_lut_mod8_m_12[735] = 0xC45D08EA;
      m_lut_mod8_m_12[736] = 0xFD94FC34;
      m_lut_mod8_m_12[737] = 0x2FCFE63A;
      m_lut_mod8_m_12[738] = 0x9113CFD7;
      m_lut_mod8_m_12[739] = 0xF96DD8F8;
      m_lut_mod8_m_12[740] = 0x5E761CAF;
      m_lut_mod8_m_12[741] = 0xD42D973D;
      m_lut_mod8_m_12[742] = 0x49984A7C;
      m_lut_mod8_m_12[743] = 0xEB44F431;
      m_lut_mod8_m_12[744] = 0x9D389650;
      m_lut_mod8_m_12[745] = 0xC1F6029A;
      m_lut_mod8_m_12[746] = 0xD4017584;
      m_lut_mod8_m_12[747] = 0xFFC46227;
      m_lut_mod8_m_12[748] = 0xD683D542;
      m_lut_mod8_m_12[749] = 0x33D4D32F;
      m_lut_mod8_m_12[750] = 0x597F08A0;
      m_lut_mod8_m_12[751] = 0xB2E9E861;
      m_lut_mod8_m_12[752] = 0xF6DD430F;
      m_lut_mod8_m_12[753] = 0xEFB4FDF0;
      m_lut_mod8_m_12[754] = 0x628F630A;
      m_lut_mod8_m_12[755] = 0xF75FC124;
      m_lut_mod8_m_12[756] = 0xDAE32B7D;
      m_lut_mod8_m_12[757] = 0xF88A12ED;
      m_lut_mod8_m_12[758] = 0xB39840E4;
      m_lut_mod8_m_12[759] = 0xE94CBB9C;
      m_lut_mod8_m_12[760] = 0xCF8ECD90;
      m_lut_mod8_m_12[761] = 0x38223FDC;
      m_lut_mod8_m_12[762] = 0x1EA4B58D;
      m_lut_mod8_m_12[763] = 0x8B95F816;
      m_lut_mod8_m_12[764] = 0x9144766F;
      m_lut_mod8_m_12[765] = 0xF93C244B;
      m_lut_mod8_m_12[766] = 0x7B827BD8;
      m_lut_mod8_m_12[767] = 0xFCA92DD7;
      m_lut_mod8_m_12[768] = 0xE7AA4066;
      m_lut_mod8_m_12[769] = 0xEFA1E2C0;
      m_lut_mod8_m_12[770] = 0x9110AC3B;
      m_lut_mod8_m_12[771] = 0x1B34F30A;
      m_lut_mod8_m_12[772] = 0x388A3A21;
      m_lut_mod8_m_12[773] = 0xC1706472;
      m_lut_mod8_m_12[774] = 0x23EDDE96;
      m_lut_mod8_m_12[775] = 0x9CBE083B;
      m_lut_mod8_m_12[776] = 0xB3CC9AB0;
      m_lut_mod8_m_12[777] = 0x0B446CDD;
      m_lut_mod8_m_12[778] = 0x8C868C69;
      m_lut_mod8_m_12[779] = 0x05FB7679;
      m_lut_mod8_m_12[780] = 0xA071FD4B;
      m_lut_mod8_m_12[781] = 0xD6DDF2B7;
      m_lut_mod8_m_12[782] = 0xF689995B;
      m_lut_mod8_m_12[783] = 0x0DBC2AB1;
      m_lut_mod8_m_12[784] = 0x218722F3;
      m_lut_mod8_m_12[785] = 0xCA868881;
      m_lut_mod8_m_12[786] = 0x643663BB;
      m_lut_mod8_m_12[787] = 0xA5C2184C;
      m_lut_mod8_m_12[788] = 0xD455AFD0;
      m_lut_mod8_m_12[789] = 0x1DCCB566;
      m_lut_mod8_m_12[790] = 0x958B94BB;
      m_lut_mod8_m_12[791] = 0x0E0D9A8A;
      m_lut_mod8_m_12[792] = 0x681D3A3C;
      m_lut_mod8_m_12[793] = 0x9D59C22E;
      m_lut_mod8_m_12[794] = 0x5E22C6FB;
      m_lut_mod8_m_12[795] = 0x3625407C;
      m_lut_mod8_m_12[796] = 0x0A900B85;
      m_lut_mod8_m_12[797] = 0xD69DBD94;
      m_lut_mod8_m_12[798] = 0xAC5AA4CC;
      m_lut_mod8_m_12[799] = 0xEE4628D5;
      m_lut_mod8_m_12[800] = 0x7CFEF070;
      m_lut_mod8_m_12[801] = 0x2655DFAB;
      m_lut_mod8_m_12[802] = 0xBE9CBDCD;
      m_lut_mod8_m_12[803] = 0x1216AF9F;
      m_lut_mod8_m_12[804] = 0x2FC68711;
      m_lut_mod8_m_12[805] = 0xA425D259;
      m_lut_mod8_m_12[806] = 0x39BBF39B;
      m_lut_mod8_m_12[807] = 0x20AD99C7;
      m_lut_mod8_m_12[808] = 0x139D1357;
      m_lut_mod8_m_12[809] = 0xDD6B5167;
      m_lut_mod8_m_12[810] = 0xEB8119E1;
      m_lut_mod8_m_12[811] = 0xD73A38A2;
      m_lut_mod8_m_12[812] = 0x1B67C510;
      m_lut_mod8_m_12[813] = 0x30DD0610;
      m_lut_mod8_m_12[814] = 0xA791A51F;
      m_lut_mod8_m_12[815] = 0x19E0436C;
      m_lut_mod8_m_12[816] = 0x3790341F;
      m_lut_mod8_m_12[817] = 0xD512669C;
      m_lut_mod8_m_12[818] = 0x2D5521CD;
      m_lut_mod8_m_12[819] = 0x777E73F2;
      m_lut_mod8_m_12[820] = 0x2DAA2D2A;
      m_lut_mod8_m_12[821] = 0x6C4B1F5B;
      m_lut_mod8_m_12[822] = 0xF3D7AAEF;
      m_lut_mod8_m_12[823] = 0xA60D8C67;
      m_lut_mod8_m_12[824] = 0x0F891746;
      m_lut_mod8_m_12[825] = 0x670EEC25;
      m_lut_mod8_m_12[826] = 0x99A69B62;
      m_lut_mod8_m_12[827] = 0xA8C00D50;
      m_lut_mod8_m_12[828] = 0x704B8932;
      m_lut_mod8_m_12[829] = 0xEC6E76EB;
      m_lut_mod8_m_12[830] = 0x4ACC14AD;
      m_lut_mod8_m_12[831] = 0x61F6AA49;
      m_lut_mod8_m_12[832] = 0x34A735F8;
      m_lut_mod8_m_12[833] = 0x67BDF3A8;
      m_lut_mod8_m_12[834] = 0xB40C17C2;
      m_lut_mod8_m_12[835] = 0x9F719C10;
      m_lut_mod8_m_12[836] = 0x68102226;
      m_lut_mod8_m_12[837] = 0x7186359E;
      m_lut_mod8_m_12[838] = 0x80AB83B0;
      m_lut_mod8_m_12[839] = 0xA336E1A3;
      m_lut_mod8_m_12[840] = 0xB8274E45;
      m_lut_mod8_m_12[841] = 0xA7EA4672;
      m_lut_mod8_m_12[842] = 0xE2674B0D;
      m_lut_mod8_m_12[843] = 0x5A6FC084;
      m_lut_mod8_m_12[844] = 0x1FB01C8E;
      m_lut_mod8_m_12[845] = 0x7BA6C6BD;
      m_lut_mod8_m_12[846] = 0x7C60D0B5;
      m_lut_mod8_m_12[847] = 0xD4F5AC89;
      m_lut_mod8_m_12[848] = 0xC0BB7D86;
      m_lut_mod8_m_12[849] = 0x4A1F5F53;
      m_lut_mod8_m_12[850] = 0xABBCAAC6;
      m_lut_mod8_m_12[851] = 0xBF2DD4B6;
      m_lut_mod8_m_12[852] = 0xFFFCF368;
      m_lut_mod8_m_12[853] = 0x9E965605;
      m_lut_mod8_m_12[854] = 0x85FE7E6D;
      m_lut_mod8_m_12[855] = 0x4CE7193F;
      m_lut_mod8_m_12[856] = 0x06BD045C;
      m_lut_mod8_m_12[857] = 0x70502A4E;
      m_lut_mod8_m_12[858] = 0x3BBB6D98;
      m_lut_mod8_m_12[859] = 0xED89BCFE;
      m_lut_mod8_m_12[860] = 0xA72248E6;
      m_lut_mod8_m_12[861] = 0x5C9786E8;
      m_lut_mod8_m_12[862] = 0xB2B1B214;
      m_lut_mod8_m_12[863] = 0xB4DB3845;
      m_lut_mod8_m_12[864] = 0x888A2859;
      m_lut_mod8_m_12[865] = 0x45852FF8;
      m_lut_mod8_m_12[866] = 0xCBBAEFA1;
      m_lut_mod8_m_12[867] = 0xF5C814EE;
      m_lut_mod8_m_12[868] = 0x63DE6075;
      m_lut_mod8_m_12[869] = 0x19E65AC5;
      m_lut_mod8_m_12[870] = 0x4CCDB6A9;
      m_lut_mod8_m_12[871] = 0x369AC503;
      m_lut_mod8_m_12[872] = 0xE966D92A;
      m_lut_mod8_m_12[873] = 0xE5B88B39;
      m_lut_mod8_m_12[874] = 0xD7D2D63D;
      m_lut_mod8_m_12[875] = 0xDD6D48CE;
      m_lut_mod8_m_12[876] = 0xCF519574;
      m_lut_mod8_m_12[877] = 0x7CF93F8F;
      m_lut_mod8_m_12[878] = 0xAC23DAC1;
      m_lut_mod8_m_12[879] = 0xE340CD55;
      m_lut_mod8_m_12[880] = 0x7AD378A7;
      m_lut_mod8_m_12[881] = 0x1210B636;
      m_lut_mod8_m_12[882] = 0x0B160B84;
      m_lut_mod8_m_12[883] = 0x0FE6D574;
      m_lut_mod8_m_12[884] = 0x8EFFEC4A;
      m_lut_mod8_m_12[885] = 0xF3305282;
      m_lut_mod8_m_12[886] = 0xCEDFCEEF;
      m_lut_mod8_m_12[887] = 0xD69BA43D;
      m_lut_mod8_m_12[888] = 0x073D5203;
      m_lut_mod8_m_12[889] = 0x377D0F16;
      m_lut_mod8_m_12[890] = 0x04888561;
      m_lut_mod8_m_12[891] = 0xD8D9A798;
      m_lut_mod8_m_12[892] = 0x51C451D1;
      m_lut_mod8_m_12[893] = 0x0E0B8323;
      m_lut_mod8_m_12[894] = 0xC37ACCF3;
      m_lut_mod8_m_12[895] = 0x4462E5ED;
      m_lut_mod8_m_12[896] = 0x2654B3EA;
      m_lut_mod8_m_12[897] = 0xC8A9384F;
      m_lut_mod8_m_12[898] = 0xE5C8E799;
      m_lut_mod8_m_12[899] = 0xCA809128;
      m_lut_mod8_m_12[900] = 0x40E6EF2E;
      m_lut_mod8_m_12[901] = 0x0E011F61;
      m_lut_mod8_m_12[902] = 0x6311B001;
      m_lut_mod8_m_12[903] = 0xCE517E23;
      m_lut_mod8_m_12[904] = 0x48C94903;
      m_lut_mod8_m_12[905] = 0x05FD6FD0;
      m_lut_mod8_m_12[906] = 0x84A171DE;
      m_lut_mod8_m_12[907] = 0x7D1EF59A;
      m_lut_mod8_m_12[908] = 0x41CD868A;
      m_lut_mod8_m_12[909] = 0xDE21E1F4;
      m_lut_mod8_m_12[910] = 0xFCC5FF4B;
      m_lut_mod8_m_12[911] = 0xC1767DDB;
      m_lut_mod8_m_12[912] = 0x58B05C20;
      m_lut_mod8_m_12[913] = 0x7F36ABA4;
      m_lut_mod8_m_12[914] = 0x77FF6257;
      m_lut_mod8_m_12[915] = 0x99829416;
      m_lut_mod8_m_12[916] = 0x76FE777E;
      m_lut_mod8_m_12[917] = 0xB4DD21EC;
      m_lut_mod8_m_12[918] = 0x9CF7C2D0;
      m_lut_mod8_m_12[919] = 0x0C29415F;
      m_lut_mod8_m_12[920] = 0x552354DC;
      m_lut_mod8_m_12[921] = 0x89F20BC1;
      m_lut_mod8_m_12[922] = 0xC2F2C136;
      m_lut_mod8_m_12[923] = 0x705633E7;
      m_lut_mod8_m_12[924] = 0x1F6BE10D;
      m_lut_mod8_m_12[925] = 0x464ABBD3;
      m_lut_mod8_m_12[926] = 0x10665737;
      m_lut_mod8_m_12[927] = 0x8F0A4DAD;
      m_lut_mod8_m_12[928] = 0x6FF36FAC;
      m_lut_mod8_m_12[929] = 0xBF2BCD1F;
      m_lut_mod8_m_12[930] = 0xDB2C7FFD;
      m_lut_mod8_m_12[931] = 0x35555128;
      m_lut_mod8_m_12[932] = 0x32BA61BC;
      m_lut_mod8_m_12[933] = 0x9F7AD27A;
      m_lut_mod8_m_12[934] = 0xDBFFD9E4;
      m_lut_mod8_m_12[935] = 0x7BA0DF14;
      m_lut_mod8_m_12[936] = 0xD707267A;
      m_lut_mod8_m_12[937] = 0x0DCE8B4A;
      m_lut_mod8_m_12[938] = 0xB8CD0897;
      m_lut_mod8_m_12[939] = 0xB4932760;
      m_lut_mod8_m_12[940] = 0x44E446DA;
      m_lut_mod8_m_12[941] = 0xA330F80A;
      m_lut_mod8_m_12[942] = 0x1340B88A;
      m_lut_mod8_m_12[943] = 0x7ED161B1;
      m_lut_mod8_m_12[944] = 0x9A113E1C;
      m_lut_mod8_m_12[945] = 0xA4E3B8B7;
      m_lut_mod8_m_12[946] = 0xF0E8F092;
      m_lut_mod8_m_12[947] = 0x67BBEA01;
      m_lut_mod8_m_12[948] = 0x90DC9B57;
      m_lut_mod8_m_12[949] = 0x34B29B3D;
      m_lut_mod8_m_12[950] = 0xDF543DF7;
      m_lut_mod8_m_12[951] = 0xA21BFEDB;
      m_lut_mod8_m_12[952] = 0x5DE95E08;
      m_lut_mod8_m_12[953] = 0xA8C614F9;
      m_lut_mod8_m_12[954] = 0x549B05A7;
      m_lut_mod8_m_12[955] = 0x47AD71C6;
      m_lut_mod8_m_12[956] = 0xFD880B7C;
      m_lut_mod8_m_12[957] = 0xB26B610C;
      m_lut_mod8_m_12[958] = 0xE9E5E840;
      m_lut_mod8_m_12[959] = 0x6C4D06F2;
      m_lut_mod8_m_12[960] = 0x39EA9019;
      m_lut_mod8_m_12[961] = 0xBBE878B0;
      m_lut_mod8_m_12[962] = 0x24442B0E;
      m_lut_mod8_m_12[963] = 0xC6CD3CC2;
      m_lut_mod8_m_12[964] = 0x8E228E88;
      m_lut_mod8_m_12[965] = 0x705C191C;
      m_lut_mod8_m_12[966] = 0xFDAD0EE9;
      m_lut_mod8_m_12[967] = 0xC8F7924B;
      m_lut_mod8_m_12[968] = 0x06981D85;
      m_lut_mod8_m_12[969] = 0xD6BDA315;
      m_lut_mod8_m_12[970] = 0x3A2E38C0;
      m_lut_mod8_m_12[971] = 0xB4D70B17;
      m_lut_mod8_m_12[972] = 0x7E312D34;
      m_lut_mod8_m_12[973] = 0x829468C7;
      m_lut_mod8_m_12[974] = 0x43DD1E6E;
      m_lut_mod8_m_12[975] = 0xD045E579;
      m_lut_mod8_m_12[976] = 0x972F965A;
      m_lut_mod8_m_12[977] = 0x7BAAF5EF;
      m_lut_mod8_m_12[978] = 0xBA76B3C4;
      m_lut_mod8_m_12[979] = 0xF18B823C;
      m_lut_mod8_m_12[980] = 0x610128E5;
      m_lut_mod8_m_12[981] = 0xC0357AAE;
      m_lut_mod8_m_12[982] = 0x23232012;
      m_lut_mod8_m_12[983] = 0xBF21E7E4;
      m_lut_mod8_m_12[984] = 0xB65DEA43;
      m_lut_mod8_m_12[985] = 0xC910585E;
      m_lut_mod8_m_12[986] = 0xEB7641CE;
      m_lut_mod8_m_12[987] = 0xEBDC8FB4;
      m_lut_mod8_m_12[988] = 0xBC38BF2C;
      m_lut_mod8_m_12[989] = 0x67B1C0FA;
      m_lut_mod8_m_12[990] = 0x721A74B3;
      m_lut_mod8_m_12[991] = 0xBA0FB2A5;
      m_lut_mod8_m_12[992] = 0xC9AA7745;
      m_lut_mod8_m_12[993] = 0xFBAC1063;
      m_lut_mod8_m_12[994] = 0x08340964;
      m_lut_mod8_m_12[995] = 0xA33AD2F1;
      m_lut_mod8_m_12[996] = 0xF186576E;
      m_lut_mod8_m_12[997] = 0xF06C4829;
      m_lut_mod8_m_12[998] = 0x8CEF74AE;
      m_lut_mod8_m_12[999] = 0xFD54560F;
      m_lut_mod8_m_12[1000] = 0xA535A7FE;
      m_lut_mod8_m_12[1001] = 0x6C472C09;
      m_lut_mod8_m_12[1002] = 0x35C1C99E;
      m_lut_mod8_m_12[1003] = 0x8373A2D2;
      m_lut_mod8_m_12[1004] = 0xAE334225;
      m_lut_mod8_m_12[1005] = 0xED24C9D8;
      m_lut_mod8_m_12[1006] = 0x113911B6;
      m_lut_mod8_m_12[1007] = 0xA8CC3E02;
      m_lut_mod8_m_12[1008] = 0xE9D0E460;
      m_lut_mod8_m_12[1009] = 0x815BFCEC;
      m_lut_mod8_m_12[1010] = 0x9801A6F8;
      m_lut_mod8_m_12[1011] = 0xAA87BC3A;
      m_lut_mod8_m_12[1012] = 0x9B029983;
      m_lut_mod8_m_12[1013] = 0xDD676235;
      m_lut_mod8_m_12[1014] = 0x2D977A90;
      m_lut_mod8_m_12[1015] = 0xF2441617;
      m_lut_mod8_m_12[1016] = 0xBADD9073;
      m_lut_mod8_m_12[1017] = 0xBAF723ED;
      m_lut_mod8_m_12[1018] = 0x2F0E2FCB;
      m_lut_mod8_m_12[1019] = 0x19EC703E;
      m_lut_mod8_m_12[1020] = 0xAE0B594D;
      m_lut_mod8_m_12[1021] = 0xB827EC9B;
      m_lut_mod8_m_12[1022] = 0xFF989398;
      m_lut_mod8_m_12[1023] = 0xBC0F6581;
      m_lut_mod8_m_12[1024] = 0x820F8151;
      m_lut_mod8_m_12[1025] = 0xD6918EC6;
      m_lut_mod8_m_12[1026] = 0x6A4CC7BD;
      m_lut_mod8_m_12[1027] = 0xCB380660;
      m_lut_mod8_m_12[1028] = 0xDD44A513;
      m_lut_mod8_m_12[1029] = 0xAC7FFA56;
      m_lut_mod8_m_12[1030] = 0x36033719;
      m_lut_mod8_m_12[1031] = 0x121A9CCD;
      m_lut_mod8_m_12[1032] = 0x66679E3A;
      m_lut_mod8_m_12[1033] = 0xF3A3DC02;
      m_lut_mod8_m_12[1034] = 0x5733CC38;
      m_lut_mod8_m_12[1035] = 0x87960F4C;
      m_lut_mod8_m_12[1036] = 0xA918A827;
      m_lut_mod8_m_12[1037] = 0xCA8ABBD3;
      m_lut_mod8_m_12[1038] = 0xA22000CA;
      m_lut_mod8_m_12[1039] = 0x80BC36F9;
      m_lut_mod8_m_12[1040] = 0x75EFFAB3;
      m_lut_mod8_m_12[1041] = 0x97E6909B;
      m_lut_mod8_m_12[1042] = 0x1D141E6F;
      m_lut_mod8_m_12[1043] = 0x0E01A9D8;
      m_lut_mod8_m_12[1044] = 0x21BC2317;
      m_lut_mod8_m_12[1045] = 0xCADFCC75;
      m_lut_mod8_m_12[1046] = 0x30AAF958;
      m_lut_mod8_m_12[1047] = 0x911ED6F7;
      m_lut_mod8_m_12[1048] = 0xB015B0F5;
      m_lut_mod8_m_12[1049] = 0xC17C5720;
      m_lut_mod8_m_12[1050] = 0xE5FBBDE7;
      m_lut_mod8_m_12[1051] = 0xB9C0268E;
      m_lut_mod8_m_12[1052] = 0x1276CFD3;
      m_lut_mod8_m_12[1053] = 0x816E4920;
      m_lut_mod8_m_12[1054] = 0x041906BD;
      m_lut_mod8_m_12[1055] = 0x05F7452B;
      m_lut_mod8_m_12[1056] = 0x56CAF826;
      m_lut_mod8_m_12[1057] = 0x11CCB588;
      m_lut_mod8_m_12[1058] = 0x7EEE6894;
      m_lut_mod8_m_12[1059] = 0x2831DB26;
      m_lut_mod8_m_12[1060] = 0xD576D4DC;
      m_lut_mod8_m_12[1061] = 0xA8CA27AB;
      m_lut_mod8_m_12[1062] = 0x928D66D6;
      m_lut_mod8_m_12[1063] = 0x62D35F73;
      m_lut_mod8_m_12[1064] = 0x5C325E1F;
      m_lut_mod8_m_12[1065] = 0x384144F1;
      m_lut_mod8_m_12[1066] = 0x617A6294;
      m_lut_mod8_m_12[1067] = 0x6C4135A0;
      m_lut_mod8_m_12[1068] = 0x1111450B;
      m_lut_mod8_m_12[1069] = 0x28B0A5FF;
      m_lut_mod8_m_12[1070] = 0x19775DF4;
      m_lut_mod8_m_12[1071] = 0x3EB9029D;
      m_lut_mod8_m_12[1072] = 0xCC7BCC0E;
      m_lut_mod8_m_12[1073] = 0xA33CCB58;
      m_lut_mod8_m_12[1074] = 0xD556DBFB;
      m_lut_mod8_m_12[1075] = 0x5BAF4F04;
      m_lut_mod8_m_12[1076] = 0x3BAB6B7F;
      m_lut_mod8_m_12[1077] = 0x2EC99D4A;
      m_lut_mod8_m_12[1078] = 0x78777A46;
      m_lut_mod8_m_12[1079] = 0x67B7D953;
      m_lut_mod8_m_12[1080] = 0xD97D827C;
      m_lut_mod8_m_12[1081] = 0x63349566;
      m_lut_mod8_m_12[1082] = 0xB1DC0254;
      m_lut_mod8_m_12[1083] = 0x05206850;
      m_lut_mod8_m_12[1084] = 0xE76CE578;
      m_lut_mod8_m_12[1085] = 0xBF27FE4D;
      m_lut_mod8_m_12[1086] = 0x1D3A1C8C;
      m_lut_mod8_m_12[1087] = 0x102B7F9D;
      m_lut_mod8_m_12[1088] = 0x930034DF;
      m_lut_mod8_m_12[1089] = 0x1550F787;
      m_lut_mod8_m_12[1090] = 0x53605330;
      m_lut_mod8_m_12[1091] = 0x7BACEC46;
      m_lut_mod8_m_12[1092] = 0x9EA63F51;
      m_lut_mod8_m_12[1093] = 0x5A488511;
      m_lut_mod8_m_12[1094] = 0xD6453734;
      m_lut_mod8_m_12[1095] = 0x13A8B1EB;
      m_lut_mod8_m_12[1096] = 0xFE61FDAA;
      m_lut_mod8_m_12[1097] = 0xB4D112BE;
      m_lut_mod8_m_12[1098] = 0x5AE1A1A1;
      m_lut_mod8_m_12[1099] = 0x29576FEA;
      m_lut_mod8_m_12[1100] = 0xF49901BF;
      m_lut_mod8_m_12[1101] = 0x03D82E3C;
      m_lut_mod8_m_12[1102] = 0x4A6D4BE2;
      m_lut_mod8_m_12[1103] = 0x705A00B5;
      m_lut_mod8_m_12[1104] = 0x86F08C5F;
      m_lut_mod8_m_12[1105] = 0x2B7F31D4;
      m_lut_mod8_m_12[1106] = 0xC2ABE562;
      m_lut_mod8_m_12[1107] = 0x447B5BDE;
      m_lut_mod8_m_12[1108] = 0xC056C3D7;
      m_lut_mod8_m_12[1109] = 0x05F15C82;
      m_lut_mod8_m_12[1110] = 0x42B712AF;
      m_lut_mod8_m_12[1111] = 0x5860DB2F;
      m_lut_mod8_m_12[1112] = 0xE077D3E9;
      m_lut_mod8_m_12[1113] = 0x540BC409;
      m_lut_mod8_m_12[1114] = 0x745A759F;
      m_lut_mod8_m_12[1115] = 0xC17A4E89;
      m_lut_mod8_m_12[1116] = 0xC12B3172;
      m_lut_mod8_m_12[1117] = 0x120321A3;
      m_lut_mod8_m_12[1118] = 0xA532D002;
      m_lut_mod8_m_12[1119] = 0x52F38265;
      m_lut_mod8_m_12[1120] = 0xD95BDB05;
      m_lut_mod8_m_12[1121] = 0x0E07B071;
      m_lut_mod8_m_12[1122] = 0x056CAF82;
      m_lut_mod8_m_12[1123] = 0x611CCB58;
      m_lut_mod8_m_12[1124] = 0x87EEE689;
      m_lut_mod8_m_12[1125] = 0x42831DB2;
      m_lut_mod8_m_12[1126] = 0x6D576D4D;
      m_lut_mod8_m_12[1127] = 0xCA8CA27A;
      m_lut_mod8_m_12[1128] = 0x0947F605;
      m_lut_mod8_m_12[1129] = 0x5987113A;
      m_lut_mod8_m_12[1130] = 0x0D998FA2;
      m_lut_mod8_m_12[1131] = 0x696AE8A8;
      m_lut_mod8_m_12[1132] = 0xF24CF273;
      m_lut_mod8_m_12[1133] = 0x121C8564;
      m_lut_mod8_m_12[1134] = 0xCD0068F5;
      m_lut_mod8_m_12[1135] = 0x2A98FBC1;
      m_lut_mod8_m_12[1136] = 0x2F45B929;
      m_lut_mod8_m_12[1137] = 0x791A777F;
      m_lut_mod8_m_12[1138] = 0x4640443B;
      m_lut_mod8_m_12[1139] = 0xD697976F;
      m_lut_mod8_m_12[1140] = 0x4E9C4B28;
      m_lut_mod8_m_12[1141] = 0x60FB014D;
      m_lut_mod8_m_12[1142] = 0x6A00BAC2;
      m_lut_mod8_m_12[1143] = 0x7FE23113;
      m_lut_mod8_m_12[1144] = 0xEB41EAA1;
      m_lut_mod8_m_12[1145] = 0x19EA6997;
      m_lut_mod8_m_12[1146] = 0x8ADBD5D8;
      m_lut_mod8_m_12[1147] = 0x13E4EBB6;
      m_lut_mod8_m_12[1148] = 0x48DC8C49;
      m_lut_mod8_m_12[1149] = 0x6F92AEC4;
      m_lut_mod8_m_12[1150] = 0x5F4D5CE9;
      m_lut_mod8_m_12[1151] = 0xDD617B9C;
      m_lut_mod8_m_12[1152] = 0x947F6055;
      m_lut_mod8_m_12[1153] = 0x987113A0;
      m_lut_mod8_m_12[1154] = 0xD998FA26;
      m_lut_mod8_m_12[1155] = 0x96AE8A8F;
      m_lut_mod8_m_12[1156] = 0x24CF2731;
      m_lut_mod8_m_12[1157] = 0x21C8564B;
      m_lut_mod8_m_12[1158] = 0x5038FEA5;
      m_lut_mod8_m_12[1159] = 0xEB6EF95B;
      m_lut_mod8_m_12[1160] = 0xFB44CCAD;
      m_lut_mod8_m_12[1161] = 0x86DE1558;
      m_lut_mod8_m_12[1162] = 0x90C39179;
      m_lut_mod8_m_12[1163] = 0xE5434440;
      m_lut_mod8_m_12[1164] = 0xD3A4DD78;
      m_lut_mod8_m_12[1165] = 0xA10D03D7;
      m_lut_mod8_m_12[1166] = 0xBE01CF46;
      m_lut_mod8_m_12[1167] = 0x80265334;
      m_lut_mod8_m_12[1168] = 0x3DC23FE3;
      m_lut_mod8_m_12[1169] = 0x2A3EBAB8;
      m_lut_mod8_m_12[1170] = 0x17E34388;
      m_lut_mod8_m_12[1171] = 0xD212E92C;
      m_lut_mod8_m_12[1172] = 0x9CDDF9CD;
      m_lut_mod8_m_12[1173] = 0x9056CCE3;
      m_lut_mod8_m_12[1174] = 0x89CE89AB;
      m_lut_mod8_m_12[1175] = 0xEEB5A8B3;
      m_lut_mod8_m_12[1176] = 0x1BC81A0F;
      m_lut_mod8_m_12[1177] = 0xEA89334E;
      m_lut_mod8_m_12[1178] = 0x16AA90E6;
      m_lut_mod8_m_12[1179] = 0xBBBF39F9;
      m_lut_mod8_m_12[1180] = 0x16D51695;
      m_lut_mod8_m_12[1181] = 0x36258FAD;
      m_lut_mod8_m_12[1182] = 0xDF8F84FF;
      m_lut_mod8_m_12[1183] = 0x9996D9B5;
      m_lut_mod8_m_12[1184] = 0x3476A66D;
      m_lut_mod8_m_12[1185] = 0xABCFA62E;
      m_lut_mod8_m_12[1186] = 0xA2D9A0DD;
      m_lut_mod8_m_12[1187] = 0xF2AE9DA6;
      m_lut_mod8_m_12[1188] = 0x5C13A722;
      m_lut_mod8_m_12[1189] = 0xD3F52339;
      m_lut_mod8_m_12[1190] = 0x7133A586;
      m_lut_mod8_m_12[1191] = 0xAD37E042;
      m_lut_mod8_m_12[1192] = 0x0FD80E47;
      m_lut_mod8_m_12[1193] = 0x3DD3635E;
      m_lut_mod8_m_12[1194] = 0x985439D2;
      m_lut_mod8_m_12[1195] = 0xA0EAC9C2;
      m_lut_mod8_m_12[1196] = 0x53EF930D;
      m_lut_mod8_m_12[1197] = 0xBD477F95;
      m_lut_mod8_m_12[1198] = 0xBBD4B80F;
      m_lut_mod8_m_12[1199] = 0xF9587155;
      m_lut_mod8_m_12[1200] = 0x4445142C;
      m_lut_mod8_m_12[1201] = 0xA2C297FC;
      m_lut_mod8_m_12[1202] = 0x65DD77D0;
      m_lut_mod8_m_12[1203] = 0xFAE40A77;
      m_lut_mod8_m_12[1204] = 0x31EF303A;
      m_lut_mod8_m_12[1205] = 0x8CF32D62;
      m_lut_mod8_m_12[1206] = 0x80028ADC;
      m_lut_mod8_m_12[1207] = 0xD1DD7D07;
      m_lut_mod8_m_12[1208] = 0x4701415B;
      m_lut_mod8_m_12[1209] = 0xEA9495A0;
      m_lut_mod8_m_12[1210] = 0x85E38672;
      m_lut_mod8_m_12[1211] = 0x48783F69;
      m_lut_mod8_m_12[1212] = 0x039EA901;
      m_lut_mod8_m_12[1213] = 0x9BBE878B;
      m_lut_mod8_m_12[1214] = 0x024442B0;
      m_lut_mod8_m_12[1215] = 0xEC6CD3CC;
      m_lut_mod8_m_12[1216] = 0x28E228E8;
      m_lut_mod8_m_12[1217] = 0x8705C191;
      m_lut_mod8_m_12[1218] = 0xC7D937F1;
      m_lut_mod8_m_12[1219] = 0xE8A16D70;
      m_lut_mod8_m_12[1220] = 0x2098743B;
      m_lut_mod8_m_12[1221] = 0xFC1C4C1B;
      m_lut_mod8_m_12[1222] = 0x9CEE9EA0;
      m_lut_mod8_m_12[1223] = 0x438ED39A;
      m_lut_mod8_m_12[1224] = 0xCBF26E76;
      m_lut_mod8_m_12[1225] = 0xD03AB712;
      m_lut_mod8_m_12[1226] = 0xAAEF1D10;
      m_lut_mod8_m_12[1227] = 0xD7F5B901;
      m_lut_mod8_m_12[1228] = 0x03F5019E;
      m_lut_mod8_m_12[1229] = 0x9B1EF484;
      m_lut_mod8_m_12[1230] = 0x0FB5F086;
      m_lut_mod8_m_12[1231] = 0xA3255DE9;
      m_lut_mod8_m_12[1232] = 0x88332B9B;
      m_lut_mod8_m_12[1233] = 0xC78526D6;
      m_lut_mod8_m_12[1234] = 0xB7F9B7D6;
      m_lut_mod8_m_12[1235] = 0x5F95E68F;
      m_lut_mod8_m_12[1236] = 0x8C29D35B;
      m_lut_mod8_m_12[1237] = 0xE946A765;
      m_lut_mod8_m_12[1238] = 0xCD762870;
      m_lut_mod8_m_12[1239] = 0xC17D60BA;
      m_lut_mod8_m_12[1240] = 0x1AF8194C;
      m_lut_mod8_m_12[1241] = 0x90E81877;
      m_lut_mod8_m_12[1242] = 0x486E4DAB;
      m_lut_mod8_m_12[1243] = 0x9A594D9E;
      m_lut_mod8_m_12[1244] = 0xEFAA1EFB;
      m_lut_mod8_m_12[1245] = 0xD10DFF6D;
      m_lut_mod8_m_12[1246] = 0xAEF4AF04;
      m_lut_mod8_m_12[1247] = 0x54630A7C;
      m_lut_mod8_m_12[1248] = 0xFB5F086A;
      m_lut_mod8_m_12[1249] = 0x3255DE98;
      m_lut_mod8_m_12[1250] = 0x8332B9BC;
      m_lut_mod8_m_12[1251] = 0x78526D6B;
      m_lut_mod8_m_12[1252] = 0x7F9B7D65;
      m_lut_mod8_m_12[1253] = 0xF95E68FC;
      m_lut_mod8_m_12[1254] = 0x3F18969A;
      m_lut_mod8_m_12[1255] = 0x414A3463;
      m_lut_mod8_m_12[1256] = 0xA1EE8F37;
      m_lut_mod8_m_12[1257] = 0x6822F2BC;
      m_lut_mod8_m_12[1258] = 0xCB97CB2D;
      m_lut_mod8_m_12[1259] = 0x3DD57AF7;
      m_lut_mod8_m_12[1260] = 0xBC84B547;
      m_lut_mod8_m_12[1261] = 0x0B29CEEF;
      m_lut_mod8_m_12[1262] = 0xE4AB8CDC;
      m_lut_mod8_m_12[1263] = 0x6EDAB4D0;
      m_lut_mod8_m_12[1264] = 0x669665B7;
      m_lut_mod8_m_12[1265] = 0xF2A8840F;
      m_lut_mod8_m_12[1266] = 0x78C32BB7;
      m_lut_mod8_m_12[1267] = 0x78362414;
      m_lut_mod8_m_12[1268] = 0xC677BA57;
      m_lut_mod8_m_12[1269] = 0x7EAA2B07;
      m_lut_mod8_m_12[1270] = 0xD29AD3FF;
      m_lut_mod8_m_12[1271] = 0x36239604;
      m_lut_mod8_m_12[1272] = 0x74E87230;
      m_lut_mod8_m_12[1273] = 0x40ADFE76;
      m_lut_mod8_m_12[1274] = 0x4C00D37C;
      m_lut_mod8_m_12[1275] = 0x5543DE1D;
      m_lut_mod8_m_12[1276] = 0x4D814CC1;
      m_lut_mod8_m_12[1277] = 0xEEB3B11A;
      m_lut_mod8_m_12[1278] = 0xB0AFECC0;
      m_lut_mod8_m_12[1279] = 0x33B2148D;
      m_lut_mod8_m_12[1280] = 0x6EDCE5F7;
      m_lut_mod8_m_12[1281] = 0x453341CA;
      m_lut_mod8_m_12[1282] = 0xF98DFA89;
      m_lut_mod8_m_12[1283] = 0x2A38A311;
      m_lut_mod8_m_12[1284] = 0x3333CF1D;
      m_lut_mod8_m_12[1285] = 0x79D1EE01;
      m_lut_mod8_m_12[1286] = 0x2B99E61C;
      m_lut_mod8_m_12[1287] = 0x43CB07A6;
      m_lut_mod8_m_12[1288] = 0x548C5413;
      m_lut_mod8_m_12[1289] = 0xE5455DE9;
      m_lut_mod8_m_12[1290] = 0xF77451ED;
      m_lut_mod8_m_12[1291] = 0x0ACE04FA;
      m_lut_mod8_m_12[1292] = 0x0945D097;
      m_lut_mod8_m_12[1293] = 0x53BB9871;
      m_lut_mod8_m_12[1294] = 0xE080E25B;
      m_lut_mod8_m_12[1295] = 0x21CE4FE2;
      m_lut_mod8_m_12[1296] = 0x2B657C13;
      m_lut_mod8_m_12[1297] = 0x08E65AC4;
      m_lut_mod8_m_12[1298] = 0x3F77344A;
      m_lut_mod8_m_12[1299] = 0x1418ED93;
      m_lut_mod8_m_12[1300] = 0x6ABB6A6E;
      m_lut_mod8_m_12[1301] = 0x546513D5;
      m_lut_mod8_m_12[1302] = 0xEF22E2E3;
      m_lut_mod8_m_12[1303] = 0x7BF9B03F;
      m_lut_mod8_m_12[1304] = 0x1DAB02C1;
      m_lut_mod8_m_12[1305] = 0x04687244;
      m_lut_mod8_m_12[1306] = 0xDEB7DC26;
      m_lut_mod8_m_12[1307] = 0x90EE01DE;
      m_lut_mod8_m_12[1308] = 0x6CBEC13E;
      m_lut_mod8_m_12[1309] = 0x319A4AB3;
      m_lut_mod8_m_12[1310] = 0x58EE012A;
      m_lut_mod8_m_12[1311] = 0x02903428;
      m_lut_mod8_m_12[1312] = 0x73B672BC;
      m_lut_mod8_m_12[1313] = 0x5F93FF26;
      m_lut_mod8_m_12[1314] = 0xA8F95FCE;
      m_lut_mod8_m_12[1315] = 0x4285A048;
      m_lut_mod8_m_12[1316] = 0x7A3237A1;
      m_lut_mod8_m_12[1317] = 0x12E0ABFF;
      m_lut_mod8_m_12[1318] = 0xC7BAC4F4;
      m_lut_mod8_m_12[1319] = 0x9B18ED2D;
      m_lut_mod8_m_12[1320] = 0xA4D20649;
      m_lut_mod8_m_12[1321] = 0x7A1E7A2A;
      m_lut_mod8_m_12[1322] = 0xF0455E8A;
      m_lut_mod8_m_12[1323] = 0x39095EE5;
      m_lut_mod8_m_12[1324] = 0x58A15BCA;
      m_lut_mod8_m_12[1325] = 0x4388CA33;
      m_lut_mod8_m_12[1326] = 0x609598B9;
      m_lut_mod8_m_12[1327] = 0x090190D1;
      m_lut_mod8_m_12[1328] = 0xD2996801;
      m_lut_mod8_m_12[1329] = 0x2979C132;
      m_lut_mod8_m_12[1330] = 0xECADED82;
      m_lut_mod8_m_12[1331] = 0x8703D838;
      m_lut_mod8_m_12[1332] = 0xE309BB64;
      m_lut_mod8_m_12[1333] = 0x43626A5D;
      m_lut_mod8_m_12[1334] = 0x97DC6BEA;
      m_lut_mod8_m_12[1335] = 0x2F81875E;
      m_lut_mod8_m_12[1336] = 0x41AC4318;
      m_lut_mod8_m_12[1337] = 0x487E26C0;
      m_lut_mod8_m_12[1338] = 0x274E2594;
      m_lut_mod8_m_12[1339] = 0x307D80A6;
      m_lut_mod8_m_12[1340] = 0xB5005D61;
      m_lut_mod8_m_12[1341] = 0x3FF11889;
      m_lut_mod8_m_12[1342] = 0xF5A0F550;
      m_lut_mod8_m_12[1343] = 0x8CF534CB;
      m_lut_mod8_m_12[1344] = 0x4A3FB02A;
      m_lut_mod8_m_12[1345] = 0xCC3889D0;
      m_lut_mod8_m_12[1346] = 0x6CCC7D13;
      m_lut_mod8_m_12[1347] = 0x4B574547;
      m_lut_mod8_m_12[1348] = 0x92679398;
      m_lut_mod8_m_12[1349] = 0x90E42B25;
      m_lut_mod8_m_12[1350] = 0x8E782EDA;
      m_lut_mod8_m_12[1351] = 0xBF27632B;
      m_lut_mod8_m_12[1352] = 0x4E104B98;
      m_lut_mod8_m_12[1353] = 0x5B27DA90;
      m_lut_mod8_m_12[1354] = 0x266B25D0;
      m_lut_mod8_m_12[1355] = 0x546F392E;
      m_lut_mod8_m_12[1356] = 0x0DE40D07;
      m_lut_mod8_m_12[1357] = 0xF54499A7;
      m_lut_mod8_m_12[1358] = 0x0B554873;
      m_lut_mod8_m_12[1359] = 0x5DDF9CFC;
      m_lut_mod8_m_12[1360] = 0x8B6A8B4A;
      m_lut_mod8_m_12[1361] = 0x9B12C7D6;
      m_lut_mod8_m_12[1362] = 0xC9A393F7;
      m_lut_mod8_m_12[1363] = 0x865B735C;
      m_lut_mod8_m_12[1364] = 0x29897EF8;
      m_lut_mod8_m_12[1365] = 0x4DAF032B;
      m_lut_mod8_m_12[1366] = 0x3F663D02;
      m_lut_mod8_m_12[1367] = 0x5F99D5DD;
      m_lut_mod8_m_12[1368] = 0xC588CA70;
      m_lut_mod8_m_12[1369] = 0xBEC0A93E;
      m_lut_mod8_m_12[1370] = 0xA3FE17D3;
      m_lut_mod8_m_12[1371] = 0x6646F631;
      m_lut_mod8_m_12[1372] = 0xA07DA23C;
      m_lut_mod8_m_12[1373] = 0x8709F2C3;
      m_lut_mod8_m_12[1374] = 0x01CF5480;
      m_lut_mod8_m_12[1375] = 0xCDDF43C5;
      m_lut_mod8_m_12[1376] = 0x81222158;
      m_lut_mod8_m_12[1377] = 0x763669E6;
      m_lut_mod8_m_12[1378] = 0x14711474;
      m_lut_mod8_m_12[1379] = 0x4382E0C8;
      m_lut_mod8_m_12[1380] = 0x8253775D;
      m_lut_mod8_m_12[1381] = 0x87BCB949;
      m_lut_mod8_m_12[1382] = 0xC46722B3;
      m_lut_mod8_m_12[1383] = 0x70CE2F8A;
      m_lut_mod8_m_12[1384] = 0xB970BAEE;
      m_lut_mod8_m_12[1385] = 0x8CFF1E30;
      m_lut_mod8_m_12[1386] = 0x4614E9AD;
      m_lut_mod8_m_12[1387] = 0xF4A353B2;
      m_lut_mod8_m_12[1388] = 0xE6BB1438;
      m_lut_mod8_m_12[1389] = 0x60BEB05D;
      m_lut_mod8_m_12[1390] = 0x0D7C0CA6;
      m_lut_mod8_m_12[1391] = 0x48740C3B;
      m_lut_mod8_m_12[1392] = 0x9A05C453;
      m_lut_mod8_m_12[1393] = 0xF68B0D8C;
      m_lut_mod8_m_12[1394] = 0xD089F0E5;
      m_lut_mod8_m_12[1395] = 0x271DC5BF;
      m_lut_mod8_m_12[1396] = 0x87478493;
      m_lut_mod8_m_12[1397] = 0x3DDF500C;
      m_lut_mod8_m_12[1398] = 0x5E425AA3;
      m_lut_mod8_m_12[1399] = 0x8594E777;
      m_lut_mod8_m_12[1400] = 0xF255C66E;
      m_lut_mod8_m_12[1401] = 0x376D5A68;
      m_lut_mod8_m_12[1402] = 0x334B32DB;
      m_lut_mod8_m_12[1403] = 0xF9544207;
      m_lut_mod8_m_12[1404] = 0xDDDE797E;
      m_lut_mod8_m_12[1405] = 0xCFF71DFB;
      m_lut_mod8_m_12[1406] = 0xB710C585;
      m_lut_mod8_m_12[1407] = 0x31951C04;
      m_lut_mod8_m_12[1408] = 0x9E4A9C41;
      m_lut_mod8_m_12[1409] = 0x3629BCFF;
      m_lut_mod8_m_12[1410] = 0x1999E78E;
      m_lut_mod8_m_12[1411] = 0xBCE8F700;
      m_lut_mod8_m_12[1412] = 0x95CCF30E;
      m_lut_mod8_m_12[1413] = 0x21E583D3;
      m_lut_mod8_m_12[1414] = 0x2A462A09;
      m_lut_mod8_m_12[1415] = 0xF2A2AEF4;
      m_lut_mod8_m_12[1416] = 0x15B2BE09;
      m_lut_mod8_m_12[1417] = 0x84732D62;
      m_lut_mod8_m_12[1418] = 0x1FBB9A25;
      m_lut_mod8_m_12[1419] = 0x0A0C76C9;
      m_lut_mod8_m_12[1420] = 0xB55DB537;
      m_lut_mod8_m_12[1421] = 0x2A3289EA;
      m_lut_mod8_m_12[1422] = 0xD1F520F9;
      m_lut_mod8_m_12[1423] = 0xF76CC799;
      m_lut_mod8_m_12[1424] = 0x3D67ACAE;
      m_lut_mod8_m_12[1425] = 0x1A7CE91E;
      m_lut_mod8_m_12[1426] = 0x0151037F;
      m_lut_mod8_m_12[1427] = 0xEEB99BE1;
      m_lut_mod8_m_12[1428] = 0x52690324;
      m_lut_mod8_m_12[1429] = 0xBD0F3D15;
      m_lut_mod8_m_12[1430] = 0x7822AF45;
      m_lut_mod8_m_12[1431] = 0x1C84AF72;
      m_lut_mod8_m_12[1432] = 0xAC50ADE5;
      m_lut_mod8_m_12[1433] = 0x21C46519;
      m_lut_mod8_m_12[1434] = 0x962E9DD4;
      m_lut_mod8_m_12[1435] = 0xCE10D7EE;
      m_lut_mod8_m_12[1436] = 0x5AFE99CE;
      m_lut_mod8_m_12[1437] = 0x0CF430A5;
      m_lut_mod8_m_12[1438] = 0x185C1BAD;
      m_lut_mod8_m_12[1439] = 0xE54F7712;
      m_lut_mod8_m_12[1440] = 0x251FD815;
      m_lut_mod8_m_12[1441] = 0x661C44E8;
      m_lut_mod8_m_12[1442] = 0x36663E89;
      m_lut_mod8_m_12[1443] = 0xA5ABA2A3;
      m_lut_mod8_m_12[1444] = 0xC933C9CC;
      m_lut_mod8_m_12[1445] = 0x48721592;
      m_lut_mod8_m_12[1446] = 0xE15846E5;
      m_lut_mod8_m_12[1447] = 0x1503AE13;
      m_lut_mod8_m_12[1448] = 0x14BA0802;
      m_lut_mod8_m_12[1449] = 0xB5DB3D74;
      m_lut_mod8_m_12[1450] = 0x7D3F7F84;
      m_lut_mod8_m_12[1451] = 0x8CF90799;
      m_lut_mod8_m_12[1452] = 0x62C46538;
      m_lut_mod8_m_12[1453] = 0x5F60549F;
      m_lut_mod8_m_12[1454] = 0x51FF0BE9;
      m_lut_mod8_m_12[1455] = 0xB3237B18;
      m_lut_mod8_m_12[1456] = 0xD03ED11E;
      m_lut_mod8_m_12[1457] = 0x4384F961;
      m_lut_mod8_m_12[1458] = 0xA683FBC8;
      m_lut_mod8_m_12[1459] = 0x2C7FBE64;
      m_lut_mod8_m_12[1460] = 0x73233D62;
      m_lut_mod8_m_12[1461] = 0xA353E4CF;
      m_lut_mod8_m_12[1462] = 0x64326756;
      m_lut_mod8_m_12[1463] = 0x870FEB6A;
      m_lut_mod8_m_12[1464] = 0xAAA8A24F;
      m_lut_mod8_m_12[1465] = 0x14E46406;
      m_lut_mod8_m_12[1466] = 0xF9545449;
      m_lut_mod8_m_12[1467] = 0x88BA11D5;
      m_lut_mod8_m_12[1468] = 0xFB29F868;
      m_lut_mod8_m_12[1469] = 0x5F9FCC74;
      m_lut_mod8_m_12[1470] = 0x6EEF3CBF;
      m_lut_mod8_m_12[1471] = 0x67FB8EFD;
      m_lut_mod8_m_12[1472] = 0xDB8862C2;
      m_lut_mod8_m_12[1473] = 0x98CA8E02;
      m_lut_mod8_m_12[1474] = 0x4F254E20;
      m_lut_mod8_m_12[1475] = 0x9B14DE7F;
      m_lut_mod8_m_12[1476] = 0xED731F62;
      m_lut_mod8_m_12[1477] = 0x2D987471;
      m_lut_mod8_m_12[1478] = 0x9ECD6129;
      m_lut_mod8_m_12[1479] = 0x9E32C86E;
      m_lut_mod8_m_12[1480] = 0xE224E0BA;
      m_lut_mod8_m_12[1481] = 0x54692087;
      m_lut_mod8_m_12[1482] = 0x29348192;
      m_lut_mod8_m_12[1483] = 0x5E879E8A;
      m_lut_mod8_m_12[1484] = 0xBC1157A2;
      m_lut_mod8_m_12[1485] = 0x8E4257B9;
      m_lut_mod8_m_12[1486] = 0x562856F2;
      m_lut_mod8_m_12[1487] = 0x90E2328C;
      m_lut_mod8_m_12[1488] = 0xF525AC6C;
      m_lut_mod8_m_12[1489] = 0x5CAFC0B4;
      m_lut_mod8_m_12[1490] = 0x8A23B37F;
      m_lut_mod8_m_12[1491] = 0xC9E1225B;
      m_lut_mod8_m_12[1492] = 0xDC13DEC7;
      m_lut_mod8_m_12[1493] = 0xE5496EBB;
      m_lut_mod8_m_12[1494] = 0x3162329C;
      m_lut_mod8_m_12[1495] = 0x2FB02A4F;
      m_lut_mod8_m_12[1496] = 0xA8FF85F4;
      m_lut_mod8_m_12[1497] = 0xD991BD8C;
      m_lut_mod8_m_12[1498] = 0x681F688F;
      m_lut_mod8_m_12[1499] = 0x21C27CB0;
      m_lut_mod8_m_12[1500] = 0xB2FE1141;
      m_lut_mod8_m_12[1501] = 0x65D3D0C3;
      m_lut_mod8_m_12[1502] = 0xEDBA861F;
      m_lut_mod8_m_12[1503] = 0xDF69FBE0;
      m_lut_mod8_m_12[1504] = 0xC51EC615;
      m_lut_mod8_m_12[1505] = 0xEEBF8248;
      m_lut_mod8_m_12[1506] = 0x76B98FB1;
      m_lut_mod8_m_12[1507] = 0x16CC3A38;
      m_lut_mod8_m_12[1508] = 0xCF66B094;
      m_lut_mod8_m_12[1509] = 0xCF196437;
      m_lut_mod8_m_12[1510] = 0x7112705D;
      m_lut_mod8_m_12[1511] = 0x2A349043;
      m_lut_mod8_m_12[1512] = 0x7A92D636;
      m_lut_mod8_m_12[1513] = 0x2E57E05A;
      m_lut_mod8_m_12[1514] = 0x4511D9BF;
      m_lut_mod8_m_12[1515] = 0xE4F0912D;
      m_lut_mod8_m_12[1516] = 0xEE09EF63;
      m_lut_mod8_m_12[1517] = 0xF2A4B75D;
      m_lut_mod8_m_12[1518] = 0xBED548C6;
      m_lut_mod8_m_12[1519] = 0x5D480AA1;
      m_lut_mod8_m_12[1520] = 0x67CDEF34;
      m_lut_mod8_m_12[1521] = 0xF4800EFA;
      m_lut_mod8_m_12[1522] = 0x5A05592B;
      m_lut_mod8_m_12[1523] = 0x362FA556;
      m_lut_mod8_m_12[1524] = 0x3D496B1B;
      m_lut_mod8_m_12[1525] = 0x172BF02D;
      m_lut_mod8_m_12[1526] = 0x2288ECDF;
      m_lut_mod8_m_12[1527] = 0xF2784896;
      m_lut_mod8_m_12[1528] = 0xF704F7B1;
      m_lut_mod8_m_12[1529] = 0xF9525BAE;
      m_lut_mod8_m_12[1530] = 0xF90EF5EB;
      m_lut_mod8_m_12[1531] = 0x64341AD6;
      m_lut_mod8_m_12[1532] = 0x0054DA54;
      m_lut_mod8_m_12[1533] = 0xE208D741;
      m_lut_mod8_m_12[1534] = 0x430841F9;
      m_lut_mod8_m_12[1535] = 0x3DD949A5;

      /* Obsolete: use precalculated values instead to speed up initialization
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
          m_lut_mod8_m_12[6*b + i] = tabval[i];
        }
      }
      for (int i = 0; i < 6*256; i++) {
        printf("m_lut_mod8_m_12[%i] = 0x%08X;\n", i, m_lut_mod8_m_12[i]);
      }
      */

      /* Obsolete: use precalculated values instead to speed up initialization
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

      // Use these precalculated values. This current function would then be
      // obsolete. Should be faster, though not necessarily suitable for
      // upstream.
      for (int i = 0; i < 4; i++) {
        printf("m_poly_n_8[%i] = 0x%08X;\n", i, m_poly_n_8[i]);
      }
      for (int i = 0; i < 5; i++) {
        printf("m_poly_n_10[%i] = 0x%08X;\n", i, m_poly_n_10[i]);
      }
      for (int i = 0; i < 6; i++) {
        printf("m_poly_n_12[%i] = 0x%08X;\n", i, m_poly_n_12[i]);
      }
      for (int i = 0; i < 6; i++) {
        printf("m_poly_s_12[%i] = 0x%08X;\n", i, m_poly_s_12[i]);
      }
      for (int i = 0; i < 6; i++) {
        printf("m_poly_m_12[%i] = 0x%08X;\n", i, m_poly_m_12[i]);
      }*/
    }

    int
    dvb_bch_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      unsigned char b, temp;
      unsigned int shift[6];
      int consumed = 0;

      switch (bch_code) {
        case BCH_CODE_N12:
          for (int i = 0; i < noutput_items; i += nbch) {
            // Copy block from input to output buffer in one operation
            memcpy(out, in, kbch);
            out += kbch;
            //Zero the shift register
            memset(shift, 0, sizeof(unsigned int) * 6);
            // MSB of the codeword first
            for (int j = 0; j < (int)kbch/8; j++) {
              // Only temporarily, until we switch from bit items to bytes
              unsigned char in_byte = 0;
              for (int i = 0; i < 8; i++) {
                in_byte |= (*in++ & 1) << i;
              }

              b = (in_byte ^ (shift[5] & 0xFF));
              // todo: replace by sse instruction if possible
              reg_6_shift_8(shift);

              shift[0] ^= m_lut_mod8_m_12[6*b + 0];
              shift[1] ^= m_lut_mod8_m_12[6*b + 1];
              shift[2] ^= m_lut_mod8_m_12[6*b + 2];
              shift[3] ^= m_lut_mod8_m_12[6*b + 3];
              shift[4] ^= m_lut_mod8_m_12[6*b + 4];
              shift[5] ^= m_lut_mod8_m_12[6*b + 5];
            }
            consumed += kbch;
            // Now add the parity bits to the output
            // todo: update for bytewise data
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

  } /* namespace dtv */
} /* namespace gr */
