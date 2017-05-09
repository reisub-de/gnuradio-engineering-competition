# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-channels/include/gnuradio/channels

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "channels_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/channels" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/include/gnuradio/channels/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/include/gnuradio/channels/channel_model.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/include/gnuradio/channels/channel_model2.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/include/gnuradio/channels/fading_model.h"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/include/gnuradio/channels/selective_fading_model.h"
    )
endif()

