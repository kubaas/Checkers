//
// Created by jakub on 09.08.2020.
//

#pragma once

#include "../Piece.h"

class Queen : public Piece {
    using Piece::Piece;

public:
    ~Queen();
    MoveUtil move(std::vector<std::vector<Square>> array, int newX, int newY) override;
    void print() override;

    char getType() override;

private:
    Piece *checkDiagonal(std::vector<std::vector<Square>> vector, int x0, int y0, int x, int y) const;
};

