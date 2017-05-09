# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/grc/blocks" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/notebook.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/variable_check_box.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/variable_chooser.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/variable_slider.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/variable_static_text.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/variable_text_box.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/wxgui_constellationsink2.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/wxgui_fftsink2.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/wxgui_histosink2.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/wxgui_numbersink2.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/wxgui_scopesink2.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/wxgui_termsink.xml"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/wxgui_waterfallsink2.xml"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/grc_gnuradio/wxgui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/panel.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/grc/top_block_gui.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/grc_gnuradio/wxgui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/grc/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/grc/panel.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/grc/top_block_gui.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/grc/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/grc/panel.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/grc/top_block_gui.pyo"
    )
endif()

