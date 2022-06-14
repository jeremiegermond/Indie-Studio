project(bomberman)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
include(cmake/Findraylib.cmake)
add_compile_options(-Wall -fpermissive)
include_directories(Includes)
include_directories(Includes/Encapsulation)
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif()

add_executable(bomberman
        Src/Game/Game.cpp
        Src/Map.cpp
        Src/Gamepad.cpp
        Src/Main.cpp
        Src/Exception.cpp
        Src/Keyboard.cpp
        Src/Entity/GameObject.cpp
        Src/Entity/GameScript.cpp
        Src/Entity/GameCamera.cpp
        Src/Entity/GameDrawMap.cpp
        Src/Entity/GameImage.cpp
        Src/Entity/GameSound.cpp
        Src/Entity/GameText.cpp
        Src/Scene/Scene.cpp
        Src/Scene/SceneManager.cpp
        Src/Encapsulation/Load.cpp
        Src/Encapsulation/Window.cpp
        Src/Encapsulation/Draw.cpp
        Src/Encapsulation/Models.cpp
        Src/Entity/GamePlayer.cpp
        Src/Entity/GameButton.cpp
        Src/Entity/GameBomb.cpp)

target_link_libraries(bomberman raylib)