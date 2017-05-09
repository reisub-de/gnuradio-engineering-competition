# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/digital" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/bpsk.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/constellation_map_generator.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/cpm.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/crc.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/generic_mod_demod.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/gmsk.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/gfsk.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/modulation_utils.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm_packet_utils.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm_receiver.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm_sync_fixed.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm_sync_ml.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm_sync_pnac.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm_sync_pn.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/ofdm_txrx.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/packet_utils.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/pkt.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/psk.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/psk_constellations.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/qam.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/qamlike.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/qam_constellations.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/qpsk.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/soft_dec_lut_gen.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/digital" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/bpsk.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/constellation_map_generator.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/cpm.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/crc.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/generic_mod_demod.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/gmsk.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/gfsk.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/modulation_utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_packet_utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_receiver.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_fixed.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_ml.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_pnac.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_pn.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_txrx.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/packet_utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/pkt.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/psk.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/psk_constellations.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qam.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qamlike.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qam_constellations.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qpsk.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/soft_dec_lut_gen.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/bpsk.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/constellation_map_generator.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/cpm.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/crc.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/generic_mod_demod.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/gmsk.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/gfsk.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/modulation_utils.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_packet_utils.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_receiver.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_fixed.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_ml.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_pnac.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_sync_pn.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/ofdm_txrx.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/packet_utils.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/pkt.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/psk.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/psk_constellations.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qam.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qamlike.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qam_constellations.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/qpsk.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/soft_dec_lut_gen.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/digital/utils" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/utils/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/utils/gray_code.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/utils/mod_codes.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/utils/alignment.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-digital/python/digital/utils/tagged_streams.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "digital_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/digital/utils" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/gray_code.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/mod_codes.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/alignment.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/tagged_streams.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/gray_code.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/mod_codes.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/alignment.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/python/digital/utils/tagged_streams.pyo"
    )
endif()

