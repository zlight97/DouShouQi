//Mapp.cpp
#include "Map.h"
#include <iostream>
using namespace std;
Map::Map(int x, int y,int tileType) {
    this -> x =  x;
    this -> y =  y;
    this -> tileType = tileType;
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
