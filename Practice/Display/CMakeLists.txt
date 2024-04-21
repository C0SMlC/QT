project(Display LANGUAGES CXX)

add_library(display SHARED
    display.cpp
    display.h
)

target_include_directories(display PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
