# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-filter/examples

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "channelize.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/channelize.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "chirp_channelize.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/chirp_channelize.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "decimate.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/decimate.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "fft_filter_ccc.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/fft_filter_ccc.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "fir_filter_ccc.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/fir_filter_ccc.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "fir_filter_fff.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/fir_filter_fff.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "interpolate.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/interpolate.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "reconstruction.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/reconstruction.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "resampler.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/resampler.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "synth_filter.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/synth_filter.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "synth_to_chan.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/synth_to_chan.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "gr_filtdes_api.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/gr_filtdes_api.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "gr_filtdes_callback.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/gr_filtdes_callback.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "gr_filtdes_restrict.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/gr_filtdes_restrict.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE PROGRAM RENAME "gr_filtdes_live_upd.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/examples/gr_filtdes_live_upd.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/filter" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/examples/filter_taps.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/examples/resampler_demo.grc"
    )
endif()

