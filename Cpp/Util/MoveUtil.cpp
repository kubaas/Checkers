//
// Created by jakub on 09.08.2020.
//

#include "../../Headers/Util/MoveUtil.h"

MoveUtil::MoveUtil(MoveType type, Piece *piece) {
    this->type = type;
    this->piece = piece;
}

MoveUtil::MoveUtil(MoveType type) {
    this->type = type;
}

Piece* MoveUtil::getPiece() const {
    return this->piece;
}