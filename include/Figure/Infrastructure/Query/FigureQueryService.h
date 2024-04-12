//
// Created by flipd on 13.04.2024.
//

#ifndef GEOMETRYFIGURES_FIGUREQUERYSERVICE_H
#define GEOMETRYFIGURES_FIGUREQUERYSERVICE_H


#include "../Interfaces/IFigureRepository.h"
#include "../../App/Interfaces/IFigureQueryService.h"

class FigureQueryService : public IFigureQueryService
{
private:
    IFigureRepository* m_figureRepository;
public:
    explicit FigureQueryService(IFigureRepository* mFigureRepository);

    [[nodiscard]] FigureDTO* FindFigureWithBiggestArea() const override;

    [[nodiscard]] FigureDTO* FindFigureWithSmallestPerimeter() const override;

    [[nodiscard]] const std::vector<FigureDTO*>& FindAll() const override;

private:
    [[nodiscard]] static FigureDTO* ConvertEntityIntoDTO(IShape* figure);
};


#endif //GEOMETRYFIGURES_FIGUREQUERYSERVICE_H
