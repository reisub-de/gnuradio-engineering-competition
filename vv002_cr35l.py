#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Vv002 Cr35L
# Generated: Mon May 22 22:40:58 2017
##################################################

from gnuradio import blocks
from gnuradio import digital
from gnuradio import dtv
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser


class vv002_cr35l(gr.top_block):

    def __init__(self):
        gr.top_block.__init__(self, "Vv002 Cr35L")

        ##################################################
        # Variables
        ##################################################
        self.output_file = output_file = "gr_tp19.dat"
        self.input_file = input_file = "tp1.ts"

        ##################################################
        # Blocks
        ##################################################
        self.dtv_dvbt2_pilotgenerator_cc_0 = dtv.dvbt2_pilotgenerator_cc(dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.PILOT_PP7, dtv.GI_1_128, 59, dtv.PAPR_OFF, dtv.VERSION_111, dtv.PREAMBLE_T2_SISO, dtv.MISO_TX1, dtv.EQUALIZATION_OFF, dtv.BANDWIDTH_8_0_MHZ, 32768)
        self.dtv_dvbt2_p1insertion_cc_0 = dtv.dvbt2_p1insertion_cc(dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.GI_1_128, 59, dtv.PREAMBLE_T2_SISO, dtv.SHOWLEVELS_OFF, 3.3)
        self.dtv_dvbt2_modulator_bc_0 = dtv.dvbt2_modulator_bc(dtv.FECFRAME_NORMAL, dtv.MOD_256QAM, dtv.ROTATION_ON)
        self.dtv_dvbt2_interleaver_bb_0 = dtv.dvbt2_interleaver_bb(dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.MOD_256QAM)
        self.dtv_dvbt2_freqinterleaver_cc_0 = dtv.dvbt2_freqinterleaver_cc(dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.PILOT_PP7, dtv.GI_1_128, 59, dtv.PAPR_OFF, dtv.VERSION_111, dtv.PREAMBLE_T2_SISO)
        self.dtv_dvbt2_framemapper_cc_0 = dtv.dvbt2_framemapper_cc(dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.MOD_256QAM, dtv.ROTATION_ON, 202, 3, dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.GI_1_128, dtv.L1_MOD_64QAM, dtv.PILOT_PP7, 2, 59, dtv.PAPR_OFF, dtv.VERSION_111, dtv.PREAMBLE_T2_SISO, dtv.INPUTMODE_NORMAL, dtv.RESERVED_OFF, dtv.L1_SCRAMBLED_OFF, dtv.INBAND_OFF)
        self.dtv_dvbt2_cellinterleaver_cc_0 = dtv.dvbt2_cellinterleaver_cc(dtv.FECFRAME_NORMAL, dtv.MOD_256QAM, 202, 3)
        self.dtv_dvb_ldpc_bb_0 = dtv.dvb_ldpc_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.MOD_OTHER)
        self.dtv_dvb_bch_bb_0 = dtv.dvb_bch_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5)
        self.dtv_dvb_bbscrambler_bb_0 = dtv.dvb_bbscrambler_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5)
        self.dtv_dvb_bbheader_bb_0 = dtv.dvb_bbheader_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.RO_0_35, dtv.INPUTMODE_HIEFF, dtv.INBAND_OFF, 168, 4000000)
        self.digital_ofdm_cyclic_prefixer_0 = digital.ofdm_cyclic_prefixer(32768, 32768+32768/128, 0, '')
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, '/home/simon/rs_competition/tools/tp1.ts', False)
        self.blocks_file_sink_1_0_0 = blocks.file_sink(gr.sizeof_char*1, '/home/simon/rs_competition/test_outputs/bch_out.dat', False)
        self.blocks_file_sink_1_0_0.set_unbuffered(False)
        self.blocks_file_sink_1_0 = blocks.file_sink(gr.sizeof_char*1, '/home/simon/rs_competition/test_outputs/bch_in.dat', False)
        self.blocks_file_sink_1_0.set_unbuffered(False)
        self.blocks_file_sink_1 = blocks.file_sink(gr.sizeof_gr_complex*1, '/home/simon/rs_competition/tools/test_output.dat', False)
        self.blocks_file_sink_1.set_unbuffered(False)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_file_source_0, 0), (self.dtv_dvb_bbheader_bb_0, 0))
        self.connect((self.digital_ofdm_cyclic_prefixer_0, 0), (self.dtv_dvbt2_p1insertion_cc_0, 0))
        self.connect((self.dtv_dvb_bbheader_bb_0, 0), (self.dtv_dvb_bbscrambler_bb_0, 0))
        self.connect((self.dtv_dvb_bbscrambler_bb_0, 0), (self.blocks_file_sink_1_0, 0))
        self.connect((self.dtv_dvb_bbscrambler_bb_0, 0), (self.dtv_dvb_bch_bb_0, 0))
        self.connect((self.dtv_dvb_bch_bb_0, 0), (self.blocks_file_sink_1_0_0, 0))
        self.connect((self.dtv_dvb_bch_bb_0, 0), (self.dtv_dvb_ldpc_bb_0, 0))
        self.connect((self.dtv_dvb_ldpc_bb_0, 0), (self.dtv_dvbt2_interleaver_bb_0, 0))
        self.connect((self.dtv_dvbt2_cellinterleaver_cc_0, 0), (self.dtv_dvbt2_framemapper_cc_0, 0))
        self.connect((self.dtv_dvbt2_framemapper_cc_0, 0), (self.dtv_dvbt2_freqinterleaver_cc_0, 0))
        self.connect((self.dtv_dvbt2_freqinterleaver_cc_0, 0), (self.dtv_dvbt2_pilotgenerator_cc_0, 0))
        self.connect((self.dtv_dvbt2_interleaver_bb_0, 0), (self.dtv_dvbt2_modulator_bc_0, 0))
        self.connect((self.dtv_dvbt2_modulator_bc_0, 0), (self.dtv_dvbt2_cellinterleaver_cc_0, 0))
        self.connect((self.dtv_dvbt2_p1insertion_cc_0, 0), (self.blocks_file_sink_1, 0))
        self.connect((self.dtv_dvbt2_pilotgenerator_cc_0, 0), (self.digital_ofdm_cyclic_prefixer_0, 0))

    def get_output_file(self):
        return self.output_file

    def set_output_file(self, output_file):
        self.output_file = output_file

    def get_input_file(self):
        return self.input_file

    def set_input_file(self, input_file):
        self.input_file = input_file


