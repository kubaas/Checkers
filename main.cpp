#include <iostream>
#include "Headers/Board/Board.h"
#define clear() printf("\033[H\033[J")

int main() {

    int choice, x = 0, y = 0;
    Board *board = Board::GetInstance();
    board->initialize();


    while (board->checkWinCondition() != true) {

        std::cout << "Score for white: " << 12 - board->getRNumber() << std::endl;
        std::cout << "Score for red: " << 12 - board->getWNumber() << std::endl << std::endl;

        board->printBoard();
        int oldX, newX;
        char oldY, newY;

        std::cout << std::endl;
        if(board->getPlayerTurn() == -1) { std::cout << std::endl << "Turn: WHITE" << std::endl; }
        else { std::cout << std::endl << "Turn: RED" << std::endl; }
        std::cout << "Pick your piece (number letter): " << std::endl;
        std::cin >> oldX;
        std::cin >> oldY;

        std::cout << "Pick your move (number letter): " << std::endl;
        std::cin >> newX;
        std::cin >> newY;

        board->tryMove(oldX, oldY, newX, newY);
        clear();
    }


    return 0;
}
