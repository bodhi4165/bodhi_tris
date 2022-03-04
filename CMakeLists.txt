cmake_minimum_required(VERSION 3.19)
project(tris)

set(CMAKE_CXX_STANDARD 14)

add_executable(tris tris.cpp game_lib.h game_lib.cpp partita.h partita.cpp)