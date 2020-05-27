#include "Timer.hpp"


Timer::Timer(std::chrono::duration<float> const& s) :
    us_{ std::chrono::duration_cast<std::chrono::microseconds>(s) },
    start_time_{ std::chrono::high_resolution_clock::now() },
    end_time_{ std::chrono::high_resolution_clock::now() } {
    if (us_.count() == 0) { throw std::runtime_error("Timer initialized with null value"); }
}

Timer::~Timer() {}

void Timer::StartCycle() {
    end_time_ = std::chrono::high_resolution_clock::now() + us_;
}

void Timer::EndCycle() {
    auto wait_time{ end_time_ - std::chrono::high_resolution_clock::now() };
    while (wait_time.count() > 0) {
        if (wait_time > ConstantTimerData::wait_condition) {
            std::this_thread::sleep_for(wait_time / ConstantTimerData::wait_factor);
        }
        wait_time = end_time_ - std::chrono::high_resolution_clock::now();
    }
}