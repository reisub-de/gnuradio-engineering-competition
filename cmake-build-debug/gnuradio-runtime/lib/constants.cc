/* -*- c++ -*- */
/*
 * Copyright 2006,2009,2013 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>
#include <gnuradio/constants.h>

namespace gr {

  const std::string
  prefix()
  {
    //Use "GR_PREFIX" environment variable when specified
    const char *prefix = getenv("GR_PREFIX");
    if (prefix != NULL) return prefix;

    return "/usr/local";
  }

  const std::string
  sysconfdir()
  {
    //Provide the sysconfdir in terms of prefix()
    //when the "GR_PREFIX" environment var is specified.
    if (getenv("GR_PREFIX") != NULL)
    {
      return prefix() + "/etc";
    }

    return "/usr/local/etc";
  }

  const std::string
  prefsdir()
  {
    //Provide the prefsdir in terms of sysconfdir()
    //when the "GR_PREFIX" environment var is specified.
    if (getenv("GR_PREFIX") != NULL)
    {
      return sysconfdir() + "/gnuradio/conf.d";
    }

    return "/usr/local/etc/gnuradio/conf.d";
  }

  const std::string
  build_date()
  {
    return "";
  }

  const std::string
  version()
  {
    return "3.7.12git-102-g8b39c8f8";
  }

  // Return individual parts of the version
  const std::string
  major_version()
  {
    return "3";
  }

  const std::string
  api_version()
  {
    return "7";
  }

  const std::string
  minor_version()
  {
    return "12";
  }

  const std::string
  c_compiler()
  {
    return "cc (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609 \nCopyright (C) 2015 Free Software Foundation, Inc. \nThis is free software see the source for copying conditions.  There is NO \nwarranty not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.";
  }

  const std::string
  cxx_compiler()
  {
    return "c++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609 \nCopyright (C) 2015 Free Software Foundation, Inc. \nThis is free software see the source for copying conditions.  There is NO \nwarranty not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.";
  }

  const std::string
  compiler_flags()
  {
    return "/usr/bin/cc:::-g -O2  -fvisibility=hidden -Wsign-compare -Wall -Wno-uninitialized \n/usr/bin/c++:::-g -O2  -fvisibility=hidden -Wsign-compare -Wall -Wno-uninitialized";
  }

  const std::string
  build_time_enabled_components()
  {
    return "python-support;testing-support;volk;gnuradio-runtime;gr-ctrlport;gr-blocks;gnuradio-companion;gr-fec;gr-fft;gr-filter;gr-analog;gr-digital;gr-dtv;gr-atsc;gr-audio;* oss;gr-channels;gr-noaa;gr-pager;gr-qtgui;gr-trellis;gr-utils;gr-vocoder;gr-wavelet;gr-wxgui";
  }
} /* namespace gr */
