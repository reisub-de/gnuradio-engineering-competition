# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-channels

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/gnuradio-channels.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/include/gnuradio/channels/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/lib/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/swig/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/python/channels/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/grc/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/examples/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/doc/cmake_install.cmake")

endif()

