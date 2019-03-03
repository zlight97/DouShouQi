#include "Tile.h"
#include "Definitions.h"


Tile::Tile() {}

Tile::Tile(tileType t, int x, int y, double  xFac = 2./10, double yFac = 2./8) {
    this -> x = x;
    this -> y  = y;
    this -> xFac = xFac;
    this -> yFac = yFac;
    type = t;
    switch(type)
    {
        case WATER:
        filename = "Textures/river.png";
        break;
        case TRAP:
        filename = "trap.jpg";
        break;
        case DEN:
        filename = "den copy.jpg";
        break;
        default:
        filename = "none";
        break;
    }
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
}
Tile::~Tile() {
    delete tex;
}

void Tile::draw()
{
    tex->draw();
}

tileType Tile::getType() {
    return type;
}