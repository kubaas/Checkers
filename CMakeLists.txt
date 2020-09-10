cmake_minimum_required(VERSION 3.16)
project(checkers CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    Cpp/Board/Board.cpp
    Cpp/Pieces/Piece.cpp
    Cpp/Pieces/Square.cpp
    Cpp/Pieces/Figures/Normal.cpp
    Cpp/Pieces/Figures/Queen.cpp
    Cpp/Util/MoveUtil.cpp
)

add_executable(checkers main.cpp)
add_library(source_files SHARED ${SOURCES})
target_link_libraries(checkers source_files)
