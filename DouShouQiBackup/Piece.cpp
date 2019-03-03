#include "Piece.h"
using namespace std;

Piece::Piece()
{
    ID = "empty";
    strength = 0;
    team = NEITHER;
    staged = false;
}

Piece::Piece(int x, int y, int strength,Team t)//Team will decide where the piece is placed (x,y)
{
    staged = false;
    this->x = x;
    this->y = y;
    team = t;
    this->strength = strength;
    switch(strength)
    {
        case 0:
            ID = "empty";
            filename = "empty";
        break;
        case 1:
            ID = "rat";
            filename = "rat.png";
        break;
        case 2:
            ID = "cat";
            filename = "cat.png";
        break;
        case 3:
            ID = "wolf";
            filename = "wolf.png";
        break;
        case 4:
            ID = "dog";
            filename = "dog.png";
        break;
        case 5:
            ID = "leopard";
            filename = "leopard.png";
        break;
        case 6:
            ID = "tiger";
            filename = "tiger.png";
        break;
        case 7:
            ID = "lion";
            filename = "lion.png";
        break;
        case 8:
            ID = "elephant";
            filename= "elephant.png";
        break;
    }
    if(t==BLACK)
        filename = "Textures/B"+filename;
    if(t==RED)
        filename = "Textures/R"+filename;
    double xFac = 2./9.;
    double yFac = 2./7.;
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
    cout<<y<<" "<<intToDoubleX(x)<<" "<<intToDoubleY(y)<<endl;
    
}   
Piece::~Piece(){
    delete tex;
}

void Piece::move(int x, int y)
{
    this->x = x;
    this->y = y;
    // TextRect *old = tex;
    // tex = new TextRect(filename.c_str(), intToDoubleX(this->x),intToDoubleY(this->y),2./9.,2./7.);
    // if(old!=NULL)
    //     delete old;
    if(ID!="empty")
        tex->idle(intToDoubleX(x),intToDoubleY(y));
}

void Piece::stage()
{
    staged = false;
}

void Piece::stage(validDir d)
{
    staged = true;
    stagedDir = d;
}

void Piece::draw()
{
    tex->draw();
}

void Piece::drawStaged()
{
    if(staged)
    {
        //this uses the values in stagedDir to determine where to draw, assume given values are correct
    }
}

void Piece::clicked(float x, float y){
    this->x = doubleToIntX(x);
    this->y = doubleToIntY(y);
    cout<<this->x<<" "<<this->y<<endl;
    delete tex;
    tex = new TextRect(filename.c_str(), intToDoubleX(this->x),intToDoubleY(this->y),2./9.,2./7.);
    cout<<y<<" "<<intToDoubleX(this->x)<<" "<<intToDoubleY(this->y)<<endl;
}

void Piece::updatePiece(int x, int y, int strength,Team t)//Team will decide where the piece is placed (x,y)
{
    this->x = x;
    this->y = y;
    team = t;
    this->strength = strength;
    switch(strength)
    {
        case 0:
            ID = "empty";
            filename = "empty";
        break;
        case 1:
            ID = "rat";
            filename = "rat.png";
        break;
        case 2:
            ID = "cat";
            filename = "cat.png";
        break;
        case 3:
            ID = "wolf";
            filename = "wolf.png";
        break;
        case 4:
            ID = "dog";
            filename = "dog.png";
        break;
        case 5:
            ID = "leopard";
            filename = "leopard.png";
        break;
        case 6:
            ID = "tiger";
            filename = "tiger.png";
        break;
        case 7:
            ID = "lion";
            filename = "lion.png";
        break;
        case 8:
            ID = "elephant";
            filename= "elephant.png";
        break;
    }
    if(t==BLACK)
        filename = "Textures/B"+filename;
    if(t==RED)
        filename = "Textures/R"+filename;
    double xFac = 2./9.;
    double yFac = 2./7.;
    TextRect *old = tex;
    tex = new TextRect(filename.c_str(), intToDoubleX(x),intToDoubleY(y),xFac,yFac);
    if(old!=NULL)
        delete old;
}