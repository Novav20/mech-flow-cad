cmake_minimum_required(VERSION 3.20)
project(MechFlow VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(MechFlow_App src/main.cpp)
target_link_libraries(MechFlow_App PRIVATE MechFlow_Geometry)