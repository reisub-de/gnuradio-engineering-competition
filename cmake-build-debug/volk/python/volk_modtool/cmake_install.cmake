# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/volk/python/volk_modtool

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "volk" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/volk_modtool" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/volk/python/volk_modtool/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/volk/python/volk_modtool/cfg.py"
    "/home/zhiwei/WorkSpace/gnuradio/volk/python/volk_modtool/volk_modtool_generate.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "volk" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/volk_modtool" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/cfg.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/volk_modtool_generate.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/cfg.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/volk_modtool_generate.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "volk" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM RENAME "volk_modtool" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/volk_modtool.exe")
endif()

