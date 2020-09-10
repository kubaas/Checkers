//
// Created by jakub on 09.08.2020.
//

#pragma once

#include <memory>
#include "Piece.h"


class Piece;

class Square {
private:
    Piece *piece;
public:
    Square();

    void setPiece(Piece *piece);

    Piece *const getPiece() const;

    bool hasPiece();
};

