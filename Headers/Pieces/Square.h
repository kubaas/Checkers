//
// Created by jakub on 09.08.2020.
//

#ifndef CHECKERS_SQUARE_H
#define CHECKERS_SQUARE_H

#include "Piece.h"

class Piece;

class Square {
private:
    Piece* piece;
public:
    Square();

    void setPiece(Piece *piece);

    Piece *getPiece() const;

    bool hasPiece();
};


#endif //CHECKERS_SQUARE_H
