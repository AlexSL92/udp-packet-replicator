#pragma once

#include "Communications.hpp"
#include "DataFile.hpp"
#include "Timer.hpp"

#include <atomic>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>


/**
*   @brief Core class of the application
*/
class Core {

public:

    /**
    *   @brief Construct a new Core object
    *   
    *   @param ip IP address of the server
    *   @param port Port of the server
    *   @param ms Milliseconds between network packets
    *   @param path Path of the binary network data file
    */
    Core(std::string ip, uint16_t port, uint32_t ms, std::string path);

    /**
    *   @brief Destroy the Core object
    */
    ~Core();

    /**
    *   @brief Run the core of the application in an infinite loop
    */
    void RunLoop(std::atomic<bool> const& run_flag = true);

private:

    Communications communications_; //!< Communications manager
    Timer timer_; //!< Time manager
    std::vector<uint8_t> data_; //!< Data to send

};