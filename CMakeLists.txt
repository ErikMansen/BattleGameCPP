cmake_minimum_required(VERSION 3.24)
project(Battle_Game_Cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled src/main.cpp src/UI.cpp include/UI.h src/Utils.cpp include/Utils.h src/Character.cpp include/Character.h src/Player.cpp include/Player.h src/Enemy.cpp include/Enemy.h src/Weapon.cpp include/Weapon.h)