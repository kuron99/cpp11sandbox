cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRCS
        "*.cpp"
        "mt/*.cpp"
        )

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}" ${src})
endforeach()
