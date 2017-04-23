#ifndef GR_TIMER_H
#define GR_TIMER_H

#include <time.h>
#include <iostream>

class gr_timer
{
    private:
        unsigned long start;
        std::string id;
    public:

        gr_timer(const char* id):
            start(clock()),
            id(id)
    {
        std::cout << "started timer <" << id << ">" << std::endl;
    }
        ~gr_timer()
        {
            std::cout << "timer <" << id << "> lasted " << (clock() - start) << " cycles." << std::endl;
        } 
};

#endif

