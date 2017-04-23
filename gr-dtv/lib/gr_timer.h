#ifndef GR_TIMER_H
#define GR_TIMER_H

#include <time.h>
#include <iostream>

class gr_timer
{
    private:
        clock_t start;
        std::string id;
        static std::ofstream log;
        static gr_timer* log_owner;

    public:
        gr_timer(const char* id);
        ~gr_timer();
};

#endif

