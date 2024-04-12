//
// Created by flipd on 13.04.2024.
//

#ifndef GEOMETRYFIGURES_FIGUREDTO_H
#define GEOMETRYFIGURES_FIGUREDTO_H


#include <string>
#include <cstdint>
#include <memory>

class FigureDTO
{
public:
    const double m_area;
    const double m_perimeter;
    const uint32_t m_outlineColor;
    const std::unique_ptr<uint32_t> m_fillColor;
    const std::string m_stringRepresentation;

    FigureDTO(
        double area,
        double perimeter,
        uint32_t outlineColor,
        std::unique_ptr<uint32_t> fillColor,
        std::string stringRepresentation
    );
};


#endif //GEOMETRYFIGURES_FIGUREDTO_H
