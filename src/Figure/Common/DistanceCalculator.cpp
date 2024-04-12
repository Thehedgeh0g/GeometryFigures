//
// Created by flipd on 12.04.2024.
//

#include <valarray>
#include "../../../include/Figure/Common/DistanceCalculator.h"

double DistanceCalculator::CalculateDistance(const CPoint& startPoint, const CPoint& endPoint)
{
    double deltaX = endPoint.x - startPoint.x;
    double deltaY = endPoint.y - startPoint.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}
