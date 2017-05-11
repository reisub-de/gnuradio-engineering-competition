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

namespace gr {
  namespace dtv {
    // Multi-thread task base class definition
    class Task  
    {  
     public:
        Task(void* arg = NULL, const std::string taskName = "")
            : arg_(arg), taskName_(taskName) {}

        virtual ~Task() {}

        void setArg(void* arg){arg_ = arg;}

        virtual int run() = 0;

    protected:
        void*       arg_;
        std::string taskName_;
    };

    // Bch main component
    class dvb_bch_bb_impl : public dvb_bch_bb
    {
     private:
      unsigned int kbch;
      unsigned int nbch;
      unsigned int bch_code;
      // Polynomial product
      unsigned int m_poly_n_8[4];
      unsigned int m_poly_n_10[5];
      unsigned int m_poly_n_12[6];
      unsigned int m_poly_s_12[6];
      unsigned int m_poly_m_12[6];

      // Class member function
      int poly_mult(const int*, int, const int*, int, int*);
      void poly_pack(const int*, unsigned int*, int);
      void poly_reverse(int*, int*, int);
      inline void reg_4_shift(unsigned int*);
      inline void reg_5_shift(unsigned int*);
      inline void reg_6_shift(unsigned int*);
      void bch_poly_build_tables(void);

      // Multi-thread task
      class BchCodeN12Task: public Task  
      {  
      public:  
          BchCodeN12Task();
            
          virtual int run();
      };
      // Multi-thread data structrue
      struct DataBchMultiThread {
        DataBchMultiThread( unsigned int arg_kbcn,
                            const unsigned char *arg_in,
                            unsigned char *arg_out,
                            void * arg_self_ptr,
                            unsigned int *arg_m_poly_n_12)
                            : kbch(arg_kbcn),
                              in(arg_in),
                              out(arg_out),
                              self_ptr(arg_self_ptr),
                              m_poly_n_12(arg_m_poly_n_12) {}
        unsigned int kbch;
        const unsigned char *in;
        unsigned char *out;
        void *self_ptr;
        unsigned int *m_poly_n_12;
      };

     public:
      dvb_bch_bb_impl(dvb_standard_t standard, dvb_framesize_t framesize, dvb_code_rate_t rate);
      ~dvb_bch_bb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items);
    };

    // Thread pool declaration
    class ThreadPool
    {
    public:
        ThreadPool(int threadNum = 8);
        ~ThreadPool();

    public:
        size_t addTask(Task *task);
        void   stop();
        int    size();
        Task*  take();

    private:
        int createThreads();
        static void* threadFunc(void * threadData);

    private:
        ThreadPool& operator=(const ThreadPool&);
        ThreadPool(const ThreadPool&);

    private:
        volatile  bool              isRunning_;
        int                         threadsNum_;
        pthread_t*                  threads_;

        std::deque<Task*>           taskQueue_;
        pthread_mutex_t             mutex_;
        pthread_cond_t              condition_;
    };
  } // namespace dtv
} // namespace gr

#endif /* INCLUDED_DTV_DVB_BCH_BB_IMPL_H */

