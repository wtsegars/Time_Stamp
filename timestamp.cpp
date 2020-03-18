// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <chrono>
// #include <ctime>
// #include <thread>

// struct TimerClass {
//     TimerClass() : timestamp(std::chrono::system_clock::now()) {
//         std::chrono::steady_clock::time_point starttime = std::chrono::steady_clock::now();
//         printf("The current time is: %ll\n", timestamp);
//     }

//     ~TimerClass() {
//         std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();
//         std::chrono::duration_cast<std::chrono::seconds>(endtime - starttime).count();
//         printf("Time since last construction: %lld\n", std::chrono::duration_cast<std::chrono::seconds>(endtime - starttime).count());
//     }

// private:
//     std::chrono::system_clock::time_point timestamp;
//     std::chrono::steady_clock::time_point starttime;
//     std::chrono::steady_clock::time_point endtime;
// };

// int main() {
//     TimerClass t1;
//     TimerClass t2;
// }

#include <iostream>
#include <chrono>
#include <thread>

struct TimerClass {
    TimerClass(const char* name) 
        :   m_start (std::chrono::steady_clock::now())
    {
        printf("%s:\n", name);
    }

    ~TimerClass() {
        using namespace std::chrono;
        auto life = steady_clock::now() - m_start;
        std::cout << "Duration in ms " << duration_cast<milliseconds>( life ).count() << std::endl;
        std::cout << "Duration in us " << duration_cast<microseconds>( life ).count() << std::endl;
    }

    TimerClass(const TimerClass& other) : m_start(other.m_start) {
        
    }

    TimerClass(TimerClass&& other) noexcept : m_start(other.m_start) {
        other.m_start = std::chrono::steady_clock::now();
    }

    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this == &other) return *this;
        m_start = other.m_start;
        other.m_start = std::chrono::steady_clock::now();
        return *this;
    }

private:
    std::chrono::steady_clock::time_point m_start;
};

int main()
{
    TimerClass t("First Timer");
    TimerClass t_copy(t);
    {
        TimerClass t_2("Second Timer");
        TimerClass t_2_copy(t_2);
        t_2 = std::move(t);

        std::this_thread::sleep_for( std::chrono::seconds(1));
    }

    std::this_thread::sleep_for( std::chrono::milliseconds(300));
}