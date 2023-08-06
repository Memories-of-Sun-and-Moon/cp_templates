# include "bits/stdc++.h"
using namespace std;

struct measure_time{
    using timer_point = chrono::high_resolution_clock::time_point;
    using timer_duration = chrono::high_resolution_clock::duration;
private:
    timer_point clock_start;
    timer_duration time_length;
    bool is_stopping;
public:

    measure_time() : time_length(std::chrono::high_resolution_clock::duration()), is_stopping(false) {}

    inline void start(){
        clock_start = chrono::high_resolution_clock::now();
    }

    inline void stop(){
        assert(is_stopping == false);
        timer_point lap = chrono::high_resolution_clock::now();

        timer_duration d = lap - clock_start;

        time_length += d;
        is_stopping = true;
    }

    inline void resume(){
        assert(is_stopping == true);
        clock_start = chrono::high_resolution_clock::now();
        is_stopping = false;
    }

    inline int elapsed(){
        assert(is_stopping == false);
        timer_point lap = chrono::high_resolution_clock::now();

        timer_duration d = lap - clock_start;

        time_length += d;

        clock_start = chrono::high_resolution_clock::now();

        return chrono::duration_cast<chrono::milliseconds>(time_length).count();
    }
}timer;