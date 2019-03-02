//Mapp.cpp
#include "Map.h"

Map::Map(float x, float y, float w, float h) {
    this -> x =  x;
    this -> y =  y;
    this -> w =  w;
    this -> h = h;
    grassTex = new TextRect("Grass.png",x,y,w,h);
}

Map::Map(float x, float y, float w, float h, bool traversable) {
    this -> x =  x;
    this -> y =  y;
    this -> w =  w;
    this -> h = h;
    this -> trav = traversable;
    waterTex = new TextRect("Water.png",x,y,w,h,traversable);
}
Map::~Map() {
    // delete Map;
    // delete text;
}