#pragma once
#include <time.h>

class PerfCounter
{
private:
    
    double GetTickCount(void) 
    {
        struct timespec now;
        if (clock_gettime(CLOCK_MONOTONIC, &now))
            return 0;
        
        return now.tv_sec * 1000.0 + now.tv_nsec / 1000000.0;
    }
    
    double startVal;
    double stopVal;
    double average;
    int counter;
    
public:
    
    void StartCounter()
    {
        startVal = GetTickCount();
    }
    
    void StopCounter()
    {
        stopVal = GetTickCount();
        average += (stopVal - startVal);
        counter++;
    }
    
    void PrintAverage()
    {
        printf("Average time: %lf us\n", average / counter);
    }
};




/* Example:
 * 
inline void dvb_ldpc_bb_impl::doParityCheck(unsigned char* p, const unsigned char* d, int counter, int start)
    {
        PerfCounter c;
        c.StartCounter();

         _Cilk_for (int j = start; j < counter; j+=9) {
            // For faster check, enroll the For Loop
            // The table is always a multiple of 360
          p[ldpc_encode.p[j]] ^= d[ldpc_encode.d[j]] ^ d[ldpc_encode.d[j+1]] ^ d[ldpc_encode.d[j+2]]
                                ^ d[ldpc_encode.d[j+3]] ^ d[ldpc_encode.d[j+4]] ^ d[ldpc_encode.d[j+5]]
                                ^ d[ldpc_encode.d[j+6]] ^ d[ldpc_encode.d[j+7]] ^ d[ldpc_encode.d[j+8]];
        }  
        
        c.StopCounter();
        c.PrintAverage();
    }
*
Gibt den Average zwar jedes mal aus, aber der letzte ausgegebene Wert zählt dann.
*/
