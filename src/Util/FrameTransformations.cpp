//
// Created by Peter on 6/14/2024.
//

#include "FrameTransformations.h"

Vector3D FrameTransformations::vehicleToWorld(const Vector3D &vec, const Orientation &orientation) {
    auto R = createRotationMatrix(orientation);
    return {
            R[0][0] * vec.x + R[0][1] * vec.y + R[0][2] * vec.z,
            R[1][0] * vec.x + R[1][1] * vec.y + R[1][2] * vec.z,
            R[2][0] * vec.x + R[2][1] * vec.y + R[2][2] * vec.z
    };
}

Vector3D FrameTransformations::worldToVehicle(const Vector3D &vec, const Orientation &orientation) {
    auto R = createRotationMatrix(orientation);
    return {
            R[0][0] * vec.x + R[1][0] * vec.y + R[2][0] * vec.z,
            R[0][1] * vec.x + R[1][1] * vec.y + R[2][1] * vec.z,
            R[0][2] * vec.x + R[1][2] * vec.y + R[2][2] * vec.z
    };
}

std::array<std::array<double, 3>, 3> FrameTransformations::createRotationMatrix(const Orientation &orientation) {
    double cr = std::cos(orientation.roll);
    double sr = std::sin(orientation.roll);
    double cp = std::cos(orientation.pitch);
    double sp = std::sin(orientation.pitch);
    double cy = std::cos(orientation.yaw);
    double sy = std::sin(orientation.yaw);

    return {{
                { cy * cp, cy * sp * sr - sy * cr, cy * sp * cr + sy * sr },
                { sy * cp, sy * sp * sr + cy * cr, sy * sp * cr - cy * sr },
                { -sp,    cp * sr,                cp * cr               }
            }};
}
