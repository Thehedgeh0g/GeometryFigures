//
// Created by flipd on 12.04.2024.
//

#include <valarray>
#include "../../../../include/Figure/Domain/Model/CLineSegment.h"
#include "../../../../include/Figure/Common/ColorParser.h"

CLineSegment::CLineSegment(
    const CPoint& startPoint,
    const CPoint& endPoint,
    const uint32_t& outlineColor
) :
    m_startPoint(startPoint),
    m_endPoint(endPoint),
    m_outlineColor(outlineColor)
{
}

CLineSegment::~CLineSegment() = default;

const CPoint& CLineSegment::getStartPoint() const
{
    return m_startPoint;
}

const CPoint& CLineSegment::getEndPoint() const
{
    return m_endPoint;
}

std::uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
}

double CLineSegment::GetArea() const
{
    return 0;
}

double CLineSegment::GetPerimeter() const
{
    double deltaX = m_endPoint.x - m_startPoint.x;
    double deltaY = m_endPoint.y - m_startPoint.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

std::string CLineSegment::ToString() const
{
    return "line" +
           std::to_string(m_startPoint.x) +
           std::to_string(m_startPoint.y) +
           std::to_string(m_endPoint.x) +
           std::to_string(m_endPoint.y)
           + "#" + ColorParser::ColorCodeToString(m_outlineColor);
}
