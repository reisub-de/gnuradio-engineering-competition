# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "trellis_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/trellis" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/encoder_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/encoder_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/encoder_bi.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/encoder_ss.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/encoder_si.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/encoder_ii.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_encoder_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_encoder_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_encoder_bi.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_encoder_ss.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_encoder_si.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_encoder_ii.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_encoder_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_encoder_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_encoder_bi.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_encoder_ss.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_encoder_si.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_encoder_ii.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/metrics_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/metrics_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/metrics_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/metrics_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_b.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_sb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_ss.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_si.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_ib.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_is.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_ii.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_fb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_fs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_fi.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_cb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_cs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/viterbi_combined_ci.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_b.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_combined_fb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_combined_fs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_combined_fi.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_combined_cb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_combined_cs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/sccc_decoder_combined_ci.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_b.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_combined_fb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_combined_fs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_combined_fi.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_combined_cb.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_combined_cs.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/include/gnuradio/trellis/pccc_decoder_combined_ci.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/base.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/calc_metric.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/constellation_metrics_cf.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/core_algorithms.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/fsm.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/interleaver.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/permutation.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/quicksort_index.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/siso_type.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/siso_combined_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/include/gnuradio/trellis/siso_f.h"
    )
endif()

