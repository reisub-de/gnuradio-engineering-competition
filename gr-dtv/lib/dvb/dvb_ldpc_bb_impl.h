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

#ifndef INCLUDED_DTV_DVB_LDPC_BB_IMPL_H
#define INCLUDED_DTV_DVB_LDPC_BB_IMPL_H

#include <gnuradio/dtv/dvb_ldpc_bb.h>
#include "dvb_defines.h"

typedef struct{
    int table_length;
    int d[LDPC_ENCODE_TABLE_LENGTH];
    int p[LDPC_ENCODE_TABLE_LENGTH];
}ldpc_encode_table;

namespace gr {
  namespace dtv {

    class dvb_ldpc_bb_impl : public dvb_ldpc_bb
    {
     private:
      unsigned int frame_size;
      unsigned int frame_size_real;
      unsigned int frame_size_type;
      unsigned int signal_constellation;
      unsigned int nbch;
      unsigned int code_rate;
      unsigned int q_val;
      unsigned int dvb_standard;
      int Xs;
      int P;
      int Xp;
      unsigned char puncturing_buffer[FRAME_SIZE_NORMAL];
      unsigned char shortening_buffer[FRAME_SIZE_NORMAL];
      void ldpc_lookup_generate(void);
      ldpc_encode_table ldpc_encode;

      const static int ldpc_tab_1_2N[90][9];
      const static int ldpc_tab_3_5N[108][13];
      const static int ldpc_tab_2_3N_DVBT2[120][14];
      const static int ldpc_tab_3_4N[135][13];
      const static int ldpc_tab_4_5N[144][12];
      const static int ldpc_tab_5_6N[150][14];

      const static int ldpc_tab_1_4S[9][13];
      const static int ldpc_tab_1_2S[20][9];
      const static int ldpc_tab_3_5S_DVBT2[27][13];
      const static int ldpc_tab_2_3S[30][14];
      const static int ldpc_tab_3_4S[33][13];
      const static int ldpc_tab_4_5S[35][4];
      const static int ldpc_tab_5_6S[37][14];
      const static int ldpc_tab_1_3S[15][13];
      const static int ldpc_tab_2_5S[18][13];
      
      
     public:
      dvb_ldpc_bb_impl(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate, dvb_constellation_t constellation);
      ~dvb_ldpc_bb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items);
    };

  } // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVB_LDPC_BB_IMPL_H */

