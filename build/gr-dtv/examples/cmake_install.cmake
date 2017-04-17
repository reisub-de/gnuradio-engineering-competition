# Install script for directory: /home/rabih9780/gnuradio/gr-dtv/examples

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
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dtv_python")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/dtv" TYPE PROGRAM RENAME "atsc_ctrlport_monitor.py" FILES "/home/rabih9780/gnuradio/build/gr-dtv/examples/atsc_ctrlport_monitor.py.exe")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dtv_python")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/examples/dtv" TYPE FILE FILES
    "/home/rabih9780/gnuradio/gr-dtv/examples/README.dvbs"
    "/home/rabih9780/gnuradio/gr-dtv/examples/README.dvbs2"
    "/home/rabih9780/gnuradio/gr-dtv/examples/README.dvbt"
    "/home/rabih9780/gnuradio/gr-dtv/examples/README.dvbt2"
    "/home/rabih9780/gnuradio/gr-dtv/examples/README.catv"
    "/home/rabih9780/gnuradio/gr-dtv/examples/dvbs2_tx.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/dvbs_tx.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/dvbt_rx_8k.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/dvbt_tx_2k.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/dvbt_tx_8k.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/file_atsc_rx.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/file_atsc_tx.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/uhd_atsc_capture.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/uhd_rx_atsc.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/vv003-cr23.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/vv009-4kfft.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/vv018-miso.grc"
    "/home/rabih9780/gnuradio/gr-dtv/examples/catv_tx_64qam.grc"
    )
endif()

