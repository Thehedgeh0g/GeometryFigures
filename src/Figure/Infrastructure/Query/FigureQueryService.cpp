//
// Created by flipd on 13.04.2024.
//

#include "../../../../include/Figure/Infrastructure/Query/FigureQueryService.h"
#include "../../../../include/Figure/Domain/Interfaces/ISolidShape.h"

FigureQueryService::FigureQueryService(IFigureRepository* mFigureRepository) : m_figureRepository(mFigureRepository)
{}

FigureDTO* FigureQueryService::FindFigureWithBiggestArea() const
{
    IShape* figure = m_figureRepository->FindFigureWithBiggestArea();
    return ConvertEntityIntoDTO(figure);
}

FigureDTO* FigureQueryService::FindFigureWithSmallestPerimeter() const
{
    IShape* figure = m_figureRepository->FindFigureWithSmallestPerimeter();
    return ConvertEntityIntoDTO(figure);
}

const std::vector<FigureDTO*>& FigureQueryService::FindAll() const
{
    const std::vector<IShape*> figures = (const std::vector<IShape*>&) m_figureRepository->FindAll();
    auto* result = new std::vector<FigureDTO*>;
    for (const auto& figure: figures)
    {
        result->push_back(ConvertEntityIntoDTO(figure));
    }
    return *result;
}

FigureDTO* FigureQueryService::ConvertEntityIntoDTO(IShape* figure)
{
    auto* solidFigure = dynamic_cast<ISolidShape*>(figure);
    if (solidFigure != nullptr)
    {
        return new FigureDTO{
            solidFigure->GetArea(),
            solidFigure->GetPerimeter(),
            solidFigure->GetOutlineColor(),
            std::make_unique<uint32_t>(solidFigure->GetFillColor()),
            solidFigure->ToString()
        };
    }
    return new FigureDTO{
        figure->GetArea(),
        figure->GetPerimeter(),
        figure->GetOutlineColor(),
        nullptr,
        figure->ToString()
    };
}