project(bomberman)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -fpermissive")

include(cmake/Findraylib.cmake)
include_directories(Includes)
include_directories(Includes/Encapsulation)

add_executable(bomberman
        Src/Game/Game.cpp
        Src/Map.cpp
        Src/Main.cpp
        Src/Entity/GameObject.cpp
        Src/Entity/GameScript.cpp
        Src/Entity/GameCamera.cpp
        Src/Entity/GameDrawMap.cpp
        Src/Entity/GameImage.cpp
        Src/Entity/GameSound.cpp
        Src/Entity/GameText.cpp
        Src/Scene/Scene.cpp
        Src/Scene/SceneManager.cpp
        Src/Encapsulation/Window.cpp
        Src/Encapsulation/Draw.cpp
        Src/Encapsulation/Models.cpp
        Src/Entity/GamePlayer.cpp)

target_link_libraries(bomberman raylib)