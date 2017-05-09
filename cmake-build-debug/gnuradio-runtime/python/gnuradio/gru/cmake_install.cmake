# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/gru" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/freqz.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/gnuplot_freqz.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/hexint.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/listmisc.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/mathmisc.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/msgq_runner.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/os_read_exactly.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/seq_with_cursor.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/socket_stuff.py"
    "/home/zhiwei/WorkSpace/gnuradio/gnuradio-runtime/python/gnuradio/gru/daemon.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/gru" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/freqz.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/gnuplot_freqz.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/hexint.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/listmisc.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/mathmisc.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/msgq_runner.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/os_read_exactly.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/seq_with_cursor.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/socket_stuff.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/daemon.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/freqz.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/gnuplot_freqz.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/hexint.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/listmisc.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/mathmisc.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/msgq_runner.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/os_read_exactly.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/seq_with_cursor.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/socket_stuff.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gnuradio-runtime/python/gnuradio/gru/daemon.pyo"
    )
endif()

