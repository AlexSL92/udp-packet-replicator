#pragma once

#include <gtest/gtest.h>

#include "Core.hpp"
#include "Arguments.hpp"

#include "ClientTester.hpp"

#include <array>
#include <chrono>
#include <cstdint>
#include <string>
#include <thread>
#include <future>
#include <vector>


TEST(integration_test, main_app) {

    // Initialize basic data
    std::string data_to_send{ "data" };
    ClientTester tester{ 6666 };
    std::string file_name{ "integrationfile" };

    // Write file of data 
    std::ofstream of{ file_name, std::ios::out | std::ios::binary };
    of.write(data_to_send.c_str(), data_to_send.length());
    of.close();

    // Initialize arguments
    std::vector<std::string> raw_arguments{ "-ip", "127.0.0.1", 
        "-port", "6666", "-ms", "1000", "-file", "integrationfile" };
    Arguments args{ raw_arguments };

    // Initialize core of the application
    Core core{ args.GetArgumentSpecifier<std::string>("ip"), 
      args.GetArgumentSpecifier<uint16_t>("port"),
      args.GetArgumentSpecifier<uint32_t>("ms"), 
      args.GetArgumentSpecifier<std::string>("file") };

    // Start application
    std::atomic<bool> run{ true };
    auto f = std::async([&]{ core.RunLoop(run); });

    // Receive first packet
    auto received_1{ tester.ReceiveData() };
    ASSERT_EQ(received_1.size(), 4);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Receive second packet
    auto received_2{ tester.ReceiveData() };
    ASSERT_EQ(received_2.size(), 4);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // End core
    run = false;

}