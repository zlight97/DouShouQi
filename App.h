#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "keyboardHandler.h"

class App: public GlutApp {
    // Maintain app state here

public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    ~App();
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    void mouseMove(float x, float y);
    void idle();
};

#endif
