cmake_minimum_required(VERSION 3.10)
project(cppsandbox)

find_package(glog REQUIRED)

add_subdirectory(asm)
add_subdirectory(malloc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fno-sanitize-recover=address,undefined")

if(${USE_LIBCPP})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
endif()

add_subdirectory(cpp98)
add_subdirectory(cpp11)
add_subdirectory(cpp17)
add_subdirectory(cpp20)
add_subdirectory(boost)
add_subdirectory(nortti)
add_subdirectory(compiler_warning)
#add_subdirectory(glog)

add_subdirectory(c)
add_subdirectory(tbb)
