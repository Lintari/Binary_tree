cmake_minimum_required(VERSION 3.25)
project(proj C)
set(CMAKE_C_STANDART 99)
set(CMAKE_C_STANDART_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
enable_testing()

add_executable(bst BST.c BST.h)

