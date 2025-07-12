#include "OcctWrapper.hpp"
#include <iostream>

namespace MechFlow { namespace Geometry {
    // Minimal implementation for now
    OcctWrapper::OcctWrapper() {
        std::cout << "OcctWrapper initialized (from .cpp)." << std::endl;
    }
    OcctWrapper::~OcctWrapper() {
        std::cout << "OcctWrapper destroyed (from .cpp)." << std::endl;
    }
}}