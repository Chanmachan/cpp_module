#enable dynamic linking
#動的リンクにすることで速く小さく
set(Boost_USE_STATIC_LIBS OFF)

# Boostを見つける
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# インクルードディレクトリを設定
include_directories(${Boost_INCLUDE_DIR})

add_executable(test_exe test.cpp)
target_compile_definitions(test_exe PRIVATE DEBUG_VEC=1 DEBUG_LST=1)

# link Boost libraries to the new target
target_link_libraries(test_exe ${Boost_LIBRARIES})

# link Boost with code library
target_link_libraries(test_exe pmergeme_lib)