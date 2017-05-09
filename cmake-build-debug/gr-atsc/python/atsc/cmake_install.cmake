# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-atsc/python/atsc

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/python/atsc/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/python/atsc/atsc_utils.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/python/atsc/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/python/atsc/atsc_utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/python/atsc/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/python/atsc/atsc_utils.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/atsc" TYPE PROGRAM RENAME "atsc_rx.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/python/atsc/atsc_rx.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_examples" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/atsc" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/python/atsc/README")
endif()

