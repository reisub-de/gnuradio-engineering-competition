#ifndef GR_TIMER_H
#define GR_TIMER_H

#include <time.h>
#include <iostream>

#ifndef USE_GR_TIMERS
#define USE_GR_TIMERS 1
#endif

class gr_timer
{
    private:
#if USE_GR_TIMERS == 1
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

