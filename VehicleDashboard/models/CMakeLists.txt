project(models LANGUAGES CXX)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets REQUIRED)


add_library(models OBJECT
    userModel.cpp
    userModel.h
    vehicleInfoModel.cpp
    vehicleInfoModel.h
)

target_link_libraries(models PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
