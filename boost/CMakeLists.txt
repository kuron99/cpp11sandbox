cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRCS "*.cpp")

find_package(Boost
        COMPONENTS filesystem serialization thread system
        REQUIRED
        )

foreach(src IN LISTS SRCS)
    get_filename_component(fname "${src}" NAME_WE)
    add_executable("${fname}" ${src})
    target_link_libraries(${fname}
            PRIVATE Boost::filesystem
            PRIVATE Boost::serialization
            PRIVATE Boost::thread
            )
    if(${fname} MATCHES "_boost4$")
        target_compile_definitions(${fname} PRIVATE BOOST_THREAD_VERSION=4)
        target_compile_definitions(${fname} PRIVATE BOOST_THREAD_PROVIDES_FUTURE_CONTINUATION)
    endif()
endforeach()

# list boost target name usable in CMakeList.txt
message("boost libraries : ${Boost_LIBRARIES}")
foreach(boost_lib IN LISTS Boost_LIBRARIES)
    string(REGEX MATCH ".+/.*boost_([^-]+).*\\.(so|a)" boost_lib_name ${boost_lib})
    set(boost_lib_name ${CMAKE_MATCH_1})
    set(boost_target Boost::${boost_lib_name})
    if(TARGET ${boost_target})
        message(STATUS "Boost target found: " ${boost_target})
    endif(TARGET ${boost_target})
endforeach(boost_lib)
