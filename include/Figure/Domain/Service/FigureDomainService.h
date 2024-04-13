//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_FIGUREDOMAINSERVICE_H
#define GEOMETRYFIGURES_FIGUREDOMAINSERVICE_H


#include <unordered_map>
#include <string>
#include "../Model/CLineSegment.h"
#include "../Model/CCircle.h"
#include "../Model/CTriangle.h"
#include "../Model/CRectangle.h"
#include "../ValueObject/FigureTypeEnum.h"
#include "../../Infrastructure/Interfaces/IFigureRepository.h"

class FigureDomainService
{
private:
    IFigureRepository* m_figureRepository;

    std::unordered_map<std::string, FigureTypeEnum> m_figureMap = {
        {"line",      FigureTypeEnum::CLine},
        {"rectangle", FigureTypeEnum::CRectangle},
        {"triangle",  FigureTypeEnum::CTriangle},
        {"circle",    FigureTypeEnum::CCircle},
    };

    const std::string DATA_DELIMITER = " ";
public:
    explicit FigureDomainService(IFigureRepository* figureRepository);

    void StoreFigure(const std::string& figureData);

private:
    std::unique_ptr<IShape> ParseFigure(std::string figureData);

    static CLineSegment parseLine(const std::vector<std::string>& lineParams);

    static CCircle parseCircle(const std::vector<std::string>& circleParams);

    static CTriangle parseTriangle(const std::vector<std::string>& triangleParams);

    static CRectangle parseRectangle(const std::vector<std::string>& rectangleParams);
};


#endif //GEOMETRYFIGURES_FIGUREDOMAINSERVICE_H
