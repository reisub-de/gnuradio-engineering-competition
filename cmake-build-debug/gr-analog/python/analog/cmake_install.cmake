# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "analog_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/analog" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/am_demod.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/fm_demod.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/fm_emph.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/nbfm_rx.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/nbfm_tx.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/standard_squelch.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/wfm_rcv.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/wfm_rcv_fmdet.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/wfm_rcv_pll.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-analog/python/analog/wfm_tx.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "analog_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/analog" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/am_demod.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/fm_demod.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/fm_emph.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/nbfm_rx.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/nbfm_tx.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/standard_squelch.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_rcv.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_rcv_fmdet.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_rcv_pll.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_tx.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/am_demod.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/fm_demod.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/fm_emph.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/nbfm_rx.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/nbfm_tx.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/standard_squelch.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_rcv.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_rcv_fmdet.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_rcv_pll.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/python/analog/wfm_tx.pyo"
    )
endif()

