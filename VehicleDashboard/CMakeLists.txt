cmake_minimum_required(VERSION 3.5)
project(VehicleDashboard VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
    main.cpp
    vehicledashboard.cpp
    vehicledashboard.h
    vehicledashboard.ui

    models/userModel.h
    models/userModel.cpp
    models/vehicleInfoModel.h
    models/vehicleInfoModel.cpp
)

add_subdirectory(DataBase)
add_subdirectory(DataProvider)
add_subdirectory(models/)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(VehicleDashboard
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        vehicleinstrumentpanel.h vehicleinstrumentpanel.cpp vehicleinstrumentpanel.ui
        usersettingsdialog.h usersettingsdialog.cpp usersettingsdialog.ui
        addoperatordialog.h addoperatordialog.cpp addoperatordialog.ui
        images.qrc


    )
else()
    if(ANDROID)
        add_library(VehicleDashboard SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(VehicleDashboard
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(VehicleDashboard PUBLIC
DataBase/
DataProvider/
)

target_link_libraries(VehicleDashboard PRIVATE
    database
    dataprovider
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.VehicleDashboard)
endif()
set_target_properties(VehicleDashboard PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS VehicleDashboard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(VehicleDashboard)
endif()
