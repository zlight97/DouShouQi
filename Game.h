#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "GlutApp.h"
#include "Definitions.h"
#include "Piece.h"
#include "Map.h"

using namespace std;

class Game
{
public:
    Game();
	
    void draw();
    void click(float x, float y);

private:
    Piece pieces[7][9];
    Team currentTurn;
    int const col = 9;
	int const row = 6;
    vector<Map*> MapTiles;
};

#endif