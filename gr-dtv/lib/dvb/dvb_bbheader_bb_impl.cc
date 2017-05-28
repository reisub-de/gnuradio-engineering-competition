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
#include "dvb_bbheader_bb_impl.h"

#include <stdio.h>

namespace gr {
  namespace dtv {

    dvb_bbheader_bb::sptr
    dvb_bbheader_bb::make(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate, dvbs2_rolloff_factor_t rolloff, dvbt2_inputmode_t mode, dvbt2_inband_t inband, int fecblocks, int tsrate)
    {
      return gnuradio::get_initial_sptr
        (new dvb_bbheader_bb_impl(standard, framesize, rate, rolloff, mode, inband, fecblocks, tsrate));
    }

    /*
     * The private constructor
     */
    dvb_bbheader_bb_impl::dvb_bbheader_bb_impl(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate, dvbs2_rolloff_factor_t rolloff, dvbt2_inputmode_t mode, dvbt2_inband_t inband, int fecblocks, int tsrate)
      : gr::block("dvb_bbheader_bb",
              gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {
      printf("%d %d %d %d %d %d %d %d ", standard, framesize_t framesize, code_rate_t rate, 2_rolloff_factor_t rolloff, 2_inputmode_t mode, 2_inband_t inband, fecblocks, tsrate);
      count = 0;
      crc = 0x0;
      dvbs2x = FALSE;
      alternate = TRUE;
      nibble = TRUE;
      frame_size = framesize;
      BBHeader *f = &m_format[0].bb_header;
      if (framesize == FECFRAME_NORMAL) {
        switch (rate) {
          case C1_4:
            kbch = 16008;
            break;
          case C1_3:
            kbch = 21408;
            break;
          case C2_5:
            kbch = 25728;
            break;
          case C1_2:
            kbch = 32208;
            break;
          case C3_5:
            kbch = 38688;
            break;
          case C2_3:
            kbch = 43040;
            break;
          case C3_4:
            kbch = 48408;
            break;
          case C4_5:
            kbch = 51648;
            break;
          case C5_6:
            kbch = 53840;
            break;
          case C8_9:
            kbch = 57472;
            break;
          case C9_10:
            kbch = 58192;
            break;
          case C2_9_VLSNR:
            kbch = 14208;
            break;
          case C13_45:
            kbch = 18528;
            break;
          case C9_20:
            kbch = 28968;
            break;
          case C90_180:
            kbch = 32208;
            break;
          case C96_180:
            kbch = 34368;
            break;
          case C11_20:
            kbch = 35448;
            break;
          case C100_180:
            kbch = 35808;
            break;
          case C104_180:
            kbch = 37248;
            break;
          case C26_45:
            kbch = 37248;
            break;
          case C18_30:
            kbch = 38688;
            break;
          case C28_45:
            kbch = 40128;
            break;
          case C23_36:
            kbch = 41208;
            break;
          case C116_180:
            kbch = 41568;
            break;
          case C20_30:
            kbch = 43008;
            break;
          case C124_180:
            kbch = 44448;
            break;
          case C25_36:
            kbch = 44808;
            break;
          case C128_180:
            kbch = 45888;
            break;
          case C13_18:
            kbch = 46608;
            break;
          case C132_180:
            kbch = 47328;
            break;
          case C22_30:
            kbch = 47328;
            break;
          case C135_180:
            kbch = 48408;
            break;
          case C140_180:
            kbch = 50208;
            break;
          case C7_9:
            kbch = 50208;
            break;
          case C154_180:
            kbch = 55248;
            break;
          default:
            kbch = 0;
            break;
        }
      }
      else if (framesize == FECFRAME_SHORT) {
        switch (rate) {
          case C1_4:
            kbch = 3072;
            break;
          case C1_3:
            kbch = 5232;
            break;
          case C2_5:
            kbch = 6312;
            break;
          case C1_2:
            kbch = 7032;
            break;
          case C3_5:
            kbch = 9552;
            break;
          case C2_3:
            kbch = 10632;
            break;
          case C3_4:
            kbch = 11712;
            break;
          case C4_5:
            kbch = 12432;
            break;
          case C5_6:
            kbch = 13152;
            break;
          case C8_9:
            kbch = 14232;
            break;
          case C11_45:
            kbch = 3792;
            break;
          case C4_15:
            kbch = 4152;
            break;
          case C14_45:
            kbch = 4872;
            break;
          case C7_15:
            kbch = 7392;
            break;
          case C8_15:
            kbch = 8472;
            break;
          case C26_45:
            kbch = 9192;
            break;
          case C32_45:
            kbch = 11352;
            break;
          case C1_5_VLSNR_SF2:
            kbch = 2512;
            break;
          case C11_45_VLSNR_SF2:
            kbch = 3792;
            break;
          case C1_5_VLSNR:
            kbch = 3072;
            break;
          case C4_15_VLSNR:
            kbch = 4152;
            break;
          case C1_3_VLSNR:
            kbch = 5232;
            break;
          default:
            kbch = 0;
            break;
        }
      }
      else {
        switch (rate) {
          case C1_5_MEDIUM:
            kbch = 5660;
            break;
          case C11_45_MEDIUM:
            kbch = 7740;
            break;
          case C1_3_MEDIUM:
            kbch = 10620;
            break;
          default:
            kbch = 0;
            break;
        }
      }

      if (standard == STANDARD_DVBS2) {
        mode = INPUTMODE_NORMAL;
        inband_type_b = FALSE;
      }
      f->ts_gs   = TS_GS_TRANSPORT;
      f->sis_mis = SIS_MIS_SINGLE;
      f->ccm_acm = CCM;
      f->issyi   = ISSYI_NOT_ACTIVE;
      f->npd     = NPD_NOT_ACTIVE;
      if (mode == INPUTMODE_NORMAL) {
        f->upl  = 188 * 8;
        f->dfl  = kbch - 80;
        f->sync = 0x47;
      }
      else {
        f->upl  = 0;
        f->dfl  = kbch - 80;
        f->sync = 0;
      }
      if (standard == STANDARD_DVBS2) {
        if (rolloff & 0x4) {
          dvbs2x = TRUE;
        }
        f->ro = rolloff & 0x3;
      }
      else {
        f->ro = 0;
      }

      input_mode = mode;
      inband_type_b = inband;
      fec_blocks = fecblocks;
      fec_block = 0;
      ts_rate = tsrate;
      extra = (((kbch - 80) >> 3) / 187) + 1;
      if (framesize != FECFRAME_MEDIUM) {
        set_output_multiple(kbch);
      }
      else {
        set_output_multiple(kbch << 2);
      }
    }

    /*
     * Our virtual destructor.
     */
    dvb_bbheader_bb_impl::~dvb_bbheader_bb_impl()
    {
    }

    void
    dvb_bbheader_bb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      if (input_mode == INPUTMODE_NORMAL) {
        if (frame_size != FECFRAME_MEDIUM) {
          ninput_items_required[0] = ((noutput_items - 80) >> 3);
        }
        else {
          ninput_items_required[0] = ((noutput_items - 160) >> 3);
        }
      }
      else {
        ninput_items_required[0] = ((noutput_items - 80) >> 3) + extra;
      }
    }

#define CRC_POLY 0xAB
    /*
     * MSB is sent first
     *
     * The polynomial has been reversed
     */
    int
    dvb_bbheader_bb_impl::add_crc8_bits(unsigned char *in, int length)
    {
      int crc = 0;
      int b;
      int i = 0;

      for (int n = 0; n < length; n++) {
        b = in[i++] ^ (crc & 0x01);
        crc >>= 1;
        if (b) {
          crc ^= CRC_POLY;
        }
      }

      if (input_mode == INPUTMODE_HIEFF) {
        crc ^= 0x80;
      }

      for (int n = 0; n < 8; n++) {
        in[i++] = (crc & (1 << n)) ? 1 : 0;
      }
      return 8;// Length of CRC
    }

