# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-fec/examples

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/fec" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/ber_test.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/ber_curve_gen.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/ber_curve_gen_ldpc.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_decoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_encoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_async_decoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_async_encoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_async_to_stream.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_async_packed_decoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_tagged_decoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_tagged_encoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_cc_decoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_polar_async_packed_decoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_polar_decoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/fecapi_polar_encoders.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/polar_ber_curve_gen.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/polar_code_example.grc"
    "/home/zhiwei/WorkSpace/gnuradio/gr-fec/examples/tpc_ber_curve_gen.grc"
    )
endif()

