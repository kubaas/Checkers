//
// Created by jakub on 09.08.2020.
//

#include "../../Headers/Board/Board.h"
#include "../../Headers/Pieces/Figures/Normal.h"
#include "../../Headers/Pieces/Figures/Queen.h"

#include <iostream>

const char tab[] = "ABCDEFGH";

Board *Board::Instance = nullptr;

void Board::initialize() {

    for (int x = 0; x < 8; x++) {
        std::vector<Square> v1;
        for (int y = 0; y < 8; y++) {
            v1.push_back(Square());
        }
        boardFields.push_back(v1);
    }

    this->wNumber = 0;
    this->rNumber = 0;

    for (int x = 5; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2) {
                this->boardFields[x][y].setPiece(new Normal(x, y, Color(-1)));
                this->wNumber++;
            } // WHITE
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2) {
                this->boardFields[x][y].setPiece(new Normal(x, y, Color(1)));
                this->rNumber++;
            } // RED
        }
    }

    playerTurn = -1; // WHITE

}


void Board::printBoard() const{
    for (int x = 0; x < 8; x++) {
        std::cout << x + 1 << " ";
        for (int y = 0; y < 8; y++) {
            if (boardFields[x][y].hasPiece()) {
                boardFields[x][y].getPiece()->print();
            } else if (!boardFields[x][y].hasPiece() && (x + y) % 2) {
                std::cout << ". ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  ";

    for (int y = 0; y < 8; y++) {
        std::cout << tab[y] << " ";
    }
}


void Board::tryMove(int old_number, char old_letter, int new_number, char new_letter) {
    int oldX = int(old_number) - 1, oldY = 0;
    int newX = int(new_number) - 1, newY = 0;
    int j = 0;
    for (char i : tab) {
        if (i == old_letter)
            oldY = j;
        ++j;
    }
    j = 0;
    for (char i : tab) {
        if (i == new_letter)
            newY = j;
        ++j;
    }


    MoveUtil trymv = NONE;

    if (boardFields[oldX][oldY].hasPiece() && !boardFields[newX][newY].hasPiece() && playerTurn == boardFields[oldX][oldY].getPiece()->getColor()) {
        trymv = boardFields[oldX][oldY].getPiece()->move(boardFields, newX, newY);
        if (playerTurn == 1) playerTurn = -1;
        else playerTurn = 1;
    }


    switch (trymv.getType()) {

        case NONE:
            break;
        case NORMAL: {
            Piece *piece = boardFields[oldX][oldY].getPiece();
            piece->setX(newX);
            piece->setY(newY);

            if ((piece->getColor() == 1 && newX == 7) || (piece->getColor() == -1 && newX == 0)) {
                int color = piece->getColor();
                boardFields[newX][newY].setPiece(new Queen(newX, newY, Color(color)));
            } else boardFields[newX][newY].setPiece(piece);

            boardFields[oldX][oldY].setPiece(nullptr);
            break;
        }

        case KILL:
            Piece *piece = boardFields[oldX][oldY].getPiece();
            piece->setX(newX);
            piece->setY(newY);
            if ((piece->getColor() == 1 && newX == 7) || (piece->getColor() == -1 && newX == 0)) {
                int color = piece->getColor();
                boardFields[newX][newY].setPiece(new Queen(newX, newY, Color(color)));
            } else boardFields[newX][newY].setPiece(piece);
            boardFields[oldX][oldY].setPiece(nullptr);

            Piece *otherPiece = trymv.getPiece();
            boardFields[otherPiece->getX()][otherPiece->getY()].setPiece(nullptr);

            if (piece->getColor() == 1) this->wNumber--;
            else this->rNumber--;

            break;
    }
}

bool Board::checkWinCondition() const {

    if (rNumber == 0) {
        std::cout << "White player wins" << std::endl;
        return true;
    } else if (wNumber == 0) {
        std::cout << "Red player wins" << std::endl;
        return true;
    } else return false;

}

Board *Board::GetInstance() {
    if (Instance == nullptr) {
        Instance = new Board();
    }
    return Instance;
}

int Board::getRNumber() const {
    return rNumber;
}

int Board::getWNumber() const {
    return wNumber;
}

int Board::getPlayerTurn() const {
    return playerTurn;
}

void Board::checkBoard() {

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(playerTurn == boardFields[i][j].getPiece()->getColor())
            {
                if (boardFields[i][j].getPiece()->getType() == 'n')
                {

//                        if (boardFields[i+playerTurn][j+1].hasPiece() || boardFields[i+playerTurn][j+1].hasPiece()
                                    
                }
            }
        }
    }
}


