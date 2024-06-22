//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_FRAMETRANSFORMATIONS_H
#define WAVES_FRAMETRANSFORMATIONS_H

#include <array>
#include <cmath>
#include "../Model/Base/Orientation.h"
#include "../Model/Base/Vector3D.h"

class FrameTransformations {
public:
    // Converts a vector in the vehicle frame to the world frame given the vehicle's orientation. Uses NED frame orientation.
    static Vector3D vehicleToWorld(const Vector3D& vehicleFrame, const Orientation& orientation);
    // Converts a vector in the world frame to the vehicle frame given the vehicle's orientation. Uses NED frame orientation.
    static Vector3D worldToVehicle(const Vector3D& vec, const Orientation& orientation);


private:
    static std::array<std::array<double, 3> ,3> createRotationMatrix(const Orientation& orientation);
};


#endif //WAVES_FRAMETRANSFORMATIONS_H
