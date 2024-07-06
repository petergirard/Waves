//
// Created by Peter on 6/4/2024.
//

#include "MathUtils.h"

double MathUtils::boundDegrees_0to360(double angle) {
    return boundAngle(angle, 0, 360);
}

double MathUtils::boundDegrees_Neg180To180(double angle) {
    return boundAngle(angle, -180, 180);
}

double MathUtils::boundRadians_0to2Pi(double angle) {
    return boundAngle(angle, 0, 2.0*M_PI);
}

double MathUtils::boundRadians_NegPiToPi(double angle) {
    return boundAngle(angle, -1.0 * M_PI, M_PI);
}

// Returns the output of the polynomial given the polynomial and x.
// Power of constant should increase with index, so polynomial[0] should be the constant for x^0.
// and polynomial[n] is constant for x^n.
double MathUtils::executePolynomial(double x, const std::vector<double>& polynomial) {
    double output = 0;
    for(int i = 0; i < polynomial.size(); i++){
        output += polynomial[i] * std::pow(x, i);
    }
    return output;
}

// Applies a sigmoid function that starts at 0,0 and has a range of [0,1]
double MathUtils::applySigmoidFunction(double x) {
    if (x < 0)
        return 0;
    if (x > 1)
        return 1;

    return 2.0 / (1.0 + std::exp(-x)) - 1.0;
}

double MathUtils::sign(double x) {
    return (x > 0) - (x < 0);
}

double MathUtils::boundAngle(double angle, double min, double max) {
    double range = max - min;
    while (angle > max){
        angle -= range;
    }
    while (angle < min){
        angle += range;
    }
    return angle;
}

