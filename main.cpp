#include <tuple>
#include <iostream>
#include "include/Figure/Infrastructure/Query/FigureQueryService.h"
#include "include/Figure/App/Service/FigureAppService.h"
#include "include/Figure/Infrastructure/Persistence/InMemory/FigureRepository.h"

std::tuple<FigureQueryService*, FigureAppService*> initializeServices()
{
    auto* figureRepository = new FigureRepository();
    auto* figureDomainService = new FigureDomainService(figureRepository);
    auto* figureAppService = new FigureAppService(figureDomainService);
    auto figureQueryService = new FigureQueryService(figureRepository);
    return std::make_tuple(figureQueryService, figureAppService);
}

void PrintInstruction()
{
    std::cout << "data format:\n"
                 "rectangle {right_top_vertex.x} {right_top_vertex.y} {left_bottom_vertex.x} {left_bottom_vertex.y} {outline_color} {fill_color}\n"
                 "circle {center.x} {center.y} {radius} {outline_color} {fill_color}\n"
                 "triangle {vertex1.x} {vertex1.y} {vertex2.x} {vertex2.y} {vertex3.x} {vertex3.y} {outline_color} {fill_color}\n"
                 "line {vertex1.x} {vertex1.y} {vertex2.x} {vertex2.y} {outline_color}\n"
                 "To exit enter empty string\n";
}

int main()
{
    auto [figureQueryService, figureAppService] = initializeServices();

    std::string figureData;
    system("cls");
    PrintInstruction();
    while (std::getline(std::cin, figureData))
    {
        system("cls");
        PrintInstruction();
        if (figureData.empty())
        {
            break;
        }
        figureAppService->StoreFigure(figureData);
    }

    FigureDTO* figureWithSmallestPerimeter = figureQueryService->FindFigureWithSmallestPerimeter();
    FigureDTO* figureWithBiggestArea = figureQueryService->FindFigureWithBiggestArea();

    std::cout << figureWithSmallestPerimeter->m_stringRepresentation << std::endl
              << "Perimeter: " << figureWithSmallestPerimeter->m_perimeter << std::endl;
    std::cout << figureWithBiggestArea->m_stringRepresentation << std::endl
              << "Area: " << figureWithBiggestArea->m_area << std::endl;

    std::cout << "Press any button to exit...";
    std::cin.get();

    delete figureQueryService;
    delete figureAppService;

    return 0;
}
/*
 * rectangle 10.3 20.15 30.7 40.4 #ff0000 #00ff00
 * circle 2.5 3 1 #ff0000 #00ff00
 */