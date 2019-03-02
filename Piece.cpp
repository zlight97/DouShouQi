#include "Piece.h"
#include "Definitions.h"
using namespace std;

Piece::Piece(int strength/*,Team t*/)//Team will decide where the piece is placed (x,y)
{
    this->strength = strength;
    switch(strength)
    {
        case 1:
            ID = "rat";
        break;
        case 2:
            ID = "cat";
        break;
        case 3:
            ID = "wolf";
        break;
        case 4:
            ID = "dog";
        break;
        case 5:
            ID = "leopard";
        break;
        case 6:
            ID = "tiger";
        break;
        case 7:
            ID = "lion";
        break;
        case 8:
            ID = "elephant";
        break;
    }
}
Piece::~Piece(){}
bool Piece::move(int x, int y){}
void Piece::draw(){}
void Piece::clicked(int x, int y){}