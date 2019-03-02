//Map class
#ifndef MAP_H
#define MAP_H
#include <stddef.h>
#include "TextRect.h"


class Map {
    float x,y,w,h;
    bool trav = true;
    int tileType;
    TextRect *grassTex;
    TextRect *waterTex;
    TextRect *trapTex;
    TextRect *denTex;
    
    public:
    Map(float x,float y,float w,float h,int type);
    Map(float x,float y,float w,float h, bool specialTile); // Maybe we need to use speialTile for water/trap/den
    ~Map();
    void draw();
    void loadText();
    void setTileType(int newTile){tileType = newTile;}
    int getTileType(){return tileType;}
    
};


#endif