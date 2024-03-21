project(services LANGUAGES CXX)

add_library(services SHARED
service.cpp
service.h)

target_link_libraries(services PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
