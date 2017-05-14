#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Vv002 Cr35L
# Generated: Mon May  1 19:10:52 2017
##################################################

from gnuradio import blocks
from gnuradio import digital
from gnuradio import dtv
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser
import sys
from operator import itemgetter


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
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, input_file, False)
        self.blocks_file_sink_1 = blocks.file_sink(gr.sizeof_gr_complex*1, output_file, False)
        self.blocks_file_sink_1.set_unbuffered(False)

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


def printProgressBar (iteration, total, prefix = '', suffix = '', decimals = 1, length = 100, fill = '█'):
    """
    Call in a loop to create terminal progress bar
    @params:
        iteration   - Required  : current iteration (Int)
        total       - Required  : total iterations (Int)
        prefix      - Optional  : prefix string (Str)
        suffix      - Optional  : suffix string (Str)
        decimals    - Optional  : positive number of decimals in percent complete (Int)
        length      - Optional  : character length of bar (Int)
        fill        - Optional  : bar fill character (Str)
    """
    percent = ("{0:." + str(decimals) + "f}").format(100 * (iteration / float(total)))
    filledLength = int(length * iteration // total)
    bar = fill * filledLength + '-' * (length - filledLength)
    sys.stdout.write('\r%s |%s| %s%% %s' % (prefix, bar, percent, suffix))
    sys.stdout.flush()

    # Print New Line on Complete
    if iteration == total: 
        print()
        print()

def main(top_block_cls=vv002_cr35l, options=None):
    
    t0=['BBheader', 0]
    t1=['BBscrambler', 0]
    t2=['BCH Encoder', 0]
    t3=['LDPC Encoder', 0]
    t4=['Bit Interleaver', 0]
    t5=['DVB-T2 Modulator', 0]
    t6=['Cell/Time Interleaver', 0]
    t7=['Frame Mapper', 0]
    t8=['Frequency Interleaver', 0]
    t9=['Pilot Generator and IFFT', 0]
    t10=['OFDM Cyclic Prefixer', 0]
    t11=['P1 Symbol Insertion', 0]
    times = [t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11]

    repetitions = 150
    for i in range(1, repetitions +1):
        tb = top_block_cls()
        tb.start()
        tb.wait()
        times[0][1] = times[0][1] + tb.dtv_dvb_bbheader_bb_0.pc_work_time_total()
        times[1][1] = times[1][1] + tb.dtv_dvb_bbscrambler_bb_0.pc_work_time_total()
        times[2][1] = times[2][1] + tb.dtv_dvb_bch_bb_0.pc_work_time_total()
        times[3][1] = times[3][1] + tb.dtv_dvb_ldpc_bb_0.pc_work_time_total()
        times[4][1] = times[4][1] + tb.dtv_dvbt2_interleaver_bb_0.pc_work_time_total()
        times[5][1] = times[5][1] + tb.dtv_dvbt2_modulator_bc_0.pc_work_time_total()
        times[6][1] = times[6][1] + tb.dtv_dvbt2_cellinterleaver_cc_0.pc_work_time_total()
        times[7][1] = times[7][1] + tb.dtv_dvbt2_framemapper_cc_0.pc_work_time_total()
        times[8][1] = times[8][1] + tb.dtv_dvbt2_freqinterleaver_cc_0.pc_work_time_total()
        times[9][1] = times[9][1] + tb.dtv_dvbt2_pilotgenerator_cc_0.pc_work_time_total()
        times[10][1] = times[10][1] + tb.digital_ofdm_cyclic_prefixer_0.pc_work_time_total()
        times[11][1] = times[11][1] + tb.dtv_dvbt2_p1insertion_cc_0.pc_work_time_total()
        printProgressBar(i, repetitions, prefix = 'Progress:', suffix = 'Complete', length = 50)

    times.sort(key=itemgetter(1), reverse=True)
    print("Functions\t\t\t\t\tTime")
    print("----------------------------  ----------------------")
    for element in times:
        print("{0:<25}".format(element[0] + ":") + "{0:>25}".format(str(element[1]/repetitions)) )


if __name__ == '__main__':
    main()
