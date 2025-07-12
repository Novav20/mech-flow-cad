add_library(MechFlow_Geometry OcctWrapper.cpp OcctWrapper.hpp)
target_include_directories(MechFlow_Geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# OCCT integration will be added here later, likely via vcpkg and find_package(OpenCASCADE REQUIRED)