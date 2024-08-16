CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(exe)

set(CMAKE_CXX_COMPILER c++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++98 -Wshadow -fsanitize=address -g")

add_executable(exe main.cpp
                   PmergeMe.cpp)

add_library(pmergeme_lib PmergeMe.cpp)

add_subdirectory(test)