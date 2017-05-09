# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-audio/examples/python

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "audio_copy.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/audio_copy.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "audio_fft.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/audio_fft.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "audio_play.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/audio_play.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "audio_to_file.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/audio_to_file.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "dial_tone.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/dial_tone.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "dial_tone_daemon.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/dial_tone_daemon.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "dial_tone_wav.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/dial_tone_wav.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "mono_tone.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/mono_tone.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "multi_tone.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/multi_tone.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "noise.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/noise.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "spectrum_inversion.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/spectrum_inversion.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "audio_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/audio" TYPE PROGRAM RENAME "test_resampler.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/examples/python/test_resampler.py.exe")
endif()

