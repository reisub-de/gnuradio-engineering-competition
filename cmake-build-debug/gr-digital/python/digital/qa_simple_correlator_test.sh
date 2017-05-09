#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH
export PYTHONPATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python:$PYTHONPATH
/usr/bin/python2 -B /home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/qa_simple_correlator.py 
