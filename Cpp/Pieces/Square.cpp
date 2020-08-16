//
// Created by jakub on 09.08.2020.
//

#include "../../Headers/Pieces/Square.h"


void Square::setPiece(Piece *piece) {
    Square::piece = piece;
}

Piece *Square::getPiece() const {
    return piece;
}

bool Square::hasPiece() {
    return this->piece != nullptr;
}

Square::Square() {

    this->piece = NULL;

}
