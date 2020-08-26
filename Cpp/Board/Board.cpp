//
// Created by jakub on 09.08.2020.
//

#include "../../Headers/Board/Board.h"
#include "../../Headers/Pieces/Figures/Normal.h"
#include "../../Headers/Pieces/Figures/Queen.h"

#include <iostream>
#include <cmath>

const char tab[] = "ABCDEFGH";


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

    this->wNumber = 0;
    this->rNumber = 0;

    for (int x = 5; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2) {
                this->boardFields[x][y].setPiece(new Queen(x, y, Color(-1)));
                this->wNumber++;
            } // WHITE
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2) {
                this->boardFields[x][y].setPiece(new Normal(x, y, Color(1)));
                this->rNumber++;
            } // RED
        }
    }

}

Square Board::getBoardField(int x, int y) const {
    return boardFields[x][y];
}

void Board::printBoard() {
    for (int x = 0; x < 8; x++) {
        std::cout << x + 1 << " ";
        for (int y = 0; y < 8; y++) {
            if (boardFields[x][y].hasPiece() == true) {
                boardFields[x][y].getPiece()->print();
//                std::cout << x << y;
            } else if (boardFields[x][y].hasPiece() != true && (x + y) % 2) {
                std::cout << ". ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  ";

    for (int y = 0; y < 8; y++) {
        std::cout << tab[y] << " ";
    }

    if(checkWinCondition() == true) exit(0);

}

void Board::setBoardField(Square square) {
    boardFields[square.getPiece()->getX()][square.getPiece()->getY()] = square;
}


void Board::tryMove(int old_number, char old_letter, int new_number, char new_letter) {
    int oldX = int(old_number) - 1, oldY = 0;
    int newX = int(new_number) - 1, newY = 0;
    int j = 0;
    for (char i : tab) {
        if (i == old_letter)
            oldY = j;
        ++j;
    }
    j = 0;
    for (char i : tab) {
        if (i == new_letter)
            newY = j;
        ++j;
    }

    std::cout << oldX << " " << oldY << std::endl;
    std::cout << newX << " " << newY << std::endl;

    MoveUtil trymv = NONE;

    if (boardFields[oldX][oldY].hasPiece() && !boardFields[newX][newY].hasPiece()) {
        trymv = boardFields[oldX][oldY].getPiece()->move(boardFields, newX, newY);
    }


    switch (trymv.getType()) {

        case NONE:
            break;
        case NORMAL:
        {
            Piece* piece = boardFields[oldX][oldY].getPiece();
            piece->setX(newX);
            piece->setY(newY);
            boardFields[newX][newY].setPiece(piece);
            boardFields[oldX][oldY].setPiece(nullptr);
            break;
        }

        case KILL:
            Piece* piece = boardFields[oldX][oldY].getPiece();
            piece->setX(newX);
            piece->setY(newY);
            boardFields[newX][newY].setPiece(piece);
            boardFields[oldX][oldY].setPiece(nullptr);

            Piece* otherPiece = trymv.getPiece();
            boardFields[otherPiece->getX()][otherPiece->getY()].setPiece(nullptr);

            if(piece->getColor() == 1) this->wNumber--;
            else this->rNumber--;

            break;

    }
}

bool Board::checkWinCondition() {

    if(rNumber == 0)
    {
        std::cout << "White player wins" << std::endl;
        return true;
    }
    else if (wNumber == 0)
    {
        std::cout << "Red player wins" << std::endl;
        return true;
    }
    else return false;

}


