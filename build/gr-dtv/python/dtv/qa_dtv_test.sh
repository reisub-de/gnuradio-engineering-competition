#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/rabih9780/gnuradio/gr-dtv/python/dtv
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/rabih9780/gnuradio/build/gr-dtv/python/dtv:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH
export PYTHONPATH=/home/rabih9780/gnuradio/build/gnuradio-runtime/python:$PYTHONPATH
/usr/bin/python2 -B /home/rabih9780/gnuradio/gr-dtv/python/dtv/qa_dtv.py 
