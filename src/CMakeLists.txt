cmake_minimum_required (VERSION 3.10.0)

# Define the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# Set the project name
project(udp-packet-replicator)

# Set the src files
set(SRC_FILES  
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/Arguments.cpp
    ${PROJECT_SOURCE_DIR}/Communications.cpp
    ${PROJECT_SOURCE_DIR}/Core.cpp
    ${PROJECT_SOURCE_DIR}/DataFile.cpp
    ${PROJECT_SOURCE_DIR}/Timer.cpp)

# Add the executable of the project
add_executable (${PROJECT_NAME} ${SRC_FILES})

# Link libraries from the conan text file
target_link_libraries(${PROJECT_NAME} CONAN_PKG::asio)
