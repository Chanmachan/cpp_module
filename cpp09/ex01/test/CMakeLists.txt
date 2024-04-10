set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

add_executable(test_rpn test.cpp)

target_link_libraries(test_rpn ${Boost_LIBRARIES})

# これがないとRPN.cppとリンクできないからtest.cpp内から関数を呼び出せなくなってしまう
target_link_libraries(test_rpn test_library)