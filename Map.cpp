//Mapp.cpp
#include "Map.h"

Map::Map(float x, float y, float w, float h, int tileType) {
    this -> x =  x;
    this -> y =  y;
    this -> w =  w;
    this -> h = h;
    this -> tileType = tileType;
}

Map::~Map() {
    delete grassTex;
    delete waterTex;
    delete trapTex;
    delete denTex;
}

void Map::draw() {
    // grassTex -> draw();
    // waterTex -> draw();
    waterTex -> draw();
}

void Map::loadText() {
    double xFac = 2./9.;
    double yFac = 2./7.;
    if (grassTex == NULL || waterTex == NULL || trapTex == NULL || denTex == NULL){ 
        return;
    }
    delete grassTex;
    delete waterTex;
    delete trapTex;
    delete denTex;

    switch(tileType) {
        case 0: //grass
            grassTex = new TextRect("Textures/grass.png",x ,y ,w ,h);
            break;
        case 1: //water
            waterTex = new TextRect("Textures/river.png",x ,y ,w ,h);
            break;
        case 2: //trap 
            trapTex = new TextRect("Textures/trap.jpg",x ,y ,w , h);
            break;
        case 3: //den
            denTex = new TextRect("Texture/den.jpg", x, y, w, h);
            break;
    }
}