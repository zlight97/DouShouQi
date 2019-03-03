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
    float x = getX();
    float y = getY();
    float xFac = 1./9.;
    float yFac = 1./7.;

    // Adacent center tile coordinates
    
    if(staged)
    {
        glColor3d(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        if (valid.up >= 1) {
            glVertex2f(intToDoubleX(x) - xFac/2., intToDoubleY(y-valid.up));
        }
        if (valid.down >= 1) {
            glVertex2f(intToDoubleX(x) + xFac/2., intToDoubleY(y+valid.up));
        }
        if (valid.right >= 1) {
            glVertex2f(intToDoubleX(x + valid.right), intToDoubleY(y)+yFac/2);
        }
        if (valid.left >= 1) {
            glVertex2f(intToDoubleX(x - valid.right), intToDoubleY(y)-yFac/2);
        }
        glEnd();
    }
        //this uses the values in stagedDir to determine where to draw, assume given values are correct
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