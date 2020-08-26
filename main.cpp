#include <iostream>
#include "Headers/Board/Board.h"

int main() {

    int choice, x = 0, y = 0;
    Board *board = Board::GetInstance();
    board->initialize();

    while (board->checkWinCondition() != true) {
        board->printBoard();
        int oldX, newX;
        char oldY, newY;

        std::cout << std::endl << std::endl << "Pick your piece (number letter): " << std::endl;
        std::cin >> oldX;
        std::cin >> oldY;

        std::cout << "Pick your move (number letter): " << std::endl;
        std::cin >> newX;
        std::cin >> newY;

        board->tryMove(oldX, oldY, newX, newY);
    }


    return 0;
}
