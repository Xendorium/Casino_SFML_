cmake_minimum_required(VERSION 3.25)
project(Casino_SFML_)

set(CMAKE_CXX_STANDARD 17)

add_executable(Casino_SFML_ WIN32 main.cpp Games.h Game_selection.cpp Game_selection.h Drawing.cpp Drawing.h Blackjack.cpp Blackjack.h Deck.h Players.cpp Players.h Slots.cpp Slots.h)

include_directories(headers C:/SFML/include)

set(SFML_ROOT C:/SFML)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake_modules)

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Casino_SFML_ ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Copy dlls to build
if (WIN32)
    file(GLOB BINARY_DEP_DLLS ${SFML_INCLUDE_DIR}/../bin/*.dll)
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()