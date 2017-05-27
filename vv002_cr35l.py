#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Vv002 Cr35L
# Generated: Thu May 18 10:13:47 2017
##################################################

from gnuradio import blocks
from gnuradio import digital
from gnuradio import dtv
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from optparse import OptionParser


def main():
    output_file = "gr_tp19.dat"
    input_file = "tp1.ts"
    tb = dtv.dvbt2_encoder_comp(input_file, output_file)
    tb.start()
    tb.wait()


if __name__ == '__main__':
    main()
