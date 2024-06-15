//
// Created by Peter on 6/4/2024.
//

#include "MathUtils.h"

// Bounds an angle from 0 to 360.
double MathUtils::boundAngle_0to360(double angle) {
    while (angle > 360){
        angle -= 360;
    }
    while (angle < 0){
        angle += 360;
    }
    return angle;
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
