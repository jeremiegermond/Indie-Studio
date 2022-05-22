project(bomberman)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -fpermissive")

include(cmake/Findraylib.cmake)
include_directories(includes)

add_executable(bomberman
        src/game.cpp
        src/map.cpp
        src/main.cpp)

target_link_libraries(bomberman raylib)