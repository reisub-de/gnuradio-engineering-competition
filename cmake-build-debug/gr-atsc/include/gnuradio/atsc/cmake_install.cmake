# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/atsc" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/basic_trellis_encoder_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/bit_timing_loop.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/consts.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/convolutional_interleaver.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/create_atsci_equalizer.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/create_atsci_fs_checker.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/create_atsci_fs_correlator.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/data_interleaver_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/deinterleaver.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/depad.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/derandomizer.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/diag_output_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/ds_to_softds.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/equalizer.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/equalizer_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/equalizer_lms2_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/equalizer_lms_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/equalizer_nop_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/fake_single_viterbi_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/field_sync_demux.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/field_sync_mux.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/fpll.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/fs_checker.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/fs_checker_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/fs_checker_naive_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/fs_correlator_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/fs_correlator_naive_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/GrAtscSegSymSyncImpl_export.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/interleaver_fifo.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/interleaver.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/pad.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/pnXXX_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/randomizer.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/randomizer_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/reed_solomon_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/rs_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/rs_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/single_viterbi_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/slicer_agc_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/sliding_correlator_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/sssr_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/syminfo_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/sync_tag_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/trellis_encoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/trellis_encoder_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/types.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/viterbi_decoder.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/include/gnuradio/atsc/viterbi_decoder_impl.h"
    )
endif()

