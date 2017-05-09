# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/eng_notation.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/eng_option.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/eng_arg.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr_unittest.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gr_xmlrunner.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/eng_notation.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/eng_option.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/eng_arg.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr_unittest.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr_xmlrunner.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/eng_notation.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/eng_option.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/eng_arg.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr_unittest.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr_xmlrunner.pyo"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gr/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/cmake_install.cmake")

endif()

