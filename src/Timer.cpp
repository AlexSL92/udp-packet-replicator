#include "Timer.hpp"


Timer::Timer(std::chrono::duration<float> const& s) :
    ms_{ std::chrono::duration_cast<std::chrono::milliseconds>(s) },
    start_time_{ std::chrono::high_resolution_clock::now() },
    io_{},
    t_{ io_ } {
    if (ms_.count() == 0) { throw std::runtime_error("Timer initialized with null value"); }
}

void Timer::StartCycle() {
    t_.expires_after(ms_);
}

void Timer::EndCycle() {
    t_.wait();
}
