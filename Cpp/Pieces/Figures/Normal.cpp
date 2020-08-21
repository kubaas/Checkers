//
// Created by jakub on 09.08.2020.
//

#include "../../../Headers/Pieces/Figures/Normal.h"
#include "../../../Headers/Util/MoveUtil.h"

#include <iostream>
void Normal::isMoveValid(std::vector<std::vector<Piece *>> array, int x, int y) {
    std::cout<<"1";
}

MoveUtil Normal::move(std::vector<std::vector<Square>> boardFields, int newX, int newY)  {

   //MoveUtil Board::tryMove(Piece *piece, int newX, int newY) {
    if (boardFields[newX][newY].hasPiece() || (newX + newY) % 2 == 0) {
        std::cout << "fff2 " << boardFields[newX][newY].hasPiece() << std::endl;
        return {NONE};
    }



    int x0 = this->getX();
    int y0 = this->getY();

    std::cout << "fff5 " << x0 << " " << y0 << " " << this->getColor() << " " << boardFields[x0][y0].hasPiece() << std::endl;
    std::cout << newX << " " << newY << std::endl;
    std:: cout << (newX - x0 == (this->getColor()) * 2) << "    " << (abs(newY - y0) == 2) << std::endl;
    if (newX - x0 == (int) (this->getColor()) && abs(newY - y0) == 1) {
        std::cout << "fff6" << std::endl;


        return {NORMAL};
    } else if (newX - x0 == (int) (this->getColor()) * 2 && abs(newY - y0) == 2) {
        std::cout << "fff/KILL" << std::endl;
        int x1 = x0 + (newX - x0) / 2;
        int y1 = y0 + (newY - y0) / 2;
        if (boardFields[x1][y1].hasPiece() && boardFields[x1][y1].getPiece()->getColor() != this->getColor()) {
            return MoveUtil(KILL, boardFields[x1][y1].getPiece());
        }
    } else {
        std::cout << "fff/NONE" << std::endl;
        return {NONE};
    }


//}
}

void Normal::print() {
    if(this->getColor() == Color(-1))
        std::cout<<"nw";
    else
        std::cout<<"nr";
}

