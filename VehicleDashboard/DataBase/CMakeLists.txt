project(DataBase LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql REQUIRED)


add_library(database OBJECT
    database.cpp
    database.h
)

target_link_libraries(database PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(database PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
