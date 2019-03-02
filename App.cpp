#include "App.h"
#include "Game.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    g = new Game();
    p = new Piece(0,7, 6, BLACK);
}

App::~App()
{
    delete g;
    delete p;
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(100.0, 100.0, 100.0, 1.0);

    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    g->draw();
    p->draw();
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::idle()
{

    
}

void App::mouseDown(float x, float y){
    // g->click(x,y);
    p->clicked(x,y);
    redraw();
}

void App::mouseDrag(float x, float y){

}

void App::mouseMove(float x, float y)
{

}

void App::keyUp(unsigned char key)
{

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}


