#include "gr_timer.h"

#include <time.h>
#include <fstream>

std::ofstream gr_timer::log;
gr_timer* gr_timer::log_owner = 0;

gr_timer::gr_timer(const char* id):
    start(clock()),
    id(id)
{
    if(!log.is_open())
    {
        log.open("/tmp/gr-timer.log", std::ofstream::app);
        log_owner = this;
    }
    log << "started timer <" << id << ">" << std::endl;
}

gr_timer::~gr_timer()
{
    clock_t duration = clock() - start;
    log << "timer <" << id << "> lasted " << duration << " cycles (" << (duration * 1000000 / CLOCKS_PER_SEC) << " us)." << std::endl;
    log_owner = 0;
} 


