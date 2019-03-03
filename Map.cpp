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
        // Top river
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
        //Bottom River
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
        //Left Traps
        delete tiles[0][3];
        tiles[0][3] = new Tile(TRAP,3,0,0,0);
        delete tiles[0][5];
        tiles[0][5] = new Tile(TRAP,5,0,0,0);
        delete tiles[1][4];
        tiles[1][4] = new Tile(TRAP,4,1,0,0);
        //Right Traps
        delete tiles[8][3];
        tiles[8][3] = new Tile(TRAP,3,8,0,0);
        delete tiles[8][5];
        tiles[8][5] = new Tile(TRAP,5,8,0,0);
        delete tiles[7][4];
        tiles[7][4] = new Tile(TRAP,7,4,0,0);
        //Left Den
        delete tiles[0][4];
        tiles[0][4] = new Tile(DEN,4,0,0,0);
        //Right Den
        delete tiles[8][4];
        tiles[8][4] = new Tile(DEN,4,8,0,0);
}

Map::~Map() {
      // delete waterTex;
    for(int i = 0; i<tiles.size();i++) {
         for(int j = 0; j<tiles[i].size();j++) {
            delete tiles[i][j];
         }
    }
}

void Map::draw() { 
    for(int i = 0; i<col;i++){
		for(int j = 0; j<row;j++) {
			if(tiles[j][i]!=NULL) {
                tiles[j][i]->draw();
            }
		}
	}
}
