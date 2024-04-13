cmake_minimum_required(VERSION 3.27)
project(GeometryFigures)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(GeometryFigures main.cpp
        include/Figure/Domain/Interfaces/IShape.h
        src/Figure/Domain/Model/CLineSegment.cpp
        include/Figure/Domain/Model/CLineSegment.h
        src/Figure/Domain/Model/CPoint.cpp
        include/Figure/Domain/Model/CPoint.h
        include/Figure/Domain/Interfaces/ISolidShape.h
        src/Figure/Domain/Model/CTriangle.cpp
        include/Figure/Domain/Model/CTriangle.h
        src/Figure/Common/DistanceCalculator.cpp
        include/Figure/Common/DistanceCalculator.h
        src/Figure/Domain/Model/CRectangle.cpp
        include/Figure/Domain/Model/CRectangle.h
        include/Figure/Domain/Model/CRectangle.h
        src/Figure/Domain/Model/CCircle.cpp
        include/Figure/Domain/Model/CCircle.h
        include/Figure/Infrastructure/Interfaces/IFigureRepository.h
        src/Figure/Infrastructure/Persistence/InMemory/FigureRepository.cpp
        include/Figure/Infrastructure/Persistence/InMemory/FigureRepository.h
        src/Figure/Domain/Service/FigureDomainService.cpp
        include/Figure/Domain/Service/FigureDomainService.h
        include/Figure/Domain/ValueObject/FigureTypeEnum.h
        include/Figure/App/Interfaces/IFigureQueryService.h
        src/Figure/App/Service/FigureAppService.cpp
        include/Figure/App/Service/FigureAppService.h
        src/Figure/Infrastructure/Query/FigureQueryService.cpp
        include/Figure/Infrastructure/Query/FigureQueryService.h
        src/Figure/App/Service/DTO/FigureDTO.cpp
        include/Figure/App/Service/DTO/FigureDTO.h
        src/Figure/Common/ColorParser.cpp
        include/Figure/Common/ColorParser.h
)
