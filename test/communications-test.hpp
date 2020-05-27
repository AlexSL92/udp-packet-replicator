#pragma once

#include <gtest/gtest.h>

#include "Communications.hpp"

#include <asio.hpp>

#include <array>
#include <cstdint>
#include <iostream>
#include <vector>


class ClientTester {

public:

    ClientTester(uint16_t port) : 
        io_context_{},
        socket_{ io_context_, asio::ip::udp::endpoint(asio::ip::udp::v4(), port) } {}

    ~ClientTester() {}

    std::vector<uint8_t> ReceiveData() {
        std::array<uint8_t, 8192> recv_buf{};
        asio::ip::udp::endpoint remote_endpoint{};
        auto recv{ socket_.receive_from(asio::buffer(recv_buf), remote_endpoint) };
        return std::vector<uint8_t>{ recv_buf.begin(), recv_buf.begin() + recv };
    }

private:

    asio::io_context io_context_;
    asio::ip::udp::socket socket_;

};


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