# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "dtv_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/grc/blocks" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_deinterleaver.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_depad.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_derandomizer.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_equalizer.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_fpll.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_fs_checker.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_rs_decoder.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_rx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_rx_filter.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_sync.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_viterbi_decoder.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_block_tree.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_pad.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_randomizer.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_rs_encoder.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_interleaver.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_trellis_encoder.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_atsc_field_sync_mux.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvb_bbheader_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvb_bbscrambler_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvb_bch_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvb_ldpc_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_interleaver_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_modulator_bc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_cellinterleaver_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_framemapper_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_freqinterleaver_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_pilotgenerator_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_paprtr_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_p1insertion_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt2_miso_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbs2_interleaver_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbs2_modulator_bc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbs2_physical_cc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_energy_dispersal.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_reed_solomon_enc.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_convolutional_interleaver.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_inner_coder.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_bit_inner_interleaver.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_symbol_inner_interleaver.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_map.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_reference_signals.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_ofdm_sym_acquisition.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_demod_reference_signals.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_demap.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_bit_inner_deinterleaver.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_viterbi_decoder.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_convolutional_deinterleaver.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_reed_solomon_dec.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_dvbt_energy_descramble.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_catv_transport_framing_enc_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_catv_reed_solomon_enc_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_catv_randomizer_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_catv_frame_sync_enc_bb.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-dtv/grc/dtv_catv_trellis_enc_bb.xml"
    )
endif()

