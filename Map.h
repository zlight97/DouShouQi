//Map class
#ifndef MAP_H
#define MAP_H
#include "TextRect.h"

class Map {
    float x,y,w,h;
    bool trav = true;
    TextRect *grassTex;
    TextRect *waterTex;
    public:
    Map(float x,float y,float w,float h);
    Map(float x,float y,float w,float h, bool trav);
    ~Map();
};


#endif