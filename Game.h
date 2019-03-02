#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "GlutApp.h"
#include "Piece.h"
#include "Map.h"

using namespace std;

class Game
{
public:
    Game();
    void start();
    void draw();
    void click(float x, float y);

private:
    void drawBackground();
    Piece pieces[7][9];
    Team currentTurn;
    // vector<Map*> MapTiles;
    

};

#endif