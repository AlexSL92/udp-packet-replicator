#include "DataFile.hpp"


DataFile::DataFile(std::string const& path) : path_{ path } {
    std::ifstream file{ path };
    if(!file.good()) { throw std::runtime_error("Unable to find " + path + " file"); }
}

DataFile::~DataFile() {}

std::vector<uint8_t> DataFile::GetBinaryData() const {
    std::ifstream file{ path_, std::ios::binary };
    return std::vector<uint8_t>{ std::istreambuf_iterator<char>(file), {} };
}
