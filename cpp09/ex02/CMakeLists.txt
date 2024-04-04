CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(exe)

set(CMAKE_CXX_COMPILER c++)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++98 -Wshadow -fsanitize=address")

add_executable(exe main.cpp
                   PmergeMe.cpp)