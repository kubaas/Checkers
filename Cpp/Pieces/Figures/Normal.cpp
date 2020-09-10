//
// Created by jakub on 09.08.2020.
//

#include "../../../Headers/Pieces/Figures/Normal.h"
#include <iostream>

Normal::~Normal() noexcept {
//    std::cout << "Normal destructor" << std::endl;
}

MoveUtil Normal::move(std::vector<std::vector<Square>> boardFields, int newX, int newY) {

    //MoveUtil Board::tryMove(Piece *piece, int newX, int newY) {
    if (boardFields[newX][newY].hasPiece() || (newX + newY) % 2 == 0) {
        return {NONE};
    }

    int x0 = this->getX();
    int y0 = this->getY();

    if (newX - x0 == (int) (this->getColor()) && abs(newY - y0) == 1) {
        return {NORMAL};
    } else if (newX - x0 == (int) (this->getColor()) * 2 && abs(newY - y0) == 2) {
        int x1 = x0 + (newX - x0) / 2;
        int y1 = y0 + (newY - y0) / 2;
        if (boardFields[x1][y1].hasPiece() && boardFields[x1][y1].getPiece()->getColor() != this->getColor()) {
            return {KILL, boardFields[x1][y1].getPiece()};
        }
    }

    return {NONE};
}

void Normal::print() {
    if (this->getColor() == Color(-1))
        std::cout << "nw";
    else
        std::cout << "nr";
}

char Normal::getType() {
    return 'n';
}

