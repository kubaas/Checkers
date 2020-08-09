//
// Created by jakub on 09.08.2020.
//

#ifndef CHECKERS_PIECE_H
#define CHECKERS_PIECE_H


#include "Square.h"

class Piece : Square {
public:
    Piece(int x, int y);

    virtual void isMoveValid();

    virtual void move();

    virtual void print();
};


#endif //CHECKERS_PIECE_H
