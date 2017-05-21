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

#ifndef INCLUDED_DTV_DVB_BCH_BB_IMPL_H
#define INCLUDED_DTV_DVB_BCH_BB_IMPL_H

#include <gnuradio/dtv/dvb_bch_bb.h>
#include "dvb_defines.h"

#include <ctime>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

namespace gr {
  namespace dtv {

    class dvb_bch_bb_impl : public dvb_bch_bb
    {
     private:
      unsigned int kbch;
      unsigned int nbch;
      unsigned int bch_code;
      unsigned int m_poly_n_8[4];
/*
      unsigned int m_poly_n_10[5];
      unsigned int m_poly_n_12[6];
      unsigned int m_poly_s_12[6];
      unsigned int m_poly_m_12[6];
*/
      #define m_poly_n_8_0 3563495200u
      #define m_poly_n_8_1 2931179416u
      #define m_poly_n_8_2 3186222222u
      #define m_poly_n_8_3 4205109304u
      #define m_poly_n_10_0 2309414173u
      #define m_poly_n_10_1 2160364535u
      #define m_poly_n_10_2 3236568662u
      #define m_poly_n_10_3 4174140479u
      #define m_poly_n_10_4 3073419270u
      #define m_poly_n_12_0 3886694502u
      #define m_poly_n_12_1 4020363968u
      #define m_poly_n_12_2 2433788987u
      #define m_poly_n_12_3 456454922u
      #define m_poly_n_12_4 948582945u
      #define m_poly_n_12_5 3245368434u
      #define m_poly_s_12_0 2778765451u
      #define m_poly_s_12_1 3957846346u
      #define m_poly_s_12_2 2517222852u
      #define m_poly_s_12_3 3007729046u
      #define m_poly_s_12_4 425188166u
      #define m_poly_s_12_5 45114482u
      #define m_poly_m_12_0 3498187715u
      #define m_poly_m_12_1 4096699498u
      #define m_poly_m_12_2 3433104751u
      #define m_poly_m_12_3 3653255568u
      #define m_poly_m_12_4 2977959358u
      #define m_poly_m_12_5 3709950066u

      int poly_mult(const int*, int, const int*, int, int*);
      void poly_pack(const int*, unsigned int*, int);
      void poly_reverse(int*, int*, int);
      inline void reg_4_shift(unsigned int*);
      inline void reg_5_shift(unsigned int*);
      inline void reg_6_shift(unsigned int*);
      void bch_poly_build_tables(void);

     public:
      dvb_bch_bb_impl(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate);
      ~dvb_bch_bb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items);
    };

  } // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVB_BCH_BB_IMPL_H */