def main(top_block_cls=vv002_cr35l, options=None):

    tb = top_block_cls()
    tb.start()
    tb.wait()

    print "--> Performance Measurements <--"
    print("digital_ofdm_cyclic_prefixer {0}").format(tb.digital_ofdm_cyclic_prefixer_0.pc_work_time_total())
    print("tv_dvb_bbheader_bb 		{0}").format(tb.dtv_dvb_bbheader_bb_0.pc_work_time_total())
    print("dtv_dvb_bbscrambler 		{0}").format(tb.dtv_dvb_bbscrambler_bb_0.pc_work_time_total())
    print("dtv_dvb_bch_bb		{0}").format(tb.dtv_dvb_bch_bb_0.pc_work_time_total())
    print("dtv_dvb_ldpc_bb 		{0}").format(tb.dtv_dvb_ldpc_bb_0.pc_work_time_total())
    print("dtv_dvbt2_cellinterleaver 	{0}").format(tb.dtv_dvbt2_cellinterleaver_cc_0.pc_work_time_total())
    print("dtv_dvbt2_framemapper_cc 	{0}").format(tb.dtv_dvbt2_framemapper_cc_0.pc_work_time_total())
    print("dtv_dvbt2_freqinterleaver 	{0}").format(tb.dtv_dvbt2_freqinterleaver_cc_0.pc_work_time_total())
    print("dtv_dvbt2_interleaver_bb 	{0}").format(tb.dtv_dvbt2_interleaver_bb_0.pc_work_time_total())
    print("dtv_dvbt2_modulator_bc	{0}").format(tb.dtv_dvbt2_modulator_bc_0.pc_work_time_total())
    print("dtv_dvbt2_p1insertion_cc 	{0}").format(tb.dtv_dvbt2_p1insertion_cc_0.pc_work_time_total())
    print("tv_dvbt2_pilotgenerator 	{0}").format(tb.dtv_dvbt2_pilotgenerator_cc_0.pc_work_time_total())



if __name__ == '__main__':
    main()
