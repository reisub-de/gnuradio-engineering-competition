#include "gr_timer.h"

#ifdef USE_GR_TIMERS

#include <time.h>
#include <fstream>
#include <iomanip>

std::ofstream gr_timer::log;
gr_timer* gr_timer::log_owner = 0;
int gr_timer::indent = 0;

gr_timer::gr_timer(const char* id):
    start(clock()),
    id(id),
    m_indent(indent)
{
    if(!log.is_open())
    {
        log.open("/tmp/gr-timer.log", std::ofstream::app);
        log_owner = this;
    }
    indent++;
    log << std::setw(4 * m_indent) << std::left << "+ " << "timer <" << std::setw(30) << std::left << id << "> started." << std::endl;
}

gr_timer::~gr_timer()
{
    clock_t duration = clock() - start;
    log << std::setw(4 * m_indent) << std::left << "- " << "timer <" << std::setw(30) << std::left << id << "> lasted " << std::setw(7) << std::right << (duration * 1000000 / CLOCKS_PER_SEC) << " us." << std::endl;
    log_owner = 0;
    indent--;
} 

#else
gr_timer::gr_timer(const char*) {}
gr_timer::~gr_timer() {}

#endif


