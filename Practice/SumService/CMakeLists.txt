project(SumService LANGUAGES CXX)

add_library(sumservice SHARED
    sum.cpp
    sum.h
)

target_include_directories(sumservice PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../Display
)

target_link_libraries(sumservice PRIVATE display)
