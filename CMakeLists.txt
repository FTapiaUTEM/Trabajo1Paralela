cmake_minimum_required(VERSION 3.28)
project(p1)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenMP REQUIRED)
add_executable(p1 main.cpp)


if(OpenMP_CXX_FOUND)
    target_link_libraries(p1 PUBLIC OpenMP::OpenMP_CXX)
endif ()