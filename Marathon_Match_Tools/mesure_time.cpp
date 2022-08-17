# include "bits/stdc++.h"
using namespace std;

using timer_point = chrono::high_resolution_clock::time_point;

struct mesure_time{
private:
    timer_point clock_start;
public:
    inline void start(){
        clock_start = chrono::high_resolution_clock::now();
    }

    inline int elapsed(){
        timer_point lap = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(lap - clock_start).count();
    }
};