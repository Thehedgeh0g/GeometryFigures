//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_IFIGUREREPOSITORY_H
#define GEOMETRYFIGURES_IFIGUREREPOSITORY_H

#include <vector>
#include <memory>
#include "../../Domain/Interfaces/IShape.h"

class IFigureRepository
{
public:
//todo: выяснить для чего нужен виртуальный деструктор
//todo: fizzbuzz enterprise edition почитать
    virtual ~IFigureRepository() = default;

    virtual void StoreFigure(std::unique_ptr<IShape> figure) = 0;

    [[nodiscard]] virtual IShape* FindFigureWithBiggestArea() const = 0;

    [[nodiscard]] virtual IShape* FindFigureWithSmallestPerimeter() const = 0;

    [[nodiscard]] virtual const std::vector<std::unique_ptr<IShape>>& FindAll() const = 0;
};

#endif //GEOMETRYFIGURES_IFIGUREREPOSITORY_H
