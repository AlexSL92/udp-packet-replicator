#pragma once

#include <cstdint>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>


/**
*   @brief Stores the data of a given file
*/
class DataFile {

public:

    /**
    *   @brief Construct a new Data File object
    *   
    *   @param path Path of the file
    */
    DataFile(std::string const& path);

    /**
    *   @brief Destroy the Data File object
    */
    ~DataFile();

    /**
    *   @brief Get the file as binary data
    *   
    *   @return std::vector<uint8_t> File as binary data
    */
    std::vector<uint8_t> GetBinaryData() const;

private:

    std::string path_; //!< Path to file

};