#ifndef TIMER_C
#define TIMER_C

#ifdef _WIN32
    #include <Windows.h>
    LARGE_INTEGER frequency;
#else
    #include <time.h>
#endif 


unsigned long long get_time_ns()
{
    #ifdef _WIN32 
        if (frequency.QuadPart == 0)
            QueryPerformanceFrequency(&frequency);
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);
        double seconds = (double)counter.QuadPart / frequency.QuadPart;
        return (unsigned long long)(seconds * 1000000000); // why put a .0 at the end of the divisor? isnt the result a double by default when i casted dividend
    #else 
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (unsigned long long)ts.tv_sec * 1000000000 + ts.tv_nsec; // again, why turn ts.tv_nsec into ull if the first half isalready casted?
    #endif
}


void wait_ns(unsigned nanoseconds) 
{
    #ifdef _WIN32 
        // windows only sleeps in microseconds!!!!
        Sleep(nanoseconds / 1000000);
    #else 
        struct timespec ts = {
            .tv_sec = nanoseconds / 1000000000,
            .tv_nsec = nanoseconds % 1000000000
        };
        nanosleep(&ts, NULL);
    #endif
}



#endif
