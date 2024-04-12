//
// Created by flipd on 13.04.2024.
//

#ifndef GEOMETRYFIGURES_FIGUREAPPSERVICE_H
#define GEOMETRYFIGURES_FIGUREAPPSERVICE_H


#include "../../Domain/Service/FigureDomainService.h"
#include "../Interfaces/IFigureQueryService.h"

class FigureAppService
{
private:
    FigureDomainService* m_domainService;
public:
    explicit FigureAppService(FigureDomainService* mDomainService);

    void StoreFigure(const std::string& figureData);
};


#endif //GEOMETRYFIGURES_FIGUREAPPSERVICE_H
