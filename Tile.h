#ifndef TILE_H
#define TILE_H
#include "Definitions.h"
#include "TextRect.h"
#include <string>
#include <vector>

class Tile{
    private:
        int x,y;
        double  xFac = 2./10;
        double yFac = 2./8;
        tileType type;
        TextRect *tex;
        std::vector<std::vector<Tile*> > tiles;
        std::string filename;
    public:
        Tile();
        Tile(tileType t, int x, int y, double xFac, double yFac);
        ~Tile();
        tileType getType();
        void draw();
};
#endif