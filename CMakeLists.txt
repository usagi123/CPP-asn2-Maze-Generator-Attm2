cmake_minimum_required(VERSION 3.14)
project(asn2_att2)

set(CMAKE_CXX_STANDARD 14)

add_executable(asn2_att2 main.cpp Coordinator.cpp Coordinator.h Edge.cpp Edge.h Maze.cpp Maze.h GrowingTree.cpp GrowingTree.h HuntAndKill.cpp HuntAndKill.h Prim.cpp Prim.h RecursiveBacktracking.cpp RecursiveBacktracking.h)