    void
    dvb_bbheader_bb_impl::add_bbheader(unsigned char *out, int count, int padding, bool nibble)
    {
      int temp, m_frame_offset_bits;
      unsigned char *m_frame = out;
      BBHeader *h = &m_format[0].bb_header;

      m_frame[0] = h->ts_gs >> 1;
      m_frame[1] = h->ts_gs & 1;
      m_frame[2] = h->sis_mis;
      m_frame[3] = h->ccm_acm;
      m_frame[4] = h->issyi & 1;
      m_frame[5] = h->npd & 1;
      if (dvbs2x == TRUE) {
        if (alternate == TRUE) {
          alternate = FALSE;
          m_frame[6] = 1;
          m_frame[7] = 1;
        }
        else {
          alternate = TRUE;
          m_frame[6] = h->ro >> 1;
          m_frame[7] = h->ro & 1;
        }
      }
      else {
        m_frame[6] = h->ro >> 1;
        m_frame[7] = h->ro & 1;
      }
      m_frame_offset_bits = 8;
      if (h->sis_mis == SIS_MIS_MULTIPLE) {
        temp = h->isi;
        for (int n = 7; n >= 0; n--) {
          m_frame[m_frame_offset_bits++] = temp & (1 << n) ? 1 : 0;
        }
      }
      else {
        for (int n = 7; n >= 0; n--) {
          m_frame[m_frame_offset_bits++] = 0;
        }
      }
      temp = h->upl;
      for (int n = 15; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = temp & (1 << n) ? 1 : 0;
      }
      temp = h->dfl - padding;
      for (int n = 15; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = temp & (1 << n) ? 1 : 0;
      }
      temp = h->sync;
      for (int n = 7; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = temp & (1 << n) ? 1 : 0;
      }
      // Calculate syncd, this should point to the MSB of the CRC
      temp = count;
      if (temp == 0) {
        temp = count;
      }
      else {
        temp = (188 - count) * 8;
      }
      if (nibble == FALSE) {
        temp += 4;
      }
      for (int n = 15; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = temp & (1 << n) ? 1 : 0;
      }
      // Add CRC to BB header, at end
      int len = BB_HEADER_LENGTH_BITS;
      m_frame_offset_bits += add_crc8_bits(m_frame, len);
    }

