# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-blocks/examples

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/blocks" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/examples/matrix_multiplexer.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/examples/peak_detector2.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/examples/vector_source_with_tags.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-blocks/examples/test_stream_mux_tags.grc"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/examples/metadata/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/examples/tags/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-blocks/examples/ctrlport/cmake_install.cmake")

endif()

