# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/vocoder" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/alaw_decode_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/alaw_encode_sb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/cvsd_decode_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/cvsd_encode_sb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/g721_decode_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/g721_encode_sb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/g723_24_decode_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/g723_24_encode_sb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/g723_40_decode_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/g723_40_encode_sb.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/gsm_fr_decode_ps.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/gsm_fr_encode_sp.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/ulaw_decode_bs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-vocoder/include/gnuradio/vocoder/ulaw_encode_sb.h"
    )
endif()

