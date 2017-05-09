# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/examples/network

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/network" TYPE PROGRAM RENAME "audio_sink.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/network/audio_sink.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/network" TYPE PROGRAM RENAME "audio_source.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/network/audio_source.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/network" TYPE PROGRAM RENAME "dial_tone_sink.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/network/dial_tone_sink.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/network" TYPE PROGRAM RENAME "dial_tone_source.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/network/dial_tone_source.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/network" TYPE PROGRAM RENAME "vector_sink.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/network/vector_sink.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/network" TYPE PROGRAM RENAME "vector_source.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/network/vector_source.py.exe")
endif()

