cmake_minimum_required(VERSION 3.14)

project(Practice LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Practice
    main.cpp
    SumTest.cpp
    SumMock.h
    SumMock.cpp
    SumMock.h
)

add_subdirectory(SumService/)
add_subdirectory(Display/)
add_subdirectory(googletest/)
add_subdirectory(googlemock/)

# Link libraries
target_link_libraries(Practice
    Qt${QT_VERSION_MAJOR}::Core
    gtest
    gmock
    sumservice
    display
)

# Include directories
target_include_directories(Practice PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/SumService
    ${CMAKE_CURRENT_SOURCE_DIR}/Display
    googlemock/
    googletest/
)

include(GNUInstallDirs)
install(TARGETS Practice
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
