project(DataProvider LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql REQUIRED)

add_library(dataprovider OBJECT
    dataprovider.cpp
    dataprovider.h
)

target_link_libraries(dataprovider PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(dataprovider PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
