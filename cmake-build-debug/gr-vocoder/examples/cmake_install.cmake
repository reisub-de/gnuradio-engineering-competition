# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-vocoder/examples

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "alaw_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/alaw_audio_loopback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "codec2_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/codec2_audio_loopback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "cvsd_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/cvsd_audio_loopback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "g721_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/g721_audio_loopback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "g723_24_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/g723_24_audio_loopback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "g723_40_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/g723_40_audio_loopback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "gsm_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/gsm_audio_loopback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "vocoder_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/vocoder" TYPE PROGRAM RENAME "ulaw_audio_loopback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/examples/ulaw_audio_loopback.py.exe")
endif()

