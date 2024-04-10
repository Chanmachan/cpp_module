CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(exe)

set(CMAKE_CXX_COMPILER c++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wshadow -fsanitize=address")

add_executable(exe main.cpp
                   RPN.cpp)

# testディレクトリ内でこのライブラリを使えるようにする
add_library(test_library STATIC RPN.cpp)

add_subdirectory(test)