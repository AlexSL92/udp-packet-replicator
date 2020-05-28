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

TEST(timer_test, assert_cycle_time_50_ms) {

    // Define aliases
    using ErrorTimeUnits = std::chrono::milliseconds;
    using CycleTimeUnits = std::chrono::milliseconds;
    using ClockType = std::chrono::steady_clock;

    // Initialize variables
    CycleTimeUnits cycle_time{ 50 };
    constexpr uint32_t number_of_cycles{ 50 };
    constexpr ErrorTimeUnits abs_error{ 1 };

    // Run cycles
    Timer timer{ cycle_time };
    auto start{ ClockType::now() };
    for (uint32_t i = 0; i < number_of_cycles; i++) {
        timer.StartCycle();
        timer.EndCycle();
    }
    auto duration{ std::chrono::duration_cast<CycleTimeUnits>(ClockType::now() - start).count() };
    auto average{ duration / number_of_cycles };

    // Asserts
    ASSERT_LE(average, cycle_time.count() + std::chrono::duration_cast<CycleTimeUnits>(abs_error).count());
    ASSERT_GE(average, cycle_time.count() - std::chrono::duration_cast<CycleTimeUnits>(abs_error).count());

}

TEST(timer_test, assert_cycle_time_20_ms) {

    // Define aliases
    using ErrorTimeUnits = std::chrono::milliseconds;
    using CycleTimeUnits = std::chrono::milliseconds;
    using ClockType = std::chrono::steady_clock;

    // Initialize variables
    CycleTimeUnits cycle_time{ 20 };
    constexpr uint32_t number_of_cycles{ 50 };
    constexpr ErrorTimeUnits abs_error{ 1 };

    // Run cycles
    Timer timer{ cycle_time };
    auto start{ ClockType::now() };
    for (uint32_t i = 0; i < number_of_cycles; i++) {
        timer.StartCycle();
        timer.EndCycle();
    }
    auto duration{ std::chrono::duration_cast<CycleTimeUnits>(ClockType::now() - start).count() };
    auto average{ duration / number_of_cycles };

    // Asserts
    ASSERT_LE(average, cycle_time.count() + std::chrono::duration_cast<CycleTimeUnits>(abs_error).count());
    ASSERT_GE(average, cycle_time.count() - std::chrono::duration_cast<CycleTimeUnits>(abs_error).count());

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
