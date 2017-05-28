/* -*- c++ -*- */
/* 
 * Copyright 2017 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "competition_impl.h"

#include <stdio.h>  

namespace gr {
  namespace dtv {

    competition::sptr
    competition::make(int placeholder)
    {
      return gnuradio::get_initial_sptr
        (new competition_impl(placeholder));
    }

    /*
     * The private constructor
     */
    competition_impl::competition_impl(int placeholder)
      : gr::block("competition",
                  gr::io_signature::make(1, 1, sizeof(unsigned char)), // input signature
                  gr::io_signature::make(1, 1, sizeof(unsigned char))) // output signature
    {
      bbheader = new gr::dtv::dvb_bbheader_bb_impl(
                                                STANDARD_DVBT2,
                                                FECFRAME_NORMAL,
                                                C3_5,
                                                RO_0_35, 
                                                INPUTMODE_HIEFF, 
                                                INBAND_OFF, 
                                                168, 
                                                4000000
                                                );
    }

    /*
     * Our virtual destructor.
     */
    competition_impl::~competition_impl()
    {
      delete bbheader;
    }

    void
    competition_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      bbheader->forecast(noutput_items, ninput_items_required);
    }

    int
    competition_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      int consumed = bbheader->general_work(
        noutput_items,
        ninput_items,
        input_items,
        output_items);

      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (consumed);
      return noutput_items;
    }
  } /* namespace dtv */
} /* namespace gr */

