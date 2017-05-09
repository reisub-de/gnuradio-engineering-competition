# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/gnuradio" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/api.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/attributes.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/basic_block.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/block.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/block_detail.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/block_gateway.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/block_registry.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/buffer.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/constants.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/endianness.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/expj.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/feval.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/flowgraph.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/fxpt.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/fxpt_nco.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/fxpt_vco.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/gr_complex.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/hier_block2.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/high_res_timer.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/io_signature.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/math.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/message.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/misc.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/msg_accepter.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/msg_handler.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/msg_queue.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/nco.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/prefs.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/py_feval.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/pycallback_object.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/random.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/realtime.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/realtime_impl.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/runtime_types.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/tags.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/tagged_stream_block.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/top_block.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/tpb_detail.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/sincos.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/sptr_magic.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/sync_block.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/sync_decimator.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/sync_interpolator.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/sys_paths.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/tag_checker.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/types.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/sys_pri.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/unittests.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpccallbackregister_base.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcmanager_base.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcmanager.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcregisterhelpers.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_aggregator.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_base.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_booter_aggregator.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_booter_base.h"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/include/gnuradio/rpcserver_selector.h"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/include/gnuradio/logger.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/include/gnuradio/messages/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/include/gnuradio/thread/cmake_install.cmake")

endif()

