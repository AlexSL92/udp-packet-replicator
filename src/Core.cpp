#include "Core.hpp"


Core::Core(std::string ip, uint16_t port, uint32_t ms, std::string path) :
    communications_{ ip, port },
    data_{ DataFile{ path }.GetBinaryData() },
    timer_{ std::chrono::milliseconds(ms) } {}
    
Core::~Core() {}

void Core::RunLoop(std::atomic<bool> const& run_flag) {
    while(run_flag) {
        timer_.StartCycle();
        communications_.SendPacket(data_);
        timer_.EndCycle();
    }
}
