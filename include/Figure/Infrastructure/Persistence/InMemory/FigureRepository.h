//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_FIGUREREPOSITORY_H
#define GEOMETRYFIGURES_FIGUREREPOSITORY_H


#include <vector>
#include <memory>
#include "../../../Domain/Interfaces/IShape.h"
#include "../../Interfaces/IFigureRepository.h"

class FigureRepository : public IFigureRepository
{
private:
    std::vector<std::unique_ptr<IShape>> m_figures;
public:
    ~FigureRepository() override;

    void StoreFigure(std::unique_ptr<IShape> figure) override;

    [[nodiscard]] IShape* FindFigureWithBiggestArea() const override;

    [[nodiscard]] IShape* FindFigureWithSmallestPerimeter() const override;

    [[nodiscard]] const std::vector<std::unique_ptr<IShape>>& FindAll() const override;
};


#endif //GEOMETRYFIGURES_FIGUREREPOSITORY_H
