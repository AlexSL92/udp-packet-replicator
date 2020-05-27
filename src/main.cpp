#include "Core.hpp"
#include "Arguments.hpp"

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>


int main(int argc, char* argv[]) {
  try {
    Arguments args{ std::vector<std::string>{ argv, argv + argc } };
    Core core{ args.GetArgumentSpecifier<std::string>("ip"), 
      args.GetArgumentSpecifier<uint16_t>("port"),
      args.GetArgumentSpecifier<uint32_t>("ms"), 
      args.GetArgumentSpecifier<std::string>("file") };
    std::cout << "Packet replicator running with the following configuration:" << std::endl;
    std::cout << args << std::endl;
    core.RunLoop();
  }
  catch(std::exception const& e) {
    std::cout << e.what() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
  return 0;
}