cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SRCS "*.c")

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}" ${src})
endforeach()
