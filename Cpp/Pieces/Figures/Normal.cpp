//
// Created by jakub on 09.08.2020.
//

#include "../../../Headers/Pieces/Figures/Normal.h"
#include <iostream>
void Normal::isMoveValid(std::vector<std::vector<Piece *>> array, int x, int y) {
    std::cout<<"1";
}

void Normal::move(std::vector<std::vector<Piece *>> array) {
    std::cout<<"1";
}

void Normal::print() {
    if(this->getColor() == Color(-1))
        std::cout<<"nw";
    else
        std::cout<<"nr";
}
