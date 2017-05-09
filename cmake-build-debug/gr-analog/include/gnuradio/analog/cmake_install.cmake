# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "analog_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/analog" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/noise_source_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/noise_source_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/noise_source_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/noise_source_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/fastnoise_source_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/fastnoise_source_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/fastnoise_source_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/fastnoise_source_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/sig_source_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/sig_source_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/sig_source_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/sig_source_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/random_uniform_source_b.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/random_uniform_source_s.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/include/gnuradio/analog/random_uniform_source_i.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/cpm.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/noise_type.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/agc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/agc2.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/noise_type.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/squelch_base_ff.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/squelch_base_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/agc_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/agc_ff.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/agc2_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/agc2_ff.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/agc3_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/cpfsk_bc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/ctcss_squelch_ff.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/dpll_bb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/feedforward_agc_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/fmdet_cf.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/frequency_modulator_fc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/phase_modulator_fc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/pll_carriertracking_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/pll_freqdet_cf.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/pll_refout_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/probe_avg_mag_sqrd_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/probe_avg_mag_sqrd_cf.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/probe_avg_mag_sqrd_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/pwr_squelch_cc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/pwr_squelch_ff.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/quadrature_demod_cf.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/rail_ff.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/sig_source_waveform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/include/gnuradio/analog/simple_squelch_cc.h"
    )
endif()

