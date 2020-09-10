//
// Created by jakub on 09.08.2020.
//

#pragma once

#include "../../Util/MoveUtil.h"

class Normal : public Piece {
public:
    using Piece::Piece;
    ~Normal();
    MoveUtil move(std::vector<std::vector<Square>> array, int newX, int newY) override;
    void print() override;

    char getType() override;
};

