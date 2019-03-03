//Map class
#ifndef MAP_H
#define MAP_H
#include <stddef.h>
#include <vector>
#include "TextRect.h"
#include "Tile.h"

class Map {
    private:
        int x,y;
        float w,h;
        int tileType;
        Tile *tilePieces;
        std::vector<std::vector<Tile*> > tiles;

    public:
        Map();
        ~Map();
        Map(int x,int y,int type);
        void draw();
        void setTileType(int newTile){tileType = newTile;}
        int getTileType(){return tileType;}
};
#endif