cmake_minimum_required (VERSION 3.0.0)

# Define the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# Set the project name
project(udp-packet-replicator-test)

# Set the src files
set(SRC_TEST_FILES 
    ${PROJECT_SOURCE_DIR}/main-test.cpp
    ${PROJECT_SOURCE_DIR}/../src/Arguments.cpp
    ${PROJECT_SOURCE_DIR}/../src/Communications.cpp
    ${PROJECT_SOURCE_DIR}/../src/Core.cpp
    ${PROJECT_SOURCE_DIR}/../src/DataFile.cpp
    ${PROJECT_SOURCE_DIR}/../src/Timer.cpp)

# Add the executable of the project
add_executable(${PROJECT_NAME} ${SRC_TEST_FILES})

# Link libraries from the conan text file
target_link_libraries(${PROJECT_NAME} CONAN_PKG::asio CONAN_PKG::gtest)
add_test(NAME Test COMMAND udp-packet-replicator-test)