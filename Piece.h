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
    string getID() {return ID;}
private:
    string filename;
    Team team;
    string ID;
    int strength;
    int x, y;
    TextRect *tex;
};

#endif