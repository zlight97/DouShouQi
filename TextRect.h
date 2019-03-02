#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;

    TexRect (const char*, float, float, float, float);
 
    void draw();
    
    bool contains(float, float);
    
  
    void idle(float x, float y);
   
    

    
   
};

#endif
