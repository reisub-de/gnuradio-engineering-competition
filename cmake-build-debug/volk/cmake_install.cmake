# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/volk

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "volk_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/volk.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "volk_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/zhiwei/WorkSpace/gnuradio/volk/kernels/volk" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "volk_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/volk" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/volk/include/volk/volk_prefs.h"
    "/home/zhiwei/WorkSpace/gnuradio/volk/include/volk/volk_complex.h"
    "/home/zhiwei/WorkSpace/gnuradio/volk/include/volk/volk_common.h"
    "/home/zhiwei/WorkSpace/gnuradio/volk/include/volk/volk_avx_intrinsics.h"
    "/home/zhiwei/WorkSpace/gnuradio/volk/include/volk/volk_sse3_intrinsics.h"
    "/home/zhiwei/WorkSpace/gnuradio/volk/include/volk/volk_neon_intrinsics.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/include/volk/volk.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/include/volk/volk_cpu.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/include/volk/volk_config_fixed.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/include/volk/volk_typedefs.h"
    "/home/zhiwei/WorkSpace/gnuradio/volk/include/volk/volk_malloc.h"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "volk_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/volk" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/cmake/Modules/VolkConfig.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/cmake/Modules/VolkConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/lib/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/apps/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/python/volk_modtool/cmake_install.cmake")

endif()

