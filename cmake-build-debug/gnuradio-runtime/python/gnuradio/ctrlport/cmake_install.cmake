# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/ctrlport" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/icon.png")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/ctrlport" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/GrDataPlotter.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/monitor.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/GNURadioControlPortClient.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/RPCConnection.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/ctrlport" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/GrDataPlotter.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/monitor.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/GNURadioControlPortClient.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/RPCConnection.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/GrDataPlotter.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/monitor.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/GNURadioControlPortClient.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/RPCConnection.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorx"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitor"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorxc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitorc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/gr-perf-monitorxo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/ctrlport/gr-ctrlport-monitoro"
    )
endif()

