#pragma once

#include <gtest/gtest.h>

#include "Communications.hpp"

#include "ClientTester.hpp"

#include <array>
#include <cstdint>
#include <vector>


TEST(communications_test, assert_no_throw) {
    ASSERT_NO_FATAL_FAILURE(Communications comms("127.0.0.1", 6666););
    std::vector<uint8_t> v{ { 'a', 'b' } };
    ASSERT_NO_FATAL_FAILURE(Communications comms("127.0.0.1", 6666); comms.SendPacket(v));
}

TEST(communications_test, send_receive_packet) {
    Communications comms{ "127.0.0.1", 6666 };
    ClientTester tester{ 6666 };
    std::vector<uint8_t> v{ { 'a', 'b' } };
    comms.SendPacket(v);
    auto received = tester.ReceiveData();
    ASSERT_EQ(received.size(), 2);
    ASSERT_EQ(received.at(0), 'a');
    ASSERT_EQ(received.at(1), 'b');
}
