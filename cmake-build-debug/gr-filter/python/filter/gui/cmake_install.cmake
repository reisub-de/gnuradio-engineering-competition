# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/gui

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
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/gui/bandgraphicsview.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/gui/banditems.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/gui/icons_rc.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/gui/idealbanditems.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/gui/polezero_plot.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-filter/python/filter/gui/pyqt_filter_stacked.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "filter_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/filter" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/bandgraphicsview.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/banditems.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/icons_rc.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/idealbanditems.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/polezero_plot.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/pyqt_filter_stacked.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/bandgraphicsview.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/banditems.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/icons_rc.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/idealbanditems.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/polezero_plot.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/python/filter/gui/pyqt_filter_stacked.pyo"
    )
endif()

