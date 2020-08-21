//
// Created by jakub on 09.08.2020.
//

#include "../../../Headers/Pieces/Figures/Queen.h"
#include <iostream>

void Queen::isMoveValid(std::vector<std::vector<Piece *>> array, int x, int y) {
    std::cout<<"1";
}


void Queen::print() {
    std::cout<<"q ";
}

MoveUtil Queen::move(std::vector<std::vector<Square>> vector, int i, int i1) {
    return MoveUtil(KILL);
}
