# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/grc/gui

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/grc/gui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/ActionHandler.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Actions.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Bars.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Block.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/BlockTreeWindow.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Colors.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Config.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Connection.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Constants.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Dialogs.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/DrawingArea.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Element.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Executor.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/FileDialogs.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/FlowGraph.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/MainWindow.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/NotebookPage.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Param.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/ParserErrorsDialog.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Platform.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Port.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Preferences.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/PropsDialog.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/StateCache.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/Utils.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/VariableEditor.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/grc/gui/external_editor.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "grc" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/grc/gui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/ActionHandler.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Actions.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Bars.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Block.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/BlockTreeWindow.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Colors.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Config.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Connection.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Constants.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Dialogs.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/DrawingArea.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Element.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Executor.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/FileDialogs.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/FlowGraph.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/MainWindow.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/NotebookPage.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Param.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/ParserErrorsDialog.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Platform.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Port.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Preferences.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/PropsDialog.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/StateCache.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Utils.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/VariableEditor.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/external_editor.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/ActionHandler.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Actions.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Bars.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Block.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/BlockTreeWindow.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Colors.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Config.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Connection.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Constants.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Dialogs.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/DrawingArea.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Element.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Executor.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/FileDialogs.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/FlowGraph.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/MainWindow.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/NotebookPage.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Param.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/ParserErrorsDialog.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Platform.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Port.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Preferences.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/PropsDialog.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/StateCache.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/Utils.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/VariableEditor.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/grc/gui/external_editor.pyo"
    )
endif()

