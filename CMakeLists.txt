cmake_minimum_required(VERSION 3.12)
project(cpp11sandbox)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRCS "*.cpp")

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}" ${src})
endforeach()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined,integer,nullability -fno-sanitize-recover=address,undefined,integer,nullability")
