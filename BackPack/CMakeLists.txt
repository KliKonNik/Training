cmake_minimum_required(VERSION 3.20)

project(BackPack LANGUAGES CXX)

add_executable(BackPack src/main.cpp)

add_library(itemc src/item.cpp)

target_link_libraries(BackPack PRIVATE itemc)
