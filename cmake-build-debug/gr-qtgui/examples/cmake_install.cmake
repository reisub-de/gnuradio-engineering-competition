# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-qtgui/examples

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_const_c.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_const_c.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_example_c.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_example_c.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_example_f.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_example_f.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_freq_c.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_freq_c.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_freq_f.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_freq_f.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_histogram_f.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_histogram_f.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_time_c.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_time_c.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_time_f.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_time_f.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_time_raster_b.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_time_raster_b.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_time_raster_f.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_time_raster_f.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_waterfall_c.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_waterfall_c.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE PROGRAM RENAME "pyqt_waterfall_f.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/examples/pyqt_waterfall_f.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "qtgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/qt-gui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/examples/qtgui_tags_viewing.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/examples/qtgui_vector_sink_example.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/examples/qtgui_message_inputs.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-qtgui/examples/test_qtgui_msg.grc"
    )
endif()

