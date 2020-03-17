#include <cstdio>
#include <cstring>
#include <iostream>
#include <chrono>
#include <ctime>

struct TimerClass {
    TimerClass(std::chrono::system_clock::time_point timestamp) : timestamp(timestamp) {
        std::chrono::system_clock::now();
        printf("The current time is: %s\n", timestamp);
    }

    ~TimerClass() {
        printf("Time since last construction: %s\n", timestamp);
    }

private:
    std::chrono::system_clock::time_point timestamp;
    std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();
};