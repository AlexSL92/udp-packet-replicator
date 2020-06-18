#pragma once

#include <asio.hpp>

#include <cstdint>
#include <vector>


/**
*   @brief Manager of communications
*/
class Communications {

public:

    /**
    *   @brief Construct a new Communications object
    *   
    *   @param ip IP address of the server
    *   @param port Port of the server
    */
    Communications(std::string const& ip, uint16_t port);

    /**
    *   @brief Send packet of data
    *   
    *   @param data Packet to be sent
    */
    void SendPacket(std::vector<uint8_t> const& data);

private:

    asio::io_context io_context_; //!< IO socket context
    asio::ip::udp::resolver resolver_;
    asio::ip::udp::endpoint endpoint_; //!< Endpoint of the socket
    asio::ip::udp::socket socket_; //!< Socket

};
