#include "Timer.hpp"


Timer::Timer(std::chrono::duration<float> const& s) :
    us_{ std::chrono::duration_cast<std::chrono::microseconds>(s) },
    start_time_{ std::chrono::high_resolution_clock::now() },
    io_{},
    t_{ nullptr } {
    if (us_.count() == 0) { throw std::runtime_error("Timer initialized with null value"); }
}

Timer::~Timer() {}

void Timer::StartCycle() {
    t_ = std::make_unique<asio::steady_timer>(io_, us_);
}

void Timer::EndCycle() {
    if(t_) {
        t_->wait();
    }
}