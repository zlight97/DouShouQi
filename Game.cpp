#include "Game.h"

Game::Game()
{
    //this initilizes the Pieces array with their given data
}

void Game::draw()
{
    // Need to work out the math to display the tiles
    // Need tp push back Map tiles
    for(int i = 0; i<col;i++)
	{
		for(int j = 0; j<row;j++)
		{
			float xFac = 2./col;
			float yFac = 1./row;
			// MapTiles.push_back(new Map((i*xFac)-1,j*yFac,xFac,yFac, (j/3)+1));
		}
	}
}
void Game::click(float x, float y)
{

}