project(VehicleHealthMonitorSystem)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(Models SHARED filtermodel.cpp filtermodel.h
    fluidmodel.h fluidmodel.cpp)

# target_include_directories(Models PUBLIC )
target_link_libraries(Models PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
