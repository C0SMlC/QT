cmake_minimum_required(VERSION 3.5)

project(VehicleHealthMonitorSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Models/)
add_subdirectory(googletest/)
add_subdirectory(googlemock/)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(VehicleHealthMonitorSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Models/filtermodel.h Models/filtermodel.cpp
        Models/fluidmodel.h Models/fluidmodel.cpp
        images.qrc
        FilterGoogleTest.cpp
        FluidGoogleTest.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET VehicleHealthMonitorSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(VehicleHealthMonitorSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(VehicleHealthMonitorSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(VehicleHealthMonitorSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets gtest gmock)
target_include_directories(VehicleHealthMonitorSystem PRIVATE Models/ googletest/ googlemock/)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.VehicleHealthMonitorSystem)
endif()
set_target_properties(VehicleHealthMonitorSystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS VehicleHealthMonitorSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(VehicleHealthMonitorSystem)
endif()
