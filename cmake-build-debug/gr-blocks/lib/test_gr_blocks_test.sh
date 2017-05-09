#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/zhiwei/WorkSpace/gnuradio/gr-blocks/lib
export GR_CONF_CONTROLPORT_ON=False
export PATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/lib:$PATH
export LD_LIBRARY_PATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/lib:$LD_LIBRARY_PATH
export PYTHONPATH=/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python:/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/swig:$PYTHONPATH
test-gr-blocks 
