# Install script for directory: /home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/wxgui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/common.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/constants.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/constsink_gl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/const_window.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/form.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/fftsink2.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/fftsink_nongl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/fftsink_gl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/fft_window.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/gui.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/histosink_gl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/histo_window.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/numbersink2.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/number_window.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plot.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/powermate.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/pubsub.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/scopesink2.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/scopesink_nongl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/scopesink_gl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/scope_window.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/termsink.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/waterfallsink2.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/waterfallsink_nongl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/waterfallsink_gl.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/waterfall_window.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/slider.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/stdgui2.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/wxgui" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/common.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/constants.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/constsink_gl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/const_window.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/form.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fftsink2.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fftsink_nongl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fftsink_gl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fft_window.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/gui.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/histosink_gl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/histo_window.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/numbersink2.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/number_window.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plot.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/powermate.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/pubsub.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scopesink2.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scopesink_nongl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scopesink_gl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scope_window.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/termsink.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfallsink2.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfallsink_nongl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfallsink_gl.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfall_window.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/slider.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/stdgui2.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/common.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/constants.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/constsink_gl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/const_window.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/form.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fftsink2.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fftsink_nongl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fftsink_gl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/fft_window.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/gui.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/histosink_gl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/histo_window.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/numbersink2.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/number_window.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plot.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/powermate.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/pubsub.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scopesink2.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scopesink_nongl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scopesink_gl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/scope_window.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/termsink.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfallsink2.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfallsink_nongl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfallsink_gl.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/waterfall_window.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/slider.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/stdgui2.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/wxgui/forms" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/forms/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/forms/forms.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/forms/converters.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/wxgui/forms" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/forms/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/forms/forms.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/forms/converters.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/forms/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/forms/forms.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/forms/converters.pyo"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/wxgui/plotter" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/__init__.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/bar_plotter.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/channel_plotter.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/common.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/gltext.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/grid_plotter_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/plotter_base.py"
    "/home/zhiwei/WorkSpace/gnuradio/gr-wxgui/python/wxgui/plotter/waterfall_plotter.py"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "wxgui_python" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages/gnuradio/wxgui/plotter" TYPE FILE FILES
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/__init__.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/bar_plotter.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/channel_plotter.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/common.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/gltext.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/grid_plotter_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/plotter_base.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/waterfall_plotter.pyc"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/__init__.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/bar_plotter.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/channel_plotter.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/common.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/gltext.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/grid_plotter_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/plotter_base.pyo"
    "/home/zhiwei/WorkSpace/gnuradio/cmake-build-debug/gr-wxgui/python/wxgui/plotter/waterfall_plotter.pyo"
    )
endif()

