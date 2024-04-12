//
// Created by flipd on 13.04.2024.
//

#ifndef GEOMETRYFIGURES_IFIGUREQUERYSERVICE_H
#define GEOMETRYFIGURES_IFIGUREQUERYSERVICE_H

#include <vector>
#include <memory>
#include "../../Domain/Interfaces/IShape.h"
#include "../Service/DTO/FigureDTO.h"

class IFigureQueryService
{
public:
    [[nodiscard]] virtual FigureDTO* FindFigureWithBiggestArea() const = 0;

    [[nodiscard]] virtual FigureDTO* FindFigureWithSmallestPerimeter() const = 0;

    [[nodiscard]] virtual const std::vector<FigureDTO*>& FindAll() const = 0;
};

#endif //GEOMETRYFIGURES_IFIGUREQUERYSERVICE_H
