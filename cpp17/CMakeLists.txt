cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRCS
        "*.cpp"
        "basic_io/*.cpp"
        "cyclic_dependency/*.cpp"
        "declaration_only/*.cpp"
        "mt/*.cpp"
        )

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}" ${src} ../cpp20/mt/atomic_flag_ping_pong.cpp)
endforeach()
