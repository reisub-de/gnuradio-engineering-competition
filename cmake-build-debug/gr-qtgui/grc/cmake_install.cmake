# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/grc/blocks" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_ber_sink_b.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_block_tree.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_check_box.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_chooser.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_const_sink_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_edit_box_msg.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_entry.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_freq_sink_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_histogram_sink_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_label.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_number_sink.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_push_button.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_range.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_sink_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_tab_widget.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_time_raster_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_time_sink_x.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_vector_sink_f.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/grc/qtgui_waterfall_sink_x.xml"
    )
endif()

