cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME MyUniquePtr)

project(${PROJECT_NAME})

add_executable(main src/main.cpp  "src/myUnique_ptr.h")

target_compile_features(main PUBLIC cxx_std_20)
