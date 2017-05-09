# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/filter" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/filterbank.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/freq_xlating_fft_filter.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/optfir.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/pfb.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/rational_resampler.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/filter" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/filterbank.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/freq_xlating_fft_filter.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/optfir.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/pfb.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/rational_resampler.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/filterbank.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/freq_xlating_fft_filter.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/optfir.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/pfb.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/rational_resampler.pyo"
    )
endif()

