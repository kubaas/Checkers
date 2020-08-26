//
// Created by jakub on 09.08.2020.
//

#ifndef CHECKERS_BOARD_H
#define CHECKERS_BOARD_H


#include <vector>
#include "../Pieces/Square.h"

class Board {
private:
    std::vector<std::vector<Square>> boardFields;
    const static char kLegalSpace = '.';
    const static char kIllegaleSpace = ' ';
    const static char kValidPlayerO = 'o';
    const static char kValidPlayerX = 'x';
    int rNumber;
    int wNumber;
//    MoveUtil tryMove(Piece* piece, int newX, int newY);

public:
    const std::vector<std::vector<Square>> &getBoardFields() const;
    void setBoardFields(const std::vector<std::vector<Square>> &boardFields);
    void initialize();
    Square getBoardField(int, int) const;
    void printBoard();
    void setBoardField(Square);
    void tryMove(int, char, int, char);
    bool checkWinCondition();
};


#endif //CHECKERS_BOARD_H
