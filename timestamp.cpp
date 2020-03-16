#include <cstdio>
#include <cstring>
#include <iostream>
#include <chrono>
#include <ctime>

struct TimerClass {
    TimerClass(time_t* timestamp) : timestamp(timestamp) {
        std::chrono::system_clock::now();
        printf("The current time is: %s\n", timestamp);
    }

    ~TimerClass() {
        
    }

private:
    time_t* timestamp;
};