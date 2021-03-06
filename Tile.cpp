#include "Tile.h"
#include "Definitions.h"
#include <iostream>
using namespace std;

Tile::Tile() {type = NONE;}

Tile::Tile(tileType t, int x, int y) {
    
    this -> x = x;
    this -> y  = y;
    type = t;
    switch(type)
    {
        case WATER:
        filename = "Textures/river.png";
        break;
        case TRAP:
        filename = "Textures/trap.png";
        break;
        case DEN:
        filename = "Textures/den.png";
        break;
        default:
        filename = "none";
        break;
    }
    double  xFac = 2./9; 
    double yFac = 2./7;
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
}

void Tile::updateTile(tileType type,int x,int y) {
    this -> x = x;
    this -> y = y;
    this -> type = type;
    switch(type)
    {
        case WATER:
            filename = "Textures/river.png";
        break;
        case TRAP:
            filename = "Textures/trap.png";
        break;
        case DEN:
            filename = "Textures/den.png";
        break;
    }
    double xFac = 2./9.;
    double yFac = 2./7.;
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
    
}
Tile::~Tile() {delete tex;}

void Tile::draw(){
    if(type==NONE||tex==NULL)
        return;
    tex->draw();
    }
    
tileType Tile::getType() {return type;}
