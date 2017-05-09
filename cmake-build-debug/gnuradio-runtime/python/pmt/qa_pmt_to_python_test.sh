#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/pmt
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/pmt:$PATH
export LD_LIBRARY_PATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/swig:$PYTHONPATH
/usr/bin/python2 -B /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/pmt/qa_pmt_to_python.py 
