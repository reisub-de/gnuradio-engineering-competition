# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-atsc/swig

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc/_atsc_swig.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc/_atsc_swig.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc/_atsc_swig.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc" TYPE MODULE FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/swig/_atsc_swig.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc/_atsc_swig.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc/_atsc_swig.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc/_atsc_swig.so"
         OLD_RPATH "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-analog/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-filter/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fft/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/lib:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/lib/pmt:/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/volk/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc/_atsc_swig.so")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/swig/atsc_swig.py")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/atsc" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/swig/atsc_swig.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/swig/atsc_swig.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "atsc_swig" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio/swig" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-atsc/swig/atsc_swig.i"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-atsc/swig/atsc_swig_doc.i"
    )
endif()

