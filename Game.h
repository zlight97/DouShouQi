#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "GlutApp.h"
#include "Piece.h"
// #include "Map.h"
#include "Tile.h"

using namespace std;

class Game
{
public:
    Game();
    ~Game();
    void start();
    void draw();
    void click(float x, float y);
    void newGame();

private:
    void drawBackground();
    validDir checkValid(Piece *p);
    Piece *stagedPiece;
    vector <vector<Piece*> > pieces;
    vector <vector<Tile*> > mapTiles;
    Team currentTurn;
    bool staged;
    validDir valid;
};

#endif