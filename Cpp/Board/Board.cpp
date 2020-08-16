//
// Created by jakub on 09.08.2020.
//

#include "../../Headers/Board/Board.h"
#include "../../Headers/Pieces/Figures/Normal.h"

#include <iostream>

const std::vector<std::vector<Square>> &Board::getBoardFields() const {
    return boardFields;
}

void Board::setBoardFields(const std::vector<std::vector<Square>> &boardFields) {
    Board::boardFields = boardFields;
}

void Board::initialize() {
    for (int x = 0; x < 8; x++) {
        std::vector<Square> v1;
        for (int y = 0; y < 8; y++) {
            v1.push_back(Square());
        }
        boardFields.push_back(v1);
    }


    for (int x = 5; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if((x+y)%2) {
                this->boardFields[x][y].setPiece(new Normal(x,y,Color(-1)));
            } // WHITE
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 8; y++) {
            if((x+y)%2) {
                this->boardFields[x][y].setPiece(new Normal(x,y,Color(1)));
            } // RED
        }
    }

}

Square Board::getBoardField(int x, int y) {
    return boardFields[x][y];
}

void Board::printBoard() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if(boardFields[x][y].hasPiece() == true) {
                boardFields[x][y].getPiece() -> print();
            } else if (boardFields[x][y].hasPiece() != true && (x+y)%2) {
                std::cout << ". ";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout<<std::endl;
    }
}

void Board::setBoardField(Square square) {
    boardFields[square.getPiece()->getX()][square.getPiece()->getY()] = square;
}

MoveUtil Board::tryMove(Piece *piece, int newX, int newY) {
    if (boardFields[newX][newY].hasPiece())
    return MoveUtil(NONE);
}
