# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-blocks/python/grc_gnuradio

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "blocks_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/grc_gnuradio" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/python/grc_gnuradio/__init__.py")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "blocks_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/grc_gnuradio" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/__init__.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "blocks_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/grc_gnuradio/blks2" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/python/grc_gnuradio/blks2/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/python/grc_gnuradio/blks2/error_rate.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/python/grc_gnuradio/blks2/selector.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/python/grc_gnuradio/blks2/tcp.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "blocks_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/grc_gnuradio/blks2" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/error_rate.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/selector.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/tcp.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/error_rate.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/selector.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/python/grc_gnuradio/blks2/tcp.pyo"
    )
endif()

