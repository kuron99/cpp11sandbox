cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRCS "*.cpp")

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    get_filename_component(dname "${CMAKE_CURRENT_SOURCE_DIR}/../" DIRECTORY)
    get_filename_component(dname "${dname}" NAME_WE)
    set(tname "${dname}_${fname}")
    add_executable("${tname}" ${src})
endforeach()
