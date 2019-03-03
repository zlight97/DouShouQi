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
    void move(int x, int y);
    void draw();
    void clicked(float x, float y);
    void updatePiece(int x, int y, int strength,Team t);
    void stage(validDir d);
    void stage();
    void drawStaged();
    int getX() {return x;}
    int getY() {return y;}
    Team getTeam() {return team;}
    string getID() {return ID;}
    int getStrength(){return strength;}
    void changeStrength(int strength) {this->strength;}
    
private:
    validDir stagedDir;
    bool staged;
    string filename;
    Team team;
    string ID;
    int strength;
    int x, y;
    TextRect *tex;
    validDir valid;
};

#endif