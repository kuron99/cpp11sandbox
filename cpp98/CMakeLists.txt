cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 98)

file(GLOB SRCS "*.cpp")

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}" ${src})
endforeach()
