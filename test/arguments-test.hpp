#pragma once

#include <gtest/gtest.h>

#include "Arguments.hpp"


TEST(arguments_test, assert_no_throw) {
    ASSERT_NO_FATAL_FAILURE(Arguments args{ {} };);
}

TEST(arguments_test, assert_throw) {
    Arguments args{ {} };
    ASSERT_ANY_THROW(args.GetArgumentSpecifier<int>("void"));
}

TEST(arguments_test, check_argument) {
    Arguments args{ {"-ip", "192.168.1.1"} };
    ASSERT_TRUE(args.CheckArgument("ip"));
    ASSERT_FALSE(args.CheckArgument("port"));
}

TEST(arguments_test, get_argument_specifier) {
    Arguments args{ {"-ip", "192.168.1.1", "-port", "5500", "-test"} };
    std::string ip{ args.GetArgumentSpecifier<std::string>("ip") };
    ASSERT_STREQ(ip.c_str(), "192.168.1.1");
    ASSERT_EQ(args.GetArgumentSpecifier<int>("port"), 5500);
    ASSERT_EQ(args.GetArgumentSpecifier<std::string>("test").size(), 0);
}
