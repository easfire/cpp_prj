cmake_minimum_required(VERSION 3.12)
project(hellocmake LANGUAGES CXX)

add_library(hellolib STATIC hello.cpp)
add_executable(hellocmake main.cpp)
target_link_libraries(hellocmake PUBLIC hellolib)
