#pragma once

#include <gtest/gtest.h>

#include "DataFile.hpp"

#include <fstream>


TEST(datafile_test, assert_throw) {
    ASSERT_ANY_THROW(DataFile file{ "wrongfile" });
}

TEST(datafile_test, assert_no_throw) {
    std::string w{ "test" };
    std::string file_name{ "validfile" };
    std::ofstream of{ file_name, std::ios::out | std::ios::binary };
    of.write(w.c_str(), w.length());
    of.close();
    ASSERT_NO_FATAL_FAILURE(DataFile file{ file_name });
}

TEST(datafile_test, get_binary_data) {
    std::string w{ "test" };
    std::string file_name{ "validfile" };
    std::ofstream of{ file_name, std::ios::out | std::ios::binary };
    of.write(w.c_str(), w.length());
    of.close();
    ASSERT_EQ(DataFile{ file_name }.GetBinaryData().size(), w.size());
}