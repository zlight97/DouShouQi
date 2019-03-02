#ifndef PIECE_H
#define PIECE_H

#include "GlutApp.h"
#include "Definitions.h"
#include <iostream>

using namespace std;

class Piece
{
public:
    Piece();
    Piece(int strength,Team t);
    ~Piece();
    bool move(int x, int y);
    void draw();
    void clicked(float x, float y);
private:
    Team team;
    string ID;
    int strength;
    int x, y;
};

#endif