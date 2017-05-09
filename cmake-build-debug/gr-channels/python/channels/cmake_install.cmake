# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "channels_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/channels" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/amp_bal.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/conj_fs_iqcorr.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/distortion_2_gen.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/distortion_3_gen.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/impairments.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/iqbal_gen.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/phase_bal.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/phase_noise_gen.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/python/channels/quantizer.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "channels_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/channels" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/amp_bal.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/conj_fs_iqcorr.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/distortion_2_gen.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/distortion_3_gen.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/impairments.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/iqbal_gen.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/phase_bal.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/phase_noise_gen.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/quantizer.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/amp_bal.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/conj_fs_iqcorr.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/distortion_2_gen.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/distortion_3_gen.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/impairments.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/iqbal_gen.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/phase_bal.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/phase_noise_gen.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/quantizer.pyo"
    )
endif()

