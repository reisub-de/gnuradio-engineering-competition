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
#include "dvbt2_encoder_comp_impl.h"

namespace gr {
  namespace dtv {

    dvbt2_encoder_comp::sptr
    dvbt2_encoder_comp::make(const char *input_file, const char *output_file)
    {
      return gnuradio::get_initial_sptr
        (new dvbt2_encoder_comp_impl(input_file, output_file));
    }

    /*
     * The private constructor
     */
    dvbt2_encoder_comp_impl::dvbt2_encoder_comp_impl(const char *input_file, const char *output_file)
      : gr::hier_block2("dvbt2_encoder_comp",
              gr::io_signature::make(1, 1, sizeof(char)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {
      /*************************************************
      * Blocks
      *************************************************/
      dtv::dvbt2_pilotgenerator_cc::sptr         dvbt2_pilotgenerator_cc_0(dtv::CARRIERS_EXTENDED, dtv::FFTSIZE_32K_T2GI, dtv::PILOT_PP7, dtv::GI_1_128, 59, dtv::PAPR_OFF, dtv::VERSION_111, dtv::PREAMBLE_T2_SISO, dtv::MISO_TX1, dtv::EQUALIZATION_OFF, dtv::BANDWIDTH_8_0_MHZ, 32768);
      dtv::dvbt2_p1insertion_cc::sptr            dvbt2_p1insertion_cc_0(dtv::CARRIERS_EXTENDED, dtv::FFTSIZE_32K_T2GI, dtv::GI_1_128, 59, dtv::PREAMBLE_T2_SISO, dtv::SHOWLEVELS_OFF, 3.3);
      dtv::dvbt2_modulator_bc::sptr              dvbt2_modulator_bc_0(dtv::FECFRAME_NORMAL, dtv::MOD_256QAM, dtv::ROTATION_ON);
      dtv::dvbt2_interleaver_bb::sptr            dvbt2_interleaver_bb_0(dtv::FECFRAME_NORMAL, dtv::C3_5, dtv::MOD_256QAM);
      dtv::dvbt2_freqinterleaver_cc::sptr        dvbt2_freqinterleaver_cc_0(dtv::CARRIERS_EXTENDED, dtv::FFTSIZE_32K_T2GI, dtv::PILOT_PP7, dtv::GI_1_128, 59, dtv::PAPR_OFF, dtv::VERSION_111, dtv::PREAMBLE_T2_SISO);
      dtv::dvbt2_framemapper_cc::sptr            dvbt2_framemapper_cc_0(dtv::FECFRAME_NORMAL, dtv::C3_5, dtv::MOD_256QAM, dtv::ROTATION_ON, 202, 3, dtv::CARRIERS_EXTENDED, dtv::FFTSIZE_32K_T2GI, dtv::GI_1_128, dtv::L1_MOD_64QAM, dtv::PILOT_PP7, 2, 59, dtv::PAPR_OFF, dtv::VERSION_111, dtv::PREAMBLE_T2_SISO, dtv::INPUTMODE_NORMAL, dtv::RESERVED_OFF, dtv::L1_SCRAMBLED_OFF, dtv::INBAND_OFF);
      dtv::dvbt2_cellinterleaver_cc::sptr        dvbt2_cellinterleaver_cc_0(dtv::FECFRAME_NORMAL, dtv::MOD_256QAM, 202, 3);
      dtv::dvb_ldpc_bb::sptr                     dvb_ldpc_bb_0(dtv::STANDARD_DVBT2, dtv::FECFRAME_NORMAL, dtv::C3_5, dtv::MOD_OTHER);
      dtv::dvb_bch_bb::sptr                      dvb_bch_bb_0(dtv::STANDARD_DVBT2, dtv::FECFRAME_NORMAL, dtv::C3_5);
      dtv::dvb_bbscrambler_bb::sptr              dvb_bbscrambler_bb_0(dtv::STANDARD_DVBT2, dtv::FECFRAME_NORMAL, dtv::C3_5);
      dtv::dvb_bbheader_bb::sptr                 dvb_bbheader_bb_0(dtv::STANDARD_DVBT2, dtv::FECFRAME_NORMAL, dtv::C3_5, dtv::RO_0_35, dtv::INPUTMODE_HIEFF, dtv::INBAND_OFF, 168, 4000000);
      digital::ofdm_cyclic_prefixer::sptr        ofdm_cyclic_prefixer_0(32768, 32768+32768/128, 0);
      //blocks::file_source::sptr                  file_source_0(sizeof(char)*1, input_file, false);
      //blocks::file_sink::sptr                    file_sink_1(sizeof(gr_complex)*1, output_file, false);
      //file_sink_1.set_unbuffered(false);

      /*************************************************
      * Connections
      *************************************************/
      //connect(file_source_0, 0, dvb_bbheader_bb_0, 0);
      connect(self(), 0, dvb_bbheader_bb_0, 0);
      connect(ofdm_cyclic_prefixer_0, 0, dvbt2_p1insertion_cc_0, 0);
      connect(dvb_bbheader_bb_0, 0, dvb_bbscrambler_bb_0, 0);
      connect(dvb_bbscrambler_bb_0, 0, dvb_bch_bb_0, 0);
      connect(dvb_bch_bb_0, 0, dvb_ldpc_bb_0, 0);
      connect(dvb_ldpc_bb_0, 0, dvbt2_interleaver_bb_0, 0);
      connect(dvbt2_cellinterleaver_cc_0, 0, dvbt2_framemapper_cc_0, 0);
      connect(dvbt2_framemapper_cc_0, 0, dvbt2_freqinterleaver_cc_0, 0);
      connect(dvbt2_freqinterleaver_cc_0, 0, dvbt2_pilotgenerator_cc_0, 0);
      connect(dvbt2_interleaver_bb_0, 0, dvbt2_modulator_bc_0, 0);
      connect(dvbt2_modulator_bc_0, 0, dvbt2_cellinterleaver_cc_0, 0);
      //connect(dvbt2_p1insertion_cc_0, 0, file_sink_1, 0);
      connect(dvbt2_p1insertion_cc_0, 0, self(), 0);
      connect(dvbt2_pilotgenerator_cc_0, 0, ofdm_cyclic_prefixer_0, 0);
    }

    /*
     * Our virtual destructor.
     */
    dvbt2_encoder_comp_impl::~dvbt2_encoder_comp_impl()
    {
    }


  } /* namespace dtv */
} /* namespace gr */
