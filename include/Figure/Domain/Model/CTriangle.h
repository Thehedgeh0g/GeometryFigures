//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CTRIANGLE_H
#define GEOMETRYFIGURES_CTRIANGLE_H


#include "../Interfaces/ISolidShape.h"
#include "CPoint.h"

class CTriangle : public ISolidShape
{
private:
    CPoint m_vertex1;
    CPoint m_vertex2;
    CPoint m_vertex3;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
public:
    CTriangle(
        const CPoint& vertex1,
        const CPoint& vertex2,
        const CPoint& vertex3,
        const uint32_t& outlineColor,
        const uint32_t& fillColor
    );

    ~CTriangle() override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    CPoint GetVertex1();

    CPoint GetVertex2();

    CPoint GetVertex3();

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;
};


#endif //GEOMETRYFIGURES_CTRIANGLE_H
