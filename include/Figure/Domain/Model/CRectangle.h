//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CRECTANGLE_H
#define GEOMETRYFIGURES_CRECTANGLE_H


#include "../Interfaces/ISolidShape.h"
#include "CPoint.h"

class CRectangle : public ISolidShape
{
private:
    CPoint m_rightTopVertex;
    CPoint m_leftBottomVertex;
    double m_height;
    double m_width;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
public:
    CRectangle(
        const CPoint& rightTopVertex,
        const CPoint& leftBottomVertex,
        const uint32_t& outlineColor,
        const uint32_t& fillColor
    );

    ~CRectangle() override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    [[nodiscard]] const CPoint& GetRightTopVertex() const;

    [[nodiscard]] const CPoint& GetLeftBottomVertex() const;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;
};


#endif //GEOMETRYFIGURES_CRECTANGLE_H
