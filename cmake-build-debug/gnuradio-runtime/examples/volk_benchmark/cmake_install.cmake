# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/examples/volk_benchmark

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/volk_benchmark" TYPE PROGRAM RENAME "volk_math.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/volk_benchmark/volk_math.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/volk_benchmark" TYPE PROGRAM RENAME "volk_plot.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/volk_benchmark/volk_plot.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/volk_benchmark" TYPE PROGRAM RENAME "volk_test_funcs.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/volk_benchmark/volk_test_funcs.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/volk_benchmark" TYPE PROGRAM RENAME "volk_types.py" FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/examples/volk_benchmark/volk_types.py.exe")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/volk_benchmark" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/examples/volk_benchmark/README")
endif()

