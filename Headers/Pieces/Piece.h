//
// Created by jakub on 09.08.2020.
//

#pragma once

#include <vector>
#include "Square.h"
#include "../Util/MoveUtil.h"

enum Color {RED = 1, WHITE = -1};

class Square;
class MoveUtil;

class Piece {
private:
    int x;
    int y;
    Color color;

public:
    Piece(int x, int y, Color color);

    virtual ~Piece() {};

    int getColor() const;

    void setColor(Color color);

    void setX(int x);

    void setY(int y);

    int getX() const;

    int getY() const;

    virtual MoveUtil move(std::vector<std::vector<Square>> , int , int) = 0;

    virtual void print() = 0;

    virtual char getType() = 0;
};

