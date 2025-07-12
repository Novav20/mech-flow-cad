#pragma once
#include <iostream>

namespace MechFlow { namespace Geometry {
    // Placeholder for OCCT wrapper classes
    struct Point { double x, y, z; };

    // Placeholder for a basic OCCT-like operation
    class OcctWrapper {
    public:
        OcctWrapper();
        ~OcctWrapper();

        Point createPoint(double x, double y, double z) {
            return {x, y, z};
        }
    };
}}
