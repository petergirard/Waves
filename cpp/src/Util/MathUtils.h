//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MATHUTILS_H
#define WAVES_MATHUTILS_H


#include <vector>
#include "../Model/Base/Point2D.h"

class MathUtils {
public:
    static double boundAngle_0to360(double angle);
    static double executePolynomial(double x, const std::vector<double>& polynomial);
    static double applySigmoidFunction(double x);
};


#endif //WAVES_MATHUTILS_H
