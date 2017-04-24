#ifndef GR_TIMER_H
#define GR_TIMER_H

#include <time.h>
#include <iostream>

//#define USE_GR_TIMERS
class gr_timer
{
    private:
#ifdef USE_GR_TIMERS
        clock_t start;
        std::string id;
        int m_indent;
        static std::ofstream log;
        static gr_timer* log_owner;
        static int indent;
#endif
    public:
        gr_timer(const char* id);
        ~gr_timer();
};

#endif

