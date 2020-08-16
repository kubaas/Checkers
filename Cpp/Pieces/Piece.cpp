//
// Created by jakub on 09.08.2020.
//

#include "../../Headers/Pieces/Piece.h"

Piece::Piece(int x, int y, Color color) {
    this->x = x;
    this->y = y;
    setColor(color);
}

int Piece::getColor() const {
    return this->color;
}

void Piece::setColor(Color color) {
    Piece::color = color;
}

int Piece::getX() const {
    return x;
}

int Piece::getY() const {
    return y;
}

void Piece::setX(int x) {
    Piece::x = x;
}

void Piece::setY(int y) {
    Piece::y = y;
}

