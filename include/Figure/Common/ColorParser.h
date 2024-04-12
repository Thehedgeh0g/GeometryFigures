//
// Created by flipd on 13.04.2024.
//

#ifndef GEOMETRYFIGURES_COLORPARSER_H
#define GEOMETRYFIGURES_COLORPARSER_H


#include <cstdint>
#include <string>

class ColorParser
{
public:
    static uint32_t ParseColorCode(const std::string& colorCode);

    static std::string ColorCodeToString(uint32_t color);
};


#endif //GEOMETRYFIGURES_COLORPARSER_H
