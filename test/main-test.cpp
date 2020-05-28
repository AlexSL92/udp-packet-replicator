#include <gtest/gtest.h>

#include "arguments-test.hpp"
#include "communications-test.hpp"
#include "datafile-test.hpp"
#include "integration-test.hpp"
#include "timer-test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}