# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "trellis_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/grc/blocks" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_encoder_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_siso_combined_f.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_viterbi_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_metrics_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_siso_f.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_permutation.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_viterbi_combined_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_sccc_encoder_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_sccc_decoder_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_sccc_decoder_combined_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_pccc_encoder_xx.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_pccc_decoder_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-trellis/grc/trellis_pccc_decoder_combined_xx.xml"
    )
endif()

