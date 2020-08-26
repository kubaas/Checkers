//
// Created by jakub on 09.08.2020.
//

#ifndef CHECKERS_BOARD_H
#define CHECKERS_BOARD_H


#include <vector>
#include "../Pieces/Square.h"

class Board {
private:
    mutable std::vector<std::vector<Square>> boardFields;
    int rNumber;
    int wNumber;
    int playerTurn;
    static Board* Instance;
    Board(){}

public:
    Board(Board &other) = delete;
    void operator=(const Board&) = delete;
    static Board *GetInstance();
    ~Board() = default;
    void initialize();
    void printBoard() const;
    void tryMove(int, char, int, char);
    bool checkWinCondition() const;
};


#endif //CHECKERS_BOARD_H
