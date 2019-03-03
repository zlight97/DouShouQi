#include "Tile.h"
#include "Definitions.h"
#include <iostream>
using namespace std;

Tile::Tile() {}

Tile::Tile(tileType t, int x, int y) {
    
    this -> x = x;
    this -> y  = y;
    type = t;
    switch(type)
    {
        case WATER:
        filename = "river.png";
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
     double  xFac = 2./10; 
     double yFac = 2./8;
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
}

void Tile::updateTile(tileType type,int x,int y) {
    this -> x = x;
    this -> y = y;
    this -> type = type;
    switch(type)
    {
        case WATER:
            filename = "river.png";
        break;
        case TRAP:
            filename = "trap.png";
        break;
        case DEN:
            filename = "den.png";
        break;
    double xFac = 2./9.;
    double yFac = 2./7.;
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
    }
}
Tile::~Tile() {delete tex;}
void Tile::draw(){tex->draw();}
tileType Tile::getType() {return type;}
