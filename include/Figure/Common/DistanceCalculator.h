//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_DISTANCECALCULATOR_H
#define GEOMETRYFIGURES_DISTANCECALCULATOR_H


#include "../Domain/Model/CPoint.h"

class DistanceCalculator
{
public:
    static double CalculateDistance(const CPoint& startPoint, const CPoint& endPoint);
};


#endif //GEOMETRYFIGURES_DISTANCECALCULATOR_H
