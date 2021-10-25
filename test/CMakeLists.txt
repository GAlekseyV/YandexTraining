find_package(Catch2 REQUIRED)

include(CTest)
include(Catch)

add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)
target_link_libraries(catch_main PRIVATE project_options)

add_subdirectory(HW_B1)
add_subdirectory(HW_B2)
add_subdirectory(HW_B3)
add_subdirectory(HW_B4)
add_subdirectory(HW_B5)
add_subdirectory(HW_B6)
