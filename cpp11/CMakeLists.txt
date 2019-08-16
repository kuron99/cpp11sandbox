cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRCS "*.cpp")

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}_cpp11" ${src})
endforeach()

add_subdirectory(optimize)