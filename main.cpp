#include <iostream>
#include "Headers/Board/Board.h"

int main() {

    int choice, x = 0, y = 0;
    Board board;
    board.initialize();

    while (1) {
        board.printBoard();
        int oldX, newX;
        char oldY, newY;

        std::cout << "Pick your piece: number letter" << std::endl;
        std::cin >> oldX;
        std::cin >> oldY;

        std::cout << "Pick your move: number letter" << std::endl;
        std::cin >> newX;
        std::cin >> newY;

        board.tryMove(oldX, oldY, newX, newY);
    }


    return 0;
}
