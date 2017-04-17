/*
Copyright (c) 2014 Alexander Freed

These classes provided a common API for a high performance timer
that you can use for timing run time or controlling game loops.
Use this when cross-platform compatibility between windows and
linux is required.

This file is for linux

PerformanceTimer
*/

#ifndef PERFORMANCETIMER_H
#define PERFORMANCETIMER_H

#include <time.h>
#include <sys/time.h> // some systems needs this for timeval.

// Allows for very accurate measuring of time
// Can be used to control game loops
// designed to work in Linux
class PerformanceTimer
{
    public:
		static const bool DISABLED = false;
	
        // constructor
		PerformanceTimer()
		{
			stopTime = startTime;
			interval = 1 / 60.0; // default is 1/60th of a second
		}
		
        // works on all Linux
		// this function included to make it compatible with the windows performance timer API
		bool IsValid()
		{
			return true;
		}
		
        // sets the game loop interval
		void SetInterval(double ticksPerSecond)
		{
			interval = 1 / ticksPerSecond;
		}
		
        void Start()
		{
			gettimeofday(&startTime, NULL);
			stopTime = startTime;
		}
		
        // doesn't actually stop the timer
		// just records the time
		void Stop()
		{
			gettimeofday(&stopTime, NULL);
		}
		
        // returns time elapsed in milliseconds
		double GetElapsed()
		{
			long int secDiff = stopTime.tv_sec - startTime.tv_sec;
			long int usecDiff = stopTime.tv_usec - startTime.tv_usec;
			if (usecDiff < 0)
			{
				usecDiff += 1000000;
				secDiff -= 1;
			}
			return secDiff * 1000 + usecDiff / 1000.0;
		}
		
        // since the timer was started, has the given interval elapsed?
		bool IntervalHasElapsed()
		{
			long int secDiff = stopTime.tv_sec - startTime.tv_sec;
			long int usecDiff = stopTime.tv_usec - startTime.tv_usec;
			if (usecDiff < 0)
			{
				usecDiff += 1000000;
				secDiff -= 1;
			}
			return (secDiff + usecDiff / 1000000.0) >= interval;
		}

    private:
        timeval startTime;
        timeval stopTime;
        double interval;
};

#endif // PERFORMANCETIMER_H
