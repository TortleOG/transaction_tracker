cmake_minimum_required(VERSION 2.8.9)

project(transaction_tracker)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -Werror")

# Set variables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Add headers
include_directories(include)

# Get all .cpp files
file(GLOB SOURCES "src/*.cpp" "include/*.h")

add_executable(tt ${SOURCES})

