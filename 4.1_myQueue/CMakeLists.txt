cmake_minimum_required(VERSION 3.20)

project(MyQueue LANGUAGES CXX)

add_executable(main src/main.cpp)

add_library(libQueue STATIC src/myqueue.cpp)

target_link_libraries(main PUBLIC libQueue)
