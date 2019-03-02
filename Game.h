#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "GlutApp.h"
#include "Definitions.h"
#include "Piece.h"

using namespace std;

class Game
{
public:
    Game();

    void draw();

private:
    Piece pieces[7][9];
    Team currentTurn;
};

#endif