#pragma once

#include <asio.hpp>

#include <chrono>
#include <cstdint>
#include <memory>
#include <stdexcept>


/**
*   @brief Manager of time
*
*   @throw NullInitValue The class has been initialized with a null value
*/
class Timer {

public:

    /**
    *   @brief Construct a new Timer object
    *   
    *   @param s Duration that initializes the class time value
    */
    Timer(std::chrono::duration<float> const& s);

    /**
    *   @brief Destroy the Timer object
    */
    ~Timer();

    /**
    *   @brief Start of the cycle
    */
    void StartCycle();

    /**
    *   @brief End of the cycle
    */
    void EndCycle();

    /**
    *   @brief Get the Time Since Build object
    *   
    *   @tparam T Type of the return
    *   @return T Time since the build of the class
    */
    template<typename T>
    T GetTimeSinceBuild() const {
        return std::chrono::duration_cast<T>(std::chrono::high_resolution_clock::now() - start_time_);
    }

private:

    std::chrono::microseconds us_; //!< Microseconds of waiting.
    std::chrono::high_resolution_clock::time_point start_time_; //!< Point where cycle starts.
    asio::io_context io_; //!< Asio io context
    std::unique_ptr<asio::steady_timer> t_; //!< Asio timer

};