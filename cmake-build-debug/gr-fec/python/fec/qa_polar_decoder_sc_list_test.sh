#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec:$PATH
export LD_LIBRARY_PATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python:/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/swig:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/swig:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/swig:$PYTHONPATH
/usr/bin/python2 -B /home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/qa_polar_decoder_sc_list.py 
