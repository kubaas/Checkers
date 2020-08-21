//
// Created by jakub on 09.08.2020.
//

#include "../../Headers/Board/Board.h"
#include "../../Headers/Pieces/Figures/Normal.h"

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


    for (int x = 5; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2) {
                this->boardFields[x][y].setPiece(new Normal(x, y, Color(-1)));
            } // WHITE
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2) {
                this->boardFields[x][y].setPiece(new Normal(x, y, Color(1)));
            } // RED
        }
    }

}

Square Board::getBoardField(int x, int y) {
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

}

void Board::setBoardField(Square square) {
    boardFields[square.getPiece()->getX()][square.getPiece()->getY()] = square;
}

//MoveUtil Board::tryMove(Piece *piece, int newX, int newY) {
//    if (boardFields[newX][newY].hasPiece() || (newX + newY) % 2 == 0) {
//        std::cout << "fff2 " << boardFields[newX][newY].hasPiece() << std::endl;
//        return MoveUtil(NONE);
//    }
//
//
//
//    int x0 = piece->getX();
//    int y0 = piece->getY();
//
//    std::cout << "fff5 " << x0 << " " << y0 << " " << piece->getColor() << " " << boardFields[x0][y0].hasPiece() << std::endl;
//    std::cout << newX << " " << newY << std::endl;
//    if (newX - x0 == (int) (piece->getColor()) && abs(newY - y0) == 1) {
//        std::cout << "fff6" << std::endl;
//
//        return MoveUtil(NORMAL);
//    } else if (abs(newX - x0) == 2 && newY - y0 == (int) (piece->getColor()) * 2) {
//        int x1 = x0 + (newX - x0) / 2;
//        int y1 = y0 + (newY - y0) / 2;
//        if (boardFields[x1][y1].hasPiece() && boardFields[x1][y1].getPiece()->getColor() != piece->getColor()) {
//            return MoveUtil(KILL, boardFields[x1][y1].getPiece());
//        }
//    }
//
//    return MoveUtil(NONE);
//
//}

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
    std::cout << "ffff1" << std::endl;

    MoveUtil trymv = NONE;

    if (boardFields[oldX][oldY].hasPiece() && !boardFields[newX][newY].hasPiece()) {
        trymv = boardFields[oldX][oldY].getPiece()->move(boardFields, newX, newY);
        std::cout << "ffff4 " << trymv.getType() << std::endl;
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

            break;

    }
}
