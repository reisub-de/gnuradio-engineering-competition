# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/qtgui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/ber_sink_b.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/CMakeLists.txt"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/constellationdisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/ConstellationDisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/const_sink_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/displayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/DisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/form_menus.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/freqdisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/freqcontrolpanel.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/freq_sink_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/freq_sink_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/FrequencyDisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/histogram_sink_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/histogramdisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/HistogramDisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/edit_box_msg.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/number_sink.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/numberdisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/plot_raster.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/plot_waterfall.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/qtgui_types.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/sink_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/sink_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/spectrumUpdateEvents.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/timedisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/timecontrolpanel.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/TimeDomainDisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/timerasterdisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/TimeRasterDisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/timeRasterGlobalData.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/time_raster_sink_b.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/time_raster_sink_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/time_sink_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/time_sink_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/trigger_mode.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/utils.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/waterfalldisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/WaterfallDisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/waterfallGlobalData.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/waterfall_sink_c.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/waterfall_sink_f.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/vectordisplayform.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/VectorDisplayPlot.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/include/gnuradio/qtgui/vector_sink_f.h"
    )
endif()

