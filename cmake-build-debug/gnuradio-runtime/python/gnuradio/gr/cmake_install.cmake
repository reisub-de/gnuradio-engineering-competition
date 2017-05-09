# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/gr" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/tag_utils.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/packet_utils.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/gateway.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/gr_threading.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/gr_threading_23.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/gr_threading_24.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/hier_block2.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/top_block.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr/pubsub.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/gr" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/tag_utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/packet_utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gateway.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gr_threading.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gr_threading_23.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gr_threading_24.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/hier_block2.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/top_block.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/pubsub.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/tag_utils.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/packet_utils.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gateway.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gr_threading.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gr_threading_23.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/gr_threading_24.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/hier_block2.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/top_block.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/pubsub.pyo"
    )
endif()

