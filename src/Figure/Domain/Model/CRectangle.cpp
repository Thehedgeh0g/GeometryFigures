//
// Created by flipd on 12.04.2024.
//

#include "../../../../include/Figure/Domain/Model/CRectangle.h"
#include "../../../../include/Figure/Common/DistanceCalculator.h"
#include "../../../../include/Figure/Common/ColorParser.h"

CRectangle::CRectangle(
    const CPoint& rightTopVertex,
    const CPoint& leftBottomVertex,
    const uint32_t& outlineColor,
    const uint32_t& fillColor
) :
    m_rightTopVertex(rightTopVertex),
    m_leftBottomVertex(leftBottomVertex),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor),
    m_height(
        DistanceCalculator::CalculateDistance(
            m_rightTopVertex,
            *new CPoint(leftBottomVertex.x, rightTopVertex.y)
        )
    ),
    m_width(
        DistanceCalculator::CalculateDistance(
            m_leftBottomVertex,
            *new CPoint(leftBottomVertex.x, rightTopVertex.y)
        )
    )
{
}

CRectangle::~CRectangle() = default;


const CPoint& CRectangle::GetRightTopVertex() const
{
    return m_rightTopVertex;
}

const CPoint& CRectangle::GetLeftBottomVertex() const
{
    return m_leftBottomVertex;
}

uint32_t CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
    return m_fillColor;
}

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
}

std::string CRectangle::ToString() const
{
    return "rectangle (" +
           std::to_string(m_rightTopVertex.x) + "; " + std::to_string(m_rightTopVertex.y) + ") " +
           "(" + std::to_string(m_leftBottomVertex.x) + "; " + std::to_string(m_leftBottomVertex.y) + ") " +
           std::to_string(m_width) +
           " " + std::to_string(m_height) +
           " #" + ColorParser::ColorCodeToString(m_outlineColor) +
           " #" + ColorParser::ColorCodeToString(m_fillColor);
}

