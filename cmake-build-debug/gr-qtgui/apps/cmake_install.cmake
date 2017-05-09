# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/qtgui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_psd_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_spectrogram_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_time_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_time_raster_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_form.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_constellation_form.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_psd_form.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_spectrogram_form.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_time_form.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/apps/plot_time_raster_form.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/qtgui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_psd_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_spectrogram_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_raster_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_form.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_constellation_form.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_psd_form.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_spectrogram_form.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_form.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_raster_form.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_psd_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_spectrogram_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_raster_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_form.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_constellation_form.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_psd_form.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_spectrogram_form.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_form.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/plot_time_raster_form.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_time_plot_c" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_time_plot_c.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_time_plot_f" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_time_plot_f.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_time_plot_i" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_time_plot_i.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_time_plot_s" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_time_plot_s.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_time_plot_b" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_time_plot_b.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_time_raster_f" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_time_raster_f.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_time_raster_b" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_time_raster_b.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_psd_plot_c" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_psd_plot_c.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_psd_plot_f" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_psd_plot_f.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_psd_plot_i" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_psd_plot_i.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_psd_plot_s" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_psd_plot_s.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_psd_plot_b" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_psd_plot_b.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_spectrogram_plot_c" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_spectrogram_plot_c.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_spectrogram_plot_f" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_spectrogram_plot_f.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_spectrogram_plot_i" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_spectrogram_plot_i.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_spectrogram_plot_s" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_spectrogram_plot_s.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_spectrogram_plot_b" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_spectrogram_plot_b.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_spectrogram_plot" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_spectrogram_plot.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "gr_constellation_plot" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/apps/gr_constellation_plot.exe")
endif()

