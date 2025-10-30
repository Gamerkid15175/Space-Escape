cmake_minimum_required(VERSION 4.0)
project(CS_Project_Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS_Project_Game main.cpp)

target_link_libraries(CS_Project_Game PRIVATE winmm)