    void
    dvb_bbheader_bb_impl::add_inband_type_b(unsigned char *out, int ts_rate)
    {
      int temp, m_frame_offset_bits;
      unsigned char *m_frame = out;

      m_frame[0] = 0;
      m_frame[1] = 1;
      m_frame_offset_bits = 2;
      for (int n = 30; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = 0;
      }
      for (int n = 21; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = 0;
      }
      for (int n = 1; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = 0;
      }
      for (int n = 9; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = 0;
      }
      temp = ts_rate;
      for (int n = 26; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = temp & (1 << n) ? 1 : 0;
      }
      for (int n = 9; n >= 0; n--) {
        m_frame[m_frame_offset_bits++] = 0;
      }
    }

    int
    dvb_bbheader_bb_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      int consumed = 0;
      int offset = 0;
      int padding;
      unsigned char b;

      if (frame_size != FECFRAME_MEDIUM) {
        for (int i = 0; i < noutput_items; i += kbch) {
          if (fec_block == 0 && inband_type_b == TRUE) {
            padding = 104;
          }
          else {
            padding = 0;
          }
          add_bbheader(&out[offset], count, padding, TRUE);
          offset = offset + 80;

          if (input_mode == INPUTMODE_HIEFF) {
            for (int j = 0; j < (int)((kbch - 80 - padding) / 8); j++) {
              if (count == 0) {
                if (*in != 0x47) {
                  GR_LOG_WARN(d_logger, "Transport Stream sync error!");
                }
                j--;
                in++;
              }
              else {
                b = *in++;
                for (int n = 7; n >= 0; n--) {
                  out[offset++] = b & (1 << n) ? 1 : 0;
                }
              }
              count = (count + 1) % 188;
              consumed++;
            }
            if (fec_block == 0 && inband_type_b == TRUE) {
              add_inband_type_b(&out[offset], ts_rate);
              offset = offset + 104;
            }
          }
          else {
            for (int j = 0; j < (int)((kbch - 80 - padding) / 8); j++) {
              if (count == 0) {
                if (*in != 0x47) {
                  GR_LOG_WARN(d_logger, "Transport Stream sync error!");
                }
                in++;
                b = crc;
                crc = 0;
              }
              else {
                b = *in++;
                crc = crc_tab[b ^ crc];
              }
              count = (count + 1) % 188;
              consumed++;
              for (int n = 7; n >= 0; n--) {
                out[offset++] = b & (1 << n) ? 1 : 0;
              }
            }
            if (fec_block == 0 && inband_type_b == TRUE) {
              add_inband_type_b(&out[offset], ts_rate);
              offset = offset + 104;
            }
          }
          if (inband_type_b == TRUE) {
            fec_block = (fec_block + 1) % fec_blocks;
          }
        }
      }
      else {
        for (int i = 0; i < noutput_items; i += kbch) {
            padding = 0;
            add_bbheader(&out[offset], count, padding, nibble);
            offset = offset + 80;
            for (int j = 0; j < (int)((kbch - 80) / 4); j++) {
              if (nibble == TRUE) {
                if (count == 0) {
                  if (*in != 0x47) {
                    GR_LOG_WARN(d_logger, "Transport Stream sync error!");
                  }
                  in++;
                  b = crc;
                  crc = 0;
                }
                else {
                  b = *in++;
                  crc = crc_tab[b ^ crc];
                }
                bsave = b;
                count = (count + 1) % 188;
                consumed++;
                for (int n = 7; n >= 4; n--) {
                  out[offset++] = b & (1 << n) ? 1 : 0;
                }
                nibble = FALSE;
              }
              else {
                for (int n = 3; n >= 0; n--) {
                  out[offset++] = bsave & (1 << n) ? 1 : 0;
                }
                nibble = TRUE;
              }
            }
        }
      }

      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (consumed);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }
    const unsigned char dvb_bbheader_bb_impl::crc_tab[256] = {
        0x00, 0xd5, 0x7f, 0xaa, 0xfe, 0x2b, 0x81, 0x54, 0x29, 0xfc, 0x56,
        0x83, 0xd7, 0x02, 0xa8, 0x7d, 0x52, 0x87, 0x2d, 0xf8, 0xac, 0x79, 
        0xd3, 0x06, 0x7b, 0xae, 0x04, 0xd1, 0x85, 0x50, 0xfa, 0x2f, 0xa4,
        0x71, 0xdb, 0x0e, 0x5a, 0x8f, 0x25, 0xf0, 0x8d, 0x58, 0xf2, 0x27,
        0x73, 0xa6, 0x0c, 0xd9, 0xf6, 0x23, 0x89, 0x5c, 0x08, 0xdd, 0x77,
        0xa2, 0xdf, 0x0a, 0xa0, 0x75, 0x21, 0xf4, 0x5e, 0x8b, 0x9d, 0x48, 
        0xe2, 0x37, 0x63, 0xb6, 0x1c, 0xc9, 0xb4, 0x61, 0xcb, 0x1e, 0x4a,
        0x9f, 0x35, 0xe0, 0xcf, 0x1a, 0xb0, 0x65, 0x31, 0xe4, 0x4e, 0x9b,
        0xe6, 0x33, 0x99, 0x4c, 0x18, 0xcd, 0x67, 0xb2, 0x39, 0xec, 0x46,
        0x93, 0xc7, 0x12, 0xb8, 0x6d, 0x10, 0xc5, 0x6f, 0xba, 0xee, 0x3b, 
        0x91, 0x44, 0x6b, 0xbe, 0x14, 0xc1, 0x95, 0x40, 0xea, 0x3f, 0x42, 
        0x97, 0x3d, 0xe8, 0xbc, 0x69, 0xc3, 0x16, 0xef, 0x3a, 0x90, 0x45, 
        0x11, 0xc4, 0x6e, 0xbb, 0xc6, 0x13, 0xb9, 0x6c, 0x38, 0xed, 0x47, 
        0x92, 0xbd, 0x68, 0xc2, 0x17, 0x43, 0x96, 0x3c, 0xe9, 0x94, 0x41, 
        0xeb, 0x3e, 0x6a, 0xbf, 0x15, 0xc0, 0x4b, 0x9e, 0x34, 0xe1, 0xb5, 
        0x60, 0xca, 0x1f, 0x62, 0xb7, 0x1d, 0xc8, 0x9c, 0x49, 0xe3, 0x36, 
        0x19, 0xcc, 0x66, 0xb3, 0xe7, 0x32, 0x98, 0x4d, 0x30, 0xe5, 0x4f, 
        0x9a, 0xce, 0x1b, 0xb1, 0x64, 0x72, 0xa7, 0x0d, 0xd8, 0x8c, 0x59, 
        0xf3, 0x26, 0x5b, 0x8e, 0x24, 0xf1, 0xa5, 0x70, 0xda, 0x0f, 0x20, 
        0xf5, 0x5f, 0x8a, 0xde, 0x0b, 0xa1, 0x74, 0x09, 0xdc, 0x76, 0xa3, 
        0xf7, 0x22, 0x88, 0x5d, 0xd6, 0x03, 0xa9, 0x7c, 0x28, 0xfd, 0x57, 
        0x82, 0xff, 0x2a, 0x80, 0x55, 0x01, 0xd4, 0x7e, 0xab, 0x84, 0x51, 
        0xfb, 0x2e, 0x7a, 0xaf, 0x05, 0xd0, 0xad, 0x78, 0xd2, 0x07, 0x53, 
        0x86, 0x2c, 0xf9
    };
  } /* namespace dtv */
} /* namespace gr */

