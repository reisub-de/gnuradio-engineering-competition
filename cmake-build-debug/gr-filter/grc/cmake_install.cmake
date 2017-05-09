# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-filter/grc

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/grc/blocks" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_block_tree.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_dc_blocker_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_fft_filter_xxx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_fir_filter_xxx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_filter_delay_fc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_filterbank_vcvcf.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_fractional_interpolator_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_fractional_resampler_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_freq_xlating_fft_filter_ccc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_freq_xlating_fir_filter_xxx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_hilbert_fc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_iir_filter_xxx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_interp_fir_filter_xxx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_pfb_arb_resampler.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_pfb_channelizer.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_pfb_channelizer_hier.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_pfb_decimator.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_pfb_interpolator.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_pfb_synthesizer.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_rational_resampler_xxx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_rational_resampler_base_xxx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_single_pole_iir_filter_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_low_pass_filter.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_high_pass_filter.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_band_pass_filter.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_band_reject_filter.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/filter_root_raised_cosine_filter.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/variable_low_pass_filter_taps.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/variable_high_pass_filter_taps.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/variable_band_pass_filter_taps.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/variable_band_reject_filter_taps.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/grc/variable_rrc_filter_taps.xml"
    )
endif()

