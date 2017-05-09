# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-channels/examples

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "channels_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/channels" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/examples/channel_tone_response.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/examples/demo_quantization.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/examples/demo_two_tone.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/examples/demo_spec_an.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/examples/demo_gmsk.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/examples/demo_qam.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-channels/examples/demo_ofdm.grc"
    )
endif()

