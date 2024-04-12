#include <tuple>
#include <iostream>
#include "include/Figure/Infrastructure/Query/FigureQueryService.h"
#include "include/Figure/App/Service/FigureAppService.h"
#include "include/Figure/Infrastructure/Persistence/InMemory/FigureRepository.h"

std::tuple<FigureQueryService*, FigureAppService*> initializeServices() {
    auto* figureRepository = new FigureRepository();
    auto* figureDomainService = new FigureDomainService(figureRepository);
    auto* figureAppService = new FigureAppService(figureDomainService);
    auto figureQueryService = new FigureQueryService(figureRepository);
    return std::make_tuple(figureQueryService, figureAppService);
}

int main() {
    auto [figureQueryService, figureAppService] = initializeServices();

    std::string figureData;
    while (std::getline(std::cin, figureData))
    {
        if (figureData.empty())
        {
            break;
        }
        figureAppService->StoreFigure(figureData);
    }

    FigureDTO* figureWithSmallestPerimeter = figureQueryService->FindFigureWithSmallestPerimeter();
    FigureDTO* figureWithBiggestArea = figureQueryService->FindFigureWithBiggestArea();

    std::cout << figureWithSmallestPerimeter->m_stringRepresentation << std::endl;
    std::cout << figureWithBiggestArea->m_stringRepresentation << std::endl;

    delete figureQueryService;
    delete figureAppService;

    return 0;
}
/*
 * rectangle 10.3 20.15 30.7 40.4 #ff0000 #00ff00
 * circle 2.5 3 1 #ff0000 #00ff00
 */