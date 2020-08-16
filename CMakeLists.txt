cmake_minimum_required(VERSION 3.17)
project(checkers)

set(CMAKE_CXX_STANDARD 14)

add_executable(checkers main.cpp Cpp/Pieces/Piece.cpp Headers/Pieces/Piece.h Cpp/Pieces/Square.cpp Headers/Pieces/Square.h Cpp/Board/Board.cpp Headers/Board/Board.h Cpp/Util/MoveUtil.cpp Headers/Util/MoveUtil.h Cpp/Pieces/Figures/Normal.cpp Headers/Pieces/Figures/Normal.h Cpp/Pieces/Figures/Queen.cpp Headers/Pieces/Figures/Queen.h Cpp/Pieces/IllegalSpace.cpp Headers/Pieces/IllegalSpace.h)