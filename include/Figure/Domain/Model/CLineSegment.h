//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CLINESEGMENT_H
#define GEOMETRYFIGURES_CLINESEGMENT_H


#include "../Interfaces/IShape.h"
#include "CPoint.h"

class CLineSegment : public IShape
{
private:
    CPoint m_startPoint;
    CPoint m_endPoint;
    uint32_t m_outlineColor;
public:
    CLineSegment(const CPoint& startPoint, const CPoint& endPoint, const uint32_t& outlineColor);

    ~CLineSegment() override;

    [[nodiscard]] std::uint32_t GetOutlineColor() const override;

    [[nodiscard]] const CPoint& getStartPoint() const;

    [[nodiscard]] const CPoint& getEndPoint() const;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;
};


#endif //GEOMETRYFIGURES_CLINESEGMENT_H
