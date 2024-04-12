//
// Created by flipd on 12.04.2024.
//

#include "../../../../include/Figure/Domain/Model/CTriangle.h"
#include "../../../../include/Figure/Common/DistanceCalculator.h"
#include "../../../../include/Figure/Common/ColorParser.h"

CTriangle::CTriangle(
    const CPoint& vertex1,
    const CPoint& vertex2,
    const CPoint& vertex3,
    const uint32_t& outlineColor,
    const uint32_t& fillColor
) :
    m_vertex1(vertex1),
    m_vertex2(vertex2),
    m_vertex3(vertex3),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{}

CTriangle::~CTriangle() = default;

uint32_t CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CTriangle::GetVertex1()
{
    return m_vertex1;
}

CPoint CTriangle::GetVertex2()
{
    return m_vertex2;
}

CPoint CTriangle::GetVertex3()
{
    return m_vertex3;
}

double CTriangle::GetArea() const
{
    return 0.5 * std::abs(
        m_vertex1.x * (m_vertex2.y - m_vertex3.y) +
        m_vertex2.x * (m_vertex3.y - m_vertex1.y) +
        m_vertex3.x * (m_vertex1.y - m_vertex2.y)
    );
}

double CTriangle::GetPerimeter() const
{
    double edge1 = DistanceCalculator::CalculateDistance(m_vertex1, m_vertex2);
    double edge2 = DistanceCalculator::CalculateDistance(m_vertex2, m_vertex3);
    double edge3 = DistanceCalculator::CalculateDistance(m_vertex3, m_vertex1);
    return edge1 + edge2 + edge3;
}

std::string CTriangle::ToString() const
{
    return "triangle (" +
           std::to_string(m_vertex1.x) + "; " + std::to_string(m_vertex1.y) + ") " +
           "(" + std::to_string(m_vertex2.x) + "; " + std::to_string(m_vertex2.y) + ") " +
           "(" + std::to_string(m_vertex3.x) + "; " + std::to_string(m_vertex3.y) + ") " +
           " #" + ColorParser::ColorCodeToString(m_outlineColor) +
           " #" + ColorParser::ColorCodeToString(m_fillColor);
}
