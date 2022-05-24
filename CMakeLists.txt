project(bomberman)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -fpermissive")

include(cmake/Findraylib.cmake)
include_directories(Includes)

add_executable(bomberman
        Src/Game.cpp
        Src/Map.cpp
        Src/Main.cpp)

target_link_libraries(bomberman raylib)