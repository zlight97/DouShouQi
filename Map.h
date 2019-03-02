//Map class
#ifndef MAP_H
#define MAP_H
#include <stddef.h>
#include <vector>
#include "TextRect.h"
#include "Tile.h"

class Map {
    int x,y;
    float w,h;
    int tileType;

    // TextRect *grassTex;
    // vector<denTex> denTiles;
    // vector<trapTex> trapTiles;
    
    public:
    std::vector<std::vector<Tile*> > tiles;
    Map();
    Map(int x,int y,float w,float h,int type);
    Map(int x,int y,float w,float h, bool specialTile); // Maybe we need to use speialTile for water/trap/den
    ~Map();
    void draw();
    void loadText();
    void setTileType(int newTile){tileType = newTile;}
    int getTileType(){return tileType;}
    
};


#endif