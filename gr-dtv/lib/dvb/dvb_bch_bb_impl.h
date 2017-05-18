/* -*- c++ -*- */
/* 
 * Copyright 2015,2016 Free Software Foundation, Inc.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_DTV_DVB_BCH_BB_IMPL_H
#define INCLUDED_DTV_DVB_BCH_BB_IMPL_H

#include <gnuradio/dtv/dvb_bch_bb.h>
#include "dvb_defines.h"

// ThreadPool dependencies
#include <boost/array.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/scoped_ptr.hpp>

namespace gr {
  namespace dtv {
    // Bch main component
    class dvb_bch_bb_impl : public dvb_bch_bb
    {
     private:
      unsigned int kbch;
      unsigned int nbch;
      unsigned int bch_code;
      // Polynomial product init
      const static unsigned int m_poly_n_8_0 = 0xd4669f20;
      const static unsigned int m_poly_n_8_1 = 0xaeb63f98;
      const static unsigned int m_poly_n_8_2 = 0xbde9e48e;
      const static unsigned int m_poly_n_8_3 = 0xfaa4e038;

      const static unsigned int m_poly_n_10_0 = 0x89a6dd1d;
      const static unsigned int m_poly_n_10_1 = 0x80c48bf7;
      const static unsigned int m_poly_n_10_2 = 0xc0ea1e56;
      const static unsigned int m_poly_n_10_3 = 0xf8cc543f;
      const static unsigned int m_poly_n_10_4 = 0xb730a806;

      const static unsigned int m_poly_n_12_0 = 0xe7aa4066;
      const static unsigned int m_poly_n_12_1 = 0xefa1e2c0;
      const static unsigned int m_poly_n_12_2 = 0x9110ac3b;
      const static unsigned int m_poly_n_12_3 = 0x1b34f30a;
      const static unsigned int m_poly_n_12_4 = 0x388a3a21;
      const static unsigned int m_poly_n_12_5 = 0xc1706472;

      const static unsigned int m_poly_s_12_0 = 0xa5a0988b;
      const static unsigned int m_poly_s_12_1 = 0xebe7f14a;
      const static unsigned int m_poly_s_12_2 = 0x9609c5c4;
      const static unsigned int m_poly_s_12_3 = 0xb3464d96;
      const static unsigned int m_poly_s_12_4 = 0x1957db46;
      const static unsigned int m_poly_s_12_5 = 0x2b06472;

      const static unsigned int m_poly_m_12_0 = 0xd0821bc3;
      const static unsigned int m_poly_m_12_1 = 0xf42eac6a;
      const static unsigned int m_poly_m_12_2 = 0xcca1056f;
      const static unsigned int m_poly_m_12_3 = 0xd9c04190;
      const static unsigned int m_poly_m_12_4 = 0xb1800dbe;
      const static unsigned int m_poly_m_12_5 = 0xdd215872;

     private:
      // Class member function
      void poly_reverse(int*, int*, int);
      static inline void reg_4_shift(unsigned int*);
      static inline void reg_5_shift(unsigned int*);
      static inline void reg_6_shift(unsigned int*);

      // Multi-thread handler
      static void bch_code_n12_handler(const unsigned char*, unsigned char*, unsigned int);
      static void bch_code_n10_handler(const unsigned char*, unsigned char*, unsigned int);

     public:
      dvb_bch_bb_impl(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate);
      ~dvb_bch_bb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items);
    };

// The definition of boost_asio based thread pool
  struct ThreadPool {
      typedef boost::scoped_ptr<boost::asio::io_service::work> boost_asio_worker;

      ThreadPool(size_t pool_size) :m_service(), m_working(new boost::asio::io_service::work(m_service)) {
          while(pool_size--)
          {
              m_thread_group.create_thread(boost::bind(&boost::asio::io_service::run, &(this->m_service)));
          }
      }

      template<class F>
          void enqueue(F f){m_service.post(f);}

      ~ThreadPool() {
          m_working.reset(); //allow run() to exit
          m_thread_group.join_all();
          m_service.stop();
      }

      private:
      boost::asio::io_service m_service; //< the io_service we are wrapping
      boost_asio_worker m_working;
      boost::thread_group m_thread_group; //< need to keep track of threads so we can join them
  };
  } // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVB_BCH_BB_IMPL_H */

