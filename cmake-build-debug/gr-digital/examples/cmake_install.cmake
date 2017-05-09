# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-digital/examples

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital" TYPE PROGRAM RENAME "example_costas.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/example_costas.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital" TYPE PROGRAM RENAME "example_fll.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/example_fll.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital" TYPE PROGRAM RENAME "example_timing.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/example_timing.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital" TYPE PROGRAM RENAME "run_length.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/run_length.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital" TYPE PROGRAM RENAME "gen_whitener.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/gen_whitener.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital" TYPE PROGRAM RENAME "snr_estimators.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/snr_estimators.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/burst_shaper.grc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "transmit_path.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/transmit_path.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "receive_path.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/receive_path.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "uhd_interface.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/uhd_interface.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "benchmark_tx.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/benchmark_tx.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "benchmark_rx.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/benchmark_rx.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "tx_voice.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/tx_voice.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "rx_voice.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/rx_voice.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "digital_bert_rx.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/digital_bert_rx.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "digital_bert_tx.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/digital_bert_tx.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/narrowband" TYPE PROGRAM RENAME "tunnel.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/narrowband/tunnel.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "benchmark_add_channel.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/benchmark_add_channel.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "benchmark_rx.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/benchmark_rx.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "benchmark_tx.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/benchmark_tx.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "gr_plot_ofdm.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/gr_plot_ofdm.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "receive_path.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/receive_path.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "transmit_path.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/transmit_path.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "tunnel.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/tunnel.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE PROGRAM RENAME "uhd_interface.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/examples/ofdm/uhd_interface.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/ofdm" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/ofdm/tx_ofdm.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/ofdm/rx_ofdm.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/ofdm/ofdm_loopback.grc"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/demod" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/constellation_soft_decoder.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/digital_freq_lock.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/mpsk_demod.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/pam_sync.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/pam_timing.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/ber_simulation.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/dpsk_loopback.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/gfsk_loopback.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/test_corr_and_sync.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/test_corr_est.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/uhd_corr_and_sync_tx.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/demod/uhd_corr_and_sync_rx.grc"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/digital/packet" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/burst_tagger.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/example_corr_est_and_clock_sync.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/example_corr_est_and_phase_sync.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/example_corr_est.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/formatter_crc.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/formatter_ofdm.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/packet_loopback_hier.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/packet_rx.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/packet_tx.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/simple_bpsk_tx.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/transmitter_sim_hier.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage0.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage1.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage2.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage3.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage4.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage5.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage6a.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/tx_stage6.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/uhd_packet_rx.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/uhd_packet_rx_tun.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/uhd_packet_tx.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/examples/packet/uhd_packet_tx_tun.grc"
    )
endif()

