//
// Created by flipd on 12.04.2024.
//

#include <sstream>
#include "../../../../include/Figure/Domain/Service/FigureDomainService.h"
#include "../../../../include/Figure/Common/ColorParser.h"

FigureDomainService::FigureDomainService(IFigureRepository* figureRepository) : m_figureRepository(figureRepository)
{}


void FigureDomainService::StoreFigure(const std::string& figureData)
{
    std::unique_ptr<IShape> newFigure = ParseFigure(figureData);
    if (newFigure != nullptr)
    {
        m_figureRepository->StoreFigure(std::move(newFigure));
    }
}

std::unique_ptr<IShape> FigureDomainService::ParseFigure(std::string figureData)
{
    size_t pos;
    std::vector<std::string> figureParams;
    std::string token;
    while ((pos = figureData.find(DATA_DELIMITER)) != std::string::npos)
    {
        token = figureData.substr(0, pos);
        figureParams.push_back(token);
        figureData.erase(0, pos + DATA_DELIMITER.length());
    }
    figureParams.push_back(figureData);

    auto it = m_figureMap.find(figureParams[0]);
    if (it != m_figureMap.end())
    {
        switch (it->second)
        {
            case FigureTypeEnum::CCircle:
                return std::make_unique<CCircle>(parseCircle(figureParams));
            case FigureTypeEnum::CRectangle:
                return std::make_unique<CRectangle>(parseRectangle(figureParams));
            case FigureTypeEnum::CTriangle:
                return std::make_unique<CTriangle>(parseTriangle(figureParams));
            case FigureTypeEnum::CLine:
                return std::make_unique<CLineSegment>(parseLine(figureParams));
            default:
                return nullptr;
        }
    }
}

CLineSegment FigureDomainService::parseLine(const std::vector<std::string>& lineParams)
{
    return CLineSegment{
        CPoint((std::stod(lineParams[1])), (std::stod(lineParams[2]))),
        CPoint((std::stod(lineParams[3])), (std::stod(lineParams[4]))),
        ColorParser::ParseColorCode(lineParams[5])
    };
}

CCircle FigureDomainService::parseCircle(const std::vector<std::string>& circleParams)
{
    return CCircle{
        CPoint((std::stod(circleParams[1])), (std::stod(circleParams[2]))),
        std::stod(circleParams[3]),
        ColorParser::ParseColorCode(circleParams[4]),
        ColorParser::ParseColorCode(circleParams[5])
    };
}

CTriangle FigureDomainService::parseTriangle(const std::vector<std::string>& triangleParams)
{
    return CTriangle{
        CPoint((std::stod(triangleParams[1])), (std::stod(triangleParams[2]))),
        CPoint((std::stod(triangleParams[3])), (std::stod(triangleParams[4]))),
        CPoint((std::stod(triangleParams[5])), (std::stod(triangleParams[6]))),
        ColorParser::ParseColorCode(triangleParams[7]),
        ColorParser::ParseColorCode(triangleParams[8])
    };
}

CRectangle FigureDomainService::parseRectangle(const std::vector<std::string>& rectangleParams)
{
    return CRectangle{
        CPoint((std::stod(rectangleParams[1])), (std::stod(rectangleParams[2]))),
        CPoint((std::stod(rectangleParams[3])), (std::stod(rectangleParams[4]))),
        ColorParser::ParseColorCode(rectangleParams[5]),
        ColorParser::ParseColorCode(rectangleParams[6])
    };
}

uint32_t FigureDomainService::ParseColorCode(const std::string& colorCode)
{
    std::istringstream iss(colorCode);
    std::string component;
    uint32_t color = 0;
    int shift = 24;

    while (std::getline(iss, component, ','))
    {
        int value = std::stoi(component);
        color |= static_cast<uint32_t>(value) << shift;
        shift -= 8;
    }

    return color;
}


