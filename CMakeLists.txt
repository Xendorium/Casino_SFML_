cmake_minimum_required(VERSION 3.25)
project(Casino_SFML_)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Games.cpp Games.h Game_selection.cpp Game_selection.h)
add_executable(Casino_SFML_ ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Casino_SFML_ ${SFML_LIBRARIES})
endif()