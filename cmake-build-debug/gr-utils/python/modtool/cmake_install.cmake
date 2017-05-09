# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "utils" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/modtool" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/cmakefile_editor.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/code_generator.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/grc_xml_generator.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_add.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_disable.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_help.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_info.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_makexml.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_newmod.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_rm.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/modtool_rename.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/parser_cc_block.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/scm.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/templates.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/util_functions.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "utils" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/modtool" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/cmakefile_editor.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/code_generator.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/grc_xml_generator.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_add.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_disable.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_help.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_info.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_makexml.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_newmod.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_rm.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_rename.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/parser_cc_block.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/scm.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/templates.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/util_functions.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/cmakefile_editor.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/code_generator.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/grc_xml_generator.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_add.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_disable.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_help.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_info.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_makexml.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_newmod.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_rm.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool_rename.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/parser_cc_block.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/scm.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/templates.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/util_functions.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "utils" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gnuradio/modtool" TYPE DIRECTORY FILES "/home/zhiwei/WorkSpace/gnuradio/gr-utils/python/modtool/gr-newmod")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "utils" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/etc/gnuradio/conf.d/modtool.conf")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/etc/gnuradio/conf.d" TYPE FILE FILES "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-utils/python/modtool/modtool.conf")
endif()

