cmake_minimum_required(VERSION 3.14)
project(mazer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(.)

add_executable(mazer main.cpp Coordinator.cpp Coordinator.h Edge.cpp Edge.h Maze.cpp Maze.h GrowingTree.cpp GrowingTree.h HuntAndKill.cpp HuntAndKill.h Prim.cpp Prim.h RecursiveBacktracking.cpp RecursiveBacktracking.h)