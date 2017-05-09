# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/grc/core/utils

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "grc" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/grc/core/utils" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/utils/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/utils/complexity.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/utils/epy_block_io.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/utils/expr_utils.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/utils/extract_docs.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/utils/odict.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "grc" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/grc/core/utils" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/complexity.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/epy_block_io.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/expr_utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/extract_docs.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/odict.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/complexity.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/epy_block_io.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/expr_utils.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/extract_docs.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/odict.pyo"
    )
endif()

