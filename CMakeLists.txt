cmake_minimum_required (VERSION 3.10.0)

# Define the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# Set the project name
project(udp-packet-replicator)

# Download conan.cmake automatically
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

# Include and run conan
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt 
               BASIC_SETUP CMAKE_TARGETS
               BUILD missing)

# Include main code headers
include_directories(src)

# Add main code subdirectory
add_subdirectory(src)

# Enable tests
enable_testing()

# Add test code subdirectory
add_subdirectory(test)
