//Mapp.cpp
#include "Map.h"


Map::Map(int x, int y, float w, float h, int tileType) {
    this -> x =  x;
    this -> y =  y;
    this -> w =  w;
    this -> h = h;
    this -> tileType = tileType;

    for(int i = 0; i<7; i++) {
		tiles.push_back(std::vector<Tile*>());
		for(int j = 0; j<9;j++) {
             tiles[i].push_back(new Tile());
        }
    }
    delete tiles[1][3];
        tiles[1][3] = new Tile(WATER, 3,1,0,0);
        delete tiles[1][4];
        tiles[1][4] = new Tile(WATER, 4,1,0,0);
        delete tiles[1][5];
        tiles[1][5] = new Tile(WATER, 5,1,0,0);
        delete tiles[2][3];
        tiles[2][3] = new Tile(WATER, 3,2,0,0);
        delete tiles[2][4];
        tiles[2][4] = new Tile(WATER, 4,2,0,0);
        delete tiles[2][5];
        tiles[2][5] = new Tile(WATER, 5,2,0,0);

        delete tiles[4][3];
        tiles[4][3] = new Tile(WATER, 3,4,0,0);
        delete tiles[4][4];
        tiles[4][4] = new Tile(WATER, 4,4,0,0);
        delete tiles[4][5];
        tiles[4][5] = new Tile(WATER, 5,4,0,0);
        delete tiles[2][3];
        tiles[5][3] = new Tile(WATER, 3,5,0,0);
        delete tiles[2][4];
        tiles[5][4] = new Tile(WATER, 4,5,0,0);
        delete tiles[2][5];
        tiles[5][5] = new Tile(WATER, 5,5,0,0);
}

Map::~Map() {
      // delete waterTex;
    for(int i = 0; i<tiles.size();i++) {
         for(int j = 0; j<tiles[i].size();j++) {
            delete tiles[i][j];
         }
    }
  
    // delete trapTex;
    // delete denTex;
}

void Map::draw() {
   for(int i = 0; i<7; i++)
	{
		tiles.push_back(std::vector<Tile*>());
    }
}
//    trapTex -> draw();
//    denTex -> draw();


void Map::loadText() {
    double xFac = 2./9.;
    double yFac = 2./7.;


}