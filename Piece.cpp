#include "Piece.h"
using namespace std;

Piece::Piece()
{
    ID = "empty";
    strength = 0;
    team = NEITHER;
}

Piece::Piece(int x, int y, int strength,Team t)//Team will decide where the piece is placed (x,y)
{
    this->x = x;
    this->y = y;
    team = t;
    string filename;
    this->strength = strength;
    switch(strength)
    {
        case 0:
            ID = "empty";
            filename = "empty";
        break;
        case 1:
            ID = "rat";
            filename = "textures/rat.png";
        break;
        case 2:
            ID = "cat";
            filename = "textures/cat.png";
        break;
        case 3:
            ID = "wolf";
            filename = "textures/wolf.png";
        break;
        case 4:
            ID = "dog";
            filename = "textures/dog.png";
        break;
        case 5:
            ID = "leopard";
            filename = "textures/leopard.png";
        break;
        case 6:
            ID = "tiger";
            filename = "textures/tiger.png";
        break;
        case 7:
            ID = "lion";
            filename = "textures/lion.png";
        break;
        case 8:
            ID = "elephant";
            filename= "textures/elephant.png";
        break;
    }
    double xFac = 2./10.;
    double yFac = 2./8.;
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
    cout<<"!!!: "<<intToDoubleX(x)<<intToDoubleY(y)<<endl;
    
}   
Piece::~Piece(){
    delete tex;
}

bool Piece::move(int x, int y){}
void Piece::draw()
{
    tex->draw();
}

void Piece::clicked(float x, float y){}