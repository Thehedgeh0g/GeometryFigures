//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CCIRCLE_H
#define GEOMETRYFIGURES_CCIRCLE_H


#include "../Interfaces/ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
    //todo: public -> protected -> private
private:
    CPoint m_center;
    double m_radius;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
public:

    CCircle(const CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor);

    ~CCircle() override;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    //
    [[nodiscard]] const CPoint& GetCenter() const;

    [[nodiscard]] double GetRadius() const;
};


#endif //GEOMETRYFIGURES_CCIRCLE_H
