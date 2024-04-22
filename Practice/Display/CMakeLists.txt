project(Display LANGUAGES CXX)

find_package(QT NAMES Qt6 COMPONENTS Core REQUIRED)

include_directories(${Qt6_INCLUDE_DIRS})

add_library(display SHARED


  newdisplay.h newdisplay.cpp
)

target_link_libraries(display PRIVATE Qt6::Core)
