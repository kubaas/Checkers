//
// Created by jakub on 09.08.2020.
//

#pragma once

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
    int getRNumber() const;
    int getWNumber() const;
    int getPlayerTurn() const;
    void checkBoard();
};
