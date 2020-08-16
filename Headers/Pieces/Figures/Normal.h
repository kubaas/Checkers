//
// Created by jakub on 09.08.2020.
//

#ifndef CHECKERS_NORMAL_H
#define CHECKERS_NORMAL_H


#include "../Piece.h"

class Normal : public Piece {
public:
    using Piece::Piece;

    void isMoveValid(std::vector<std::vector<Piece *>> array, int x, int y) override;

    void move(std::vector<std::vector<Piece *>> array) override;

    void print() override;
};


#endif //CHECKERS_NORMAL_H
