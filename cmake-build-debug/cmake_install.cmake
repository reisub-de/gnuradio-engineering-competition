# Install script for directory: /home/zhiwei/WorkSpace/gnuradio

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "docs" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/gnuradio-3.7.12git" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/README.md"
    "/home/zhiwei/WorkSpace/gnuradio/README.hacking"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/gnuradio" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/cmake/Modules/GnuradioConfig.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/cmake/Modules/GnuradioConfigVersion.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/CMakeMacroLibtoolFile.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/CMakeParseArgumentsCopy.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindALSA.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindCppUnit.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindFFTW3f.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindGSL.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindGit.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindJack.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindLog4cpp.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindOSS.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindPortaudio.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindQwt.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindSWIG.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindSphinx.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindThrift.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindUHD.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindUSB.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/FindZeroMQ.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrBoost.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrBuildTypes.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrComponent.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrMiscUtils.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrPackage.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrPlatform.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrPython.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrSetupQt4.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrSwig.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrTest.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/GrVersion.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/LibFindMacros.cmake"
    "/home/zhiwei/WorkSpace/gnuradio/cmake/Modules/UseSWIG.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/include/gnuradio/config.h")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/docs/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fft/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-digital/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-dtv/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-audio/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-comedi/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-channels/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-noaa/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-pager/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-qtgui/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-trellis/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-uhd/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-video-sdl/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-vocoder/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fcd/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wavelet/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-zeromq/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
