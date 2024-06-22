//
// Created by Peter on 6/14/2024.
//

#ifndef WAVES_GENERICUTILS_H
#define WAVES_GENERICUTILS_H

class GenericUtils{
public:
    static double boundNumber(double num, double min, double max){
        if (num > max)
            return max;
        if (num < min)
            return min;
        return num;
    }
};

#endif //WAVES_GENERICUTILS_H
