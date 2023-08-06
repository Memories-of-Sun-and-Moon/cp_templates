# include "bits/stdc++.h"
using namespace std;

struct measure_time{
    using timer_point = chrono::high_resolution_clock::time_point;
    using timer_duration = chrono::high_resolution_clock::duration;
private:
    timer_point clock_start;
    timer_duration time_length;
public:

    measure_time() : time_length(std::chrono::high_resolution_clock::duration()) {}

    inline void start(){
        clock_start = chrono::high_resolution_clock::now();
    }

    inline void stop(){
        timer_point lap = chrono::high_resolution_clock::now();

        timer_duration d = lap - clock_start;

        time_length += d;
    }

    inline void resume(){
        clock_start = chrono::high_resolution_clock::now();
    }

    inline int elapsed(){
        timer_point lap = chrono::high_resolution_clock::now();

        timer_duration d = lap - clock_start;

        time_length += d;

        clock_start = chrono::high_resolution_clock::now();

        return chrono::duration_cast<chrono::milliseconds>(time_length).count();
    }
}timer;