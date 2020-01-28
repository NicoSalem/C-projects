cmake_minimum_required(VERSION 3.13)
project(proj_1_automata C)

set(CMAKE_C_STANDARD 99)

add_executable(proj_1_automata main.c DFA.h NFA.h m.h)