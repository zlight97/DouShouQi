#ifndef PIECE_H
#define PIECE_H
#include "TextRect.h"
#include "GlutApp.h"
#include <iostream>

using namespace std;

class Piece
{
public:
    Piece();
    Piece(int x, int y, int strength,Team t);
    ~Piece();
    bool move(int x, int y);
    void draw();
    void clicked(float x, float y);
    void updatePiece(int x, int y, int strength,Team t);
    void stage();
    int getX() {return x;}
    int getY() {return y;}
    Team getTeam() {return team;}
    string getID() {return ID;}
private:
    bool staged;
    string filename;
    Team team;
    string ID;
    int strength;
    int x, y;
    TextRect *tex;
};

#endif