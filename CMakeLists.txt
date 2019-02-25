cmake_minimum_required(VERSION 3.10)
project(cppsandbox)

#find_package(glog REQUIRED)

add_subdirectory(asm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-sanitize-recover=address,undefined")

add_subdirectory(cpp98)
add_subdirectory(cpp11)
add_subdirectory(cpp17)
#add_subdirectory(glog)

