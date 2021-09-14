cmake_minimum_required(VERSION 3.21.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -g")

# generate file required by clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(main)

# enable debugging symbols for gdb when compiling with clang
# https://stackoverflow.com/a/47045466
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/grid.cpp)

target_include_directories(main $ENV{INCLUDE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )
