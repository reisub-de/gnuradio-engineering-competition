#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Vv002 Cr35L
# Generated: Tue Apr 25 10:48:31 2017
##################################################

from gnuradio import blocks
from gnuradio import digital
from gnuradio import dtv
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
from threading import Thread


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
        
        t1 = Thread(target=self.one, args=())
        t2 = Thread(target=self.two, args=())
        t3 = Thread(target=self.three, args=())
        t4 = Thread(target=self.four, args=())
        t5 = Thread(target=self.five, args=())
        t6 = Thread(target=self.six, args=())
        t7 = Thread(target=self.seven, args=())
        t8 = Thread(target=self.eight, args=())
        t9 = Thread(target=self.nine, args=())
        t10 = Thread(target=self.ten, args=())
        t11 = Thread(target=self.eleven, args=())
        t12 = Thread(target=self.twelve, args=())
        t13 = Thread(target=self.thirteen, args=())
        t14 = Thread(target=self.fourteen, args=())
        t15 = Thread(target=self.fifteen, args=())
        t1.start(); t2.start(); t3.start(); t4.start(); t5.start(), t6.start();
        t7.start(); t8.start(); t9.start(); t10.start(); t11.start();
        t12.start(); t13.start(); t14.start(); t15.start()
        t1.join(); t2.join(); t3.join(); t4.join(); t5.join(), t6.join();
        t7.join(); t8.join(); t9.join(); t10.join(); t11.join();
        t12.join(); t13.join(); t14.join(); t15.join()
        '''
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
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, input_file, False)
        self.blocks_file_sink_1 = blocks.file_sink(gr.sizeof_gr_complex*1, output_file, False)
        self.blocks_file_sink_1.set_unbuffered(False)'''

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_file_source_0, 0), (self.dtv_dvb_bbheader_bb_0, 0))
        self.connect((self.digital_ofdm_cyclic_prefixer_0, 0), (self.dtv_dvbt2_p1insertion_cc_0, 0))
        self.connect((self.dtv_dvb_bbheader_bb_0, 0), (self.dtv_dvb_bbscrambler_bb_0, 0))
        self.connect((self.dtv_dvb_bbscrambler_bb_0, 0), (self.dtv_dvb_bch_bb_0, 0))
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
        self.blocks_file_sink_1.open(self.output_file)

    def get_input_file(self):
        return self.input_file

    def set_input_file(self, input_file):
        self.input_file = input_file
        self.blocks_file_source_0.open(self.input_file, False)

    def one(self):
        self.dtv_dvbt2_pilotgenerator_cc_0 = dtv.dvbt2_pilotgenerator_cc(dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.PILOT_PP7, dtv.GI_1_128, 59, dtv.PAPR_OFF, dtv.VERSION_111, dtv.PREAMBLE_T2_SISO, dtv.MISO_TX1, dtv.EQUALIZATION_OFF, dtv.BANDWIDTH_8_0_MHZ, 32768)
    def two(self):
        self.dtv_dvbt2_p1insertion_cc_0 = dtv.dvbt2_p1insertion_cc(dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.GI_1_128, 59, dtv.PREAMBLE_T2_SISO, dtv.SHOWLEVELS_OFF, 3.3)
    def three(self):
        self.dtv_dvbt2_modulator_bc_0 = dtv.dvbt2_modulator_bc(dtv.FECFRAME_NORMAL, dtv.MOD_256QAM, dtv.ROTATION_ON)
    def four(self):
        self.dtv_dvbt2_interleaver_bb_0 = dtv.dvbt2_interleaver_bb(dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.MOD_256QAM)
    def five(self):
        self.dtv_dvbt2_freqinterleaver_cc_0 = dtv.dvbt2_freqinterleaver_cc(dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.PILOT_PP7, dtv.GI_1_128, 59, dtv.PAPR_OFF, dtv.VERSION_111, dtv.PREAMBLE_T2_SISO)
    def six(self):
        self.dtv_dvbt2_framemapper_cc_0 = dtv.dvbt2_framemapper_cc(dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.MOD_256QAM, dtv.ROTATION_ON, 202, 3, dtv.CARRIERS_EXTENDED, dtv.FFTSIZE_32K_T2GI, dtv.GI_1_128, dtv.L1_MOD_64QAM, dtv.PILOT_PP7, 2, 59, dtv.PAPR_OFF, dtv.VERSION_111, dtv.PREAMBLE_T2_SISO, dtv.INPUTMODE_NORMAL, dtv.RESERVED_OFF, dtv.L1_SCRAMBLED_OFF, dtv.INBAND_OFF)
    def seven(self):
        self.dtv_dvbt2_cellinterleaver_cc_0 = dtv.dvbt2_cellinterleaver_cc(dtv.FECFRAME_NORMAL, dtv.MOD_256QAM, 202, 3)
    def eight(self):
        self.dtv_dvb_ldpc_bb_0 = dtv.dvb_ldpc_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.MOD_OTHER)
    def nine(self):
        self.dtv_dvb_bch_bb_0 = dtv.dvb_bch_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5)
    def ten(self):
        self.dtv_dvb_bbscrambler_bb_0 = dtv.dvb_bbscrambler_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5)
    def eleven(self):
        self.dtv_dvb_bbheader_bb_0 = dtv.dvb_bbheader_bb(dtv.STANDARD_DVBT2, dtv.FECFRAME_NORMAL, dtv.C3_5, dtv.RO_0_35, dtv.INPUTMODE_HIEFF, dtv.INBAND_OFF, 168, 4000000)
    def twelve(self):
        self.digital_ofdm_cyclic_prefixer_0 = digital.ofdm_cyclic_prefixer(32768, 32768+32768/128, 0, '')
    def thirteen(self):
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, self.input_file, False)
    def fourteen(self):
        self.blocks_file_sink_1 = blocks.file_sink(gr.sizeof_gr_complex*1, self.output_file, False)
    def fifteen(self):
        self.blocks_file_sink_1.set_unbuffered(False)

def main(top_block_cls=vv002_cr35l, options=None):

    tb = top_block_cls()
    tb.start()
    tb.wait()
    bch = tb.dtv_dvb_bch_bb_0.pc_work_time_total()
    ldpc = tb.dtv_dvb_ldpc_bb_0.pc_work_time_total()
    intlbb = tb.dtv_dvbt2_interleaver_bb_0.pc_work_time_total()
    pgen = tb.dtv_dvbt2_pilotgenerator_cc_0.pc_work_time_total()
    cint = tb.dtv_dvbt2_cellinterleaver_cc_0.pc_work_time_total()
    mod = tb.dtv_dvbt2_modulator_bc_0.pc_work_time_total()
    fint = tb.dtv_dvbt2_freqinterleaver_cc_0.pc_work_time_total()
    bbh = tb.dtv_dvb_bbheader_bb_0.pc_work_time_total()
    cprf = tb.digital_ofdm_cyclic_prefixer_0.pc_work_time_total()
    fm = tb.dtv_dvbt2_framemapper_cc_0.pc_work_time_total()
    print('bch: ' + str(bch))
    print('ldpc: ' + str(ldpc))
    print('interleaver bb: ' + str(intlbb))
    print('pilot generator: ' + str(pgen))
    print('cell interleaver: ' + str(cint))
    print('modulator: ' + str(mod))
    print('frequency interleaver: ' + str(fint))
    print('bbheader: ' + str(bbh))
    print('cyclic prefixer: ' + str(cprf))
    print('frame mapper: ' + str(fm))


if __name__ == '__main__':
    main()
