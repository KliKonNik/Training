cmake_minimum_required(VERSION 3.20)

project(BackPack LANGUAGES CXX)

add_executable(main src/main.cpp)

add_library(proccess src/proccess.cpp)
add_library(collection src/collection.cpp)
add_library(backpack src/backpack.cpp)
add_library(item src/item.cpp)

target_link_libraries(main PRIVATE proccess)
target_link_libraries(proccess PRIVATE collection backpack)
target_link_libraries(collection PUBLIC item)
target_link_libraries(backpack PUBLIC collection)
