//
// Created by flipd on 12.04.2024.
//

#include <algorithm>
#include "../../../../../include/Figure/Infrastructure/Persistence/InMemory/FigureRepository.h"

FigureRepository::~FigureRepository() = default;

void FigureRepository::StoreFigure(std::unique_ptr<IShape> figure)
{
    m_figures.push_back(std::move(figure));
}

IShape* FigureRepository::FindFigureWithBiggestArea() const
{
    if (m_figures.empty())
    {
        return nullptr;
    }

    auto maxAreaFigure = std::max_element(
        m_figures.begin(),
        m_figures.end(),
        [](const std::unique_ptr<IShape>& a, const std::unique_ptr<IShape>& b) {
            return a->GetArea() < b->GetArea();
        }
    );

    return maxAreaFigure->get();
}

IShape* FigureRepository::FindFigureWithSmallestPerimeter() const
{
    if (m_figures.empty())
    {
        return nullptr;
    }

    auto maxAreaFigure = std::min_element(
        m_figures.begin(),
        m_figures.end(),
        [](const std::unique_ptr<IShape>& a, const std::unique_ptr<IShape>& b) {
            return a->GetPerimeter() < b->GetPerimeter();
        }
    );

    return maxAreaFigure->get();
}

const std::vector<std::unique_ptr<IShape>>& FigureRepository::FindAll() const
{
    return m_figures;
}

