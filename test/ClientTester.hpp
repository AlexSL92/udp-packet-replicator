#pragma once

#include <asio.hpp>

#include <array>
#include <cstdint>
#include <vector>


/**
*   @brief Tester of client sockets
*/
class ClientTester {

public:

    /**
    *   @brief Construct a new Client Tester object
    *   
    *   @param port Port where listen for packets
    */
    ClientTester(uint16_t port) : 
        io_context_{},
        socket_{ io_context_, asio::ip::udp::endpoint(asio::ip::udp::v4(), port) } {}

    /**
    *   @brief Destroy the Client Tester object
    *   
    */
    ~ClientTester() {}

    /**
    *   @brief Read data from socket
    *   
    *   @return std::vector<uint8_t> Data received on the socket 
    */
    std::vector<uint8_t> ReceiveData() {
        std::array<uint8_t, 8192> recv_buf{};
        asio::ip::udp::endpoint remote_endpoint{};
        auto recv{ socket_.receive_from(asio::buffer(recv_buf), remote_endpoint) };
        return std::vector<uint8_t>{ recv_buf.begin(), recv_buf.begin() + recv };
    }

private:

    asio::io_context io_context_; //!< Asio context object
    asio::ip::udp::socket socket_; //!< Asio socket

};
