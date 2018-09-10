cmake_minimum_required(VERSION 3.10)
project(cppsandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined,integer,nullability -fno-sanitize-recover=address,undefined,integer,nullability")

add_subdirectory(cpp98)
add_subdirectory(cpp11)
add_subdirectory(cpp17)
