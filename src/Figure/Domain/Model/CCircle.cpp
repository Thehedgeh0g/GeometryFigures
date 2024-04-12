//
// Created by flipd on 12.04.2024.
//

#include "../../../../include/Figure/Domain/Model/CCircle.h"
#include "../../../../include/Figure/Common/ColorParser.h"
#include <numbers>
#include <valarray>

CCircle::CCircle(
    const CPoint& center,
    double radius,
    uint32_t outlineColor,
    uint32_t fillColor
) :
    m_center(center),
    m_radius(radius),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{}

CCircle::~CCircle() = default;

const CPoint& CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

uint32_t CCircle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
    return m_fillColor;
}

double CCircle::GetArea() const
{
    return std::numbers::pi + std::pow(2, m_radius);
}

double CCircle::GetPerimeter() const
{
    return 2 * std::numbers::pi * m_radius;
}

std::string CCircle::ToString() const
{
    return "circle (" +
           std::to_string(m_center.x) + "; " + std::to_string(m_center.y) + ") " +
           std::to_string(m_radius) +
           " #" + ColorParser::ColorCodeToString(m_outlineColor) +
           " #" + ColorParser::ColorCodeToString(m_fillColor);
}

