#include "Game.h"

Game::Game()
{
    //this initilizes the Pieces array with their given data
}

void Game::draw()
{

	drawBackground();
    // Need to work out the math to display the tiles
    // Need tp push back Map tiles
    // for(int i = 0; i<col;i++)
	// {
	// 	for(int j = 0; j<row;j++)
	// 	{
	// 		float xFac = 2./col;
	// 		float yFac = 1./row;
	// 		// MapTiles.push_back(new Map((i*xFac)-1,j*yFac,xFac,yFac, (j/3)+1));
	// 	}
	// }

}
void Game::click(float x, float y)
{
    double xFac = 2./10.;
    double yFac = 2./8.;
	int yCh = doubleToIntY(y);
	int xCh = doubleToIntX(x);
	cout<<"[ "<<x<<", "<<y<<" ]\n";
	cout<<"("<<xCh<<", "<<yCh<<")\n";
	cout<<"("<<intToDoubleX(xCh)<<", "<<intToDoubleY(yCh)<<")\n";
}

void Game::drawBackground()
{
    glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for(float i = -1; i<1;i=i+(2./9.))
	{
		glVertex2f(i,1.);
		glVertex2f(i,-1.);
	}
		for(float i = -1; i<1;i=i+(2./7.))
	{
		glVertex2f(1,i);
		glVertex2f(-1,i);
	}
	glEnd();
}