/* -*- c++ -*- */
/*
 * Copyright 2017 Free Software Foundation, Inc.
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


#ifndef INCLUDED_DTV_DVBT2_ENCODER_COMP_H
#define INCLUDED_DTV_DVBT2_ENCODER_COMP_H

#include <gnuradio/dtv/api.h>
#include <gnuradio/hier_block2.h>

namespace gr {
  namespace dtv {

    /*!
     * \brief <+description of block+>
     * \ingroup dtv
     *
     */
    class DTV_API dvbt2_encoder_comp : virtual public gr::hier_block2
    {
     public:
      typedef boost::shared_ptr<dvbt2_encoder_comp> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of dtv::dvbt2_encoder_comp.
       *
       * To avoid accidental use of raw pointers, dtv::dvbt2_encoder_comp's
       * constructor is in a private implementation
       * class. dtv::dvbt2_encoder_comp::make is the public interface for
       * creating new instances.
       */
      static sptr make(const char *input_file, const char *output_file);
    };

  } // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVBT2_ENCODER_COMP_H */
