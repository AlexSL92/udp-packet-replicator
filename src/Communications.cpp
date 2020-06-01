#include "Communications.hpp"


Communications::Communications(std::string const& ip, uint16_t port) : 
    io_context_{},
    resolver_{ io_context_ },
    endpoint_{ *resolver_.resolve(asio::ip::udp::v4(), ip, std::to_string(port)).begin() },
    socket_{ io_context_ } {
        socket_.open(asio::ip::udp::v4());
    }

Communications::~Communications() {}

void Communications::SendPacket(std::vector<uint8_t> const& data) {
    socket_.send_to(asio::buffer(data.data(), data.size()), endpoint_);
}
