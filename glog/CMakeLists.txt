cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS "*.cpp")

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}" ${src})
    target_link_libraries(${fname}
            glog::glog
            )
endforeach()
