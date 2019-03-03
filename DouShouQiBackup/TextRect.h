#ifndef TextRect_h
#define TextRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
// #include "Map.h"
#endif

class TextRect {
public:
    float x;
    float y;
    float w;
    float h;
    bool trav;
    GLuint texture_id;

    TextRect (const char*, float, float, float, float);
    TextRect (const char*, float, float, float, float, bool);
    void move(float x, float y) {this->x=x;this->y=y;}
 
    void draw();
    
    bool contains(float, float);
    
  
    void idle(float x, float y);
   
    

    
   
};

#endif
