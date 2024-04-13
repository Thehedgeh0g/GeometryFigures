//
// Created by flipd on 13.04.2024.
//

#include <sstream>
#include <iomanip>
#include "../../../include/Figure/Common/ColorParser.h"

uint32_t ColorParser::ParseColorCode(const std::string& colorCode)
{
    if (colorCode.size() != 7 || colorCode[0] != '#' ||
        colorCode.find_first_not_of("0123456789abcdefABCDEF", 1) != std::string::npos)
    {
        throw std::invalid_argument("Invalid color code format");
    }

    std::istringstream iss(colorCode.substr(1));
    uint32_t color = 0;
    iss >> std::hex >> color;

    return color;
}

std::string ColorParser::ColorCodeToString(uint32_t color)
{
    int red = (color >> 16) & 0xFF;
    int green = (color >> 8) & 0xFF;
    int blue = color & 0xFF;

    std::ostringstream oss;
    oss << std::hex << std::setw(2) << std::setfill('0') << red;
    oss << std::hex << std::setw(2) << std::setfill('0') << green;
    oss << std::hex << std::setw(2) << std::setfill('0') << blue;

    return "#" + oss.str();
}
