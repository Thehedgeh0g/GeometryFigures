//
// Created by flipd on 13.04.2024.
//

#include <utility>

#include "../../../../include/Figure/App/Service/FigureAppService.h"

void FigureAppService::StoreFigure(const std::string& figureData)
{
    m_domainService->StoreFigure(figureData);
}

FigureAppService::FigureAppService(FigureDomainService* mDomainService) : m_domainService(mDomainService)
{}
