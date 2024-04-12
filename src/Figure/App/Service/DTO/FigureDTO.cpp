//
// Created by flipd on 13.04.2024.
//

#include "../../../../../include/Figure/App/Service/DTO/FigureDTO.h"

#include <utility>

FigureDTO::FigureDTO(
    const double area,
    const double perimeter,
    const uint32_t outlineColor,
    const std::unique_ptr<uint32_t> fillColor,
    std::string stringRepresentation
) :
    m_area(area),
    m_perimeter(perimeter),
    m_stringRepresentation(std::move(stringRepresentation)),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor != nullptr ? std::make_unique<uint32_t>(*fillColor) : nullptr)
{
}
