//Map class
#ifndef MAP_H
#define MAP_H

class Map {
    float x,y,w,h;
    bool occupied = false;
    // TexRect *grassTex;
    // TexRect *waterTex;
    public:
    Map(float x,float y,float w,float h);
    ~Map();
};


#endif