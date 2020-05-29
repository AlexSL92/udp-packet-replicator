#pragma once

#include <gtest/gtest.h>

#include "Timer.hpp"


TEST(timer_test, assert_no_throw) {

    // Initialize variables
    constexpr uint32_t cycle_time{ 1 };
    std::chrono::seconds cycle{ cycle_time };

    // Asserts
    ASSERT_NO_THROW(Timer timer{ cycle }; timer.StartCycle(); timer.EndCycle(););
    ASSERT_NO_THROW(Timer timer{ cycle }; timer.EndCycle(););

}

TEST(timer_test, assert_throw) {

    // Initialize variables
    constexpr uint32_t cycle_time{ 1 };
    std::chrono::seconds cycle{ cycle_time };

    // Asserts
    ASSERT_ANY_THROW(Timer timer{ std::chrono::seconds{ 0 } }; timer.StartCycle(); timer.EndCycle(););

}

TEST(timer_test, assert_cycle_time_at_least_2000_ms) {

    // Define aliases
    using CycleTimeUnits = std::chrono::milliseconds;
    using ClockType = std::chrono::high_resolution_clock;

    // Initialize variables
    constexpr CycleTimeUnits cycle_time{ 2000 };

    // Run timer
    Timer timer{ cycle_time };
    auto start{ ClockType::now() };
    timer.StartCycle();
    timer.EndCycle();
    auto finish{ ClockType::now() };
    auto elapsed{ std::chrono::duration_cast<CycleTimeUnits>(finish - start) };

    // Asserts
    ASSERT_GE(elapsed.count(), cycle_time.count());

}

TEST(timer_test, assert_cycle_time_at_least_50_ms) {

    // Define aliases
    using CycleTimeUnits = std::chrono::milliseconds;
    using ClockType = std::chrono::high_resolution_clock;

    // Initialize variables
    constexpr CycleTimeUnits cycle_time{ 50 };

    // Run timer
    Timer timer{ cycle_time };
    auto start{ ClockType::now() };
    timer.StartCycle();
    timer.EndCycle();
    auto finish{ ClockType::now() };
    auto elapsed{ std::chrono::duration_cast<CycleTimeUnits>(finish - start) };

    // Asserts
    ASSERT_GE(elapsed.count(), cycle_time.count());

}

TEST(timer_test, get_time_since_init) {

    // Define aliases
    using CycleTimeUnits = std::chrono::milliseconds;
    using ClockType = std::chrono::steady_clock;

    // Initialize variables
    constexpr CycleTimeUnits cycle_time{ 1000 };
    constexpr CycleTimeUnits abs_error{ 1 };
    Timer timer{ cycle_time };
    auto end_time{ cycle_time + ClockType::now() };
    auto wait_time{ end_time - ClockType::now() };
    
    // Compute time
    while (wait_time.count() > 0) {
        wait_time = end_time - ClockType::now();
    }
    auto t{ timer.GetTimeSinceBuild<CycleTimeUnits>().count() };

    // Asserts
    ASSERT_LE(t, cycle_time.count() + abs_error.count());
    ASSERT_GE(t, cycle_time.count() - abs_error.count());

}
