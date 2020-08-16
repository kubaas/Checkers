//
// Created by jakub on 09.08.2020.
//

#ifndef CHECKERS_MOVEUTIL_H
#define CHECKERS_MOVEUTIL_H

#include "../Pieces/Piece.h"

enum MoveType {NONE, NORMAL, KILL};

class MoveUtil {
private:
    MoveType type;
    Piece *piece;
public:
    Piece* getPiece() { return piece;}
    MoveUtil(MoveType type) { this->type = type;}
    MoveUtil(MoveType type, Piece *piece) {
        this->type = type;
        this->piece = piece;
    }
};


#endif //CHECKERS_MOVEUTIL_H
