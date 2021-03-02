cmake_minimum_required (VERSION 3.13)

set (CMAKE_PREFIX_PATH "../../share")
message ("Prefix path: ${CMAKE_PREFIX_PATH}")

find_package (royale REQUIRED)

link_directories (${royale_LIB_DIR})

project (pico_tof_cam)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../inc)

add_executable (tofRetrieveData tofRetrieveData.cpp)

copy_royale_libs (tofRetrieveData)

target_link_libraries (tofRetrieveData "${royale_LIBS}")
