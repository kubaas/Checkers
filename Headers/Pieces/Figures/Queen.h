//
// Created by jakub on 09.08.2020.
//

#ifndef CHECKERS_QUEEN_H
#define CHECKERS_QUEEN_H


#include "../Piece.h"

class Queen : public Piece {
    using Piece::Piece;

    void isMoveValid(std::vector<std::vector<Piece *>> array, int x, int y) override;

public:
    MoveUtil move(std::vector<std::vector<Square>> array, int newX, int newY) override;

private:

    void print() override;

    Piece *checkDiagonal(std::vector<std::vector<Square>> vector, int x0, int y0, int x, int y);
};


#endif //CHECKERS_QUEEN_H
