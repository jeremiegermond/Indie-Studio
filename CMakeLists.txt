project(bomberman)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -fpermissive")

include(cmake/Findraylib.cmake)
include_directories(Includes)

add_executable(bomberman
        Src/Game/Game.cpp
        Src/Map.cpp
        Src/Main.cpp
        Src/Game/GameObject.cpp
        Src/Scene/Scene.cpp
        Src/Scene/SceneManager.cpp)

target_link_libraries(bomberman raylib)