//
// Created by Peter on 6/4/2024.
//

#ifndef WAVES_MATHUTILS_H
#define WAVES_MATHUTILS_H


#include <vector>
#include "../Model/Base/Point2D.h"

class MathUtils {
public:
    static double boundDegrees_0to360(double angle);
    static double boundDegrees_Neg180To180(double angle);
    static double boundRadians_0to2Pi(double angle);
    static double boundRadians_NegPiToPi(double angle);
    static double executePolynomial(double x, const std::vector<double>& polynomial);
    static double applySigmoidFunction(double x);
    static double sign(double x);

private:
    static double boundAngle(double angle, double min, double max);
};


#endif //WAVES_MATHUTILS_H
