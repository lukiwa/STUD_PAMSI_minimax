cmake_minimum_required(VERSION 3.10)
project(STUD_PAMSI_minimax)

set(CMAKE_CXX_STANDARD 17)



if(UNIX)

set(SFML_INCLUDE_DIR "SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "SFML-2.5.1/lib")
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(include)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(STUD_PAMSI_minimax src/main.cpp src/Connect4.cpp include/Connect4.h src/Connect4AI.cpp include/Connect4AI.h include/AIGame.h include/BoardPosition.h src/Connect4UserInterface.cpp include/Connect4UserInterface.h)
target_link_libraries (STUD_PAMSI_minimax sfml-graphics sfml-window sfml-system)

endif()

