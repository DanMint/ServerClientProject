# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name your project
project(Client)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(my_program
    client1.cpp      # Main file
    client2.cpp    # Implementation file
)
