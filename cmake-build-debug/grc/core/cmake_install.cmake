# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/grc/core

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "grc" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/grc/core" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Block.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Config.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Connection.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Constants.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Element.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/FlowGraph.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Messages.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Param.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/ParseXML.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Platform.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/Port.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/__init__.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "grc" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/grc/core" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Block.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Config.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Connection.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Constants.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Element.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/FlowGraph.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Messages.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Param.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/ParseXML.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Platform.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Port.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Block.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Config.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Connection.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Constants.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Element.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/FlowGraph.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Messages.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Param.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/ParseXML.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Platform.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/Port.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/__init__.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "grc" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/grc/core" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/block.dtd"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/block_tree.dtd"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/domain.dtd"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/flow_graph.dtd"
    "/home/zhiwei/WorkSpace/gnuradio/grc/core/default_flow_graph.grc"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/generator/cmake_install.cmake")
  include("/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/core/utils/cmake_install.cmake")

endif()

