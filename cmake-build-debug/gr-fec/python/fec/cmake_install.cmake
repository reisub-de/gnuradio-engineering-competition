# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "fec_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/fec" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/bitflip.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/extended_encoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/extended_decoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/capillary_threaded_decoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/capillary_threaded_encoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/threaded_decoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/threaded_encoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/extended_async_encoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/extended_tagged_encoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/extended_tagged_decoder.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/fec_test.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/python/fec/bercurve_generator.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "fec_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/fec" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/bitflip.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_encoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_decoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/capillary_threaded_decoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/capillary_threaded_encoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/threaded_decoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/threaded_encoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_async_encoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_tagged_encoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_tagged_decoder.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/fec_test.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/bercurve_generator.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/bitflip.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_encoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_decoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/capillary_threaded_decoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/capillary_threaded_encoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/threaded_decoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/threaded_encoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_async_encoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_tagged_encoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/extended_tagged_decoder.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/fec_test.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/bercurve_generator.pyo"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-fec/python/fec/polar/cmake_install.cmake")

endif()

