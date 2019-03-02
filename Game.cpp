#include "Game.h"

Game::Game()
{
	newGame();
	staged = false;
    //this initilizes the Pieces array with their given data
}

Game::~Game()
{
	for(int i = 0; i<9;i++)
		for(int j =0; j<7;j++)
			if(pieces[j][i]!=NULL)
				delete pieces[j][i];
}

void Game::draw()
{

	drawBackground();
	
    // Need to work out the math to display the tiles
    // Need tp push back Map tiles
    for(int i = 0; i<col;i++)
	{
		for(int j = 0; j<row;j++)
		{
			// float xFac = 2./col;
			// float yFac = 1./row;
			// MapTiles.push_back(new Map((i*xFac)-1,j*yFac,xFac,yFac, (j/3)+1));
			if(pieces.size()>=7&&pieces[j][i]!=NULL && pieces[j][i]->getID()!="empty")
				pieces[j][i]->draw();
		}
	}

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
	if(!staged&&pieces[yCh][xCh]->getTeam()==currentTurn)
	{
		staged = true;
		stagedPiece = pieces[yCh][xCh];
	}else if(staged)
	{
		int curX = stagedPiece->getX();
		int curY = stagedPiece->getY();
		Piece *p = pieces[yCh][xCh];
		pieces[curY][curX] = pieces[yCh][xCh];
		pieces[yCh][xCh] = stagedPiece;
		pieces[curY][curX]->move(curX,curY);
		stagedPiece->move(xCh,yCh);

		staged = false;
		stagedPiece=NULL;
		
		if(currentTurn==BLACK)
			currentTurn=RED;
		else
			currentTurn=BLACK;

	}

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

void Game::newGame()
{
	for(int i = 0; i<7; i++)
	{
		pieces.push_back(vector<Piece*>());
		for(int j = 0; j<9;j++)
			 pieces[i].push_back(new Piece());

	}
	pieces[6][2]->updatePiece(2,6,1,RED);
	pieces[1][1]->updatePiece(1,1,2,RED);
	pieces[2][2]->updatePiece(2,2,3,RED);
	pieces[5][1]->updatePiece(1,5,4,RED);
	pieces[4][2]->updatePiece(2,4,5,RED);
	pieces[0][0]->updatePiece(0,0,6,RED);
	pieces[6][0]->updatePiece(0,6,7,RED);
	pieces[0][2]->updatePiece(2,0,8,RED);

	pieces[6-6][8-2]->updatePiece(8-2,6-6,1,BLACK);
	pieces[6-1][8-1]->updatePiece(8-1,6-1,2,BLACK);
	pieces[6-2][8-2]->updatePiece(8-2,6-2,3,BLACK);
	pieces[6-5][8-1]->updatePiece(8-1,6-5,4,BLACK);
	pieces[6-4][8-2]->updatePiece(8-2,6-4,5,BLACK);
	pieces[6-0][8-0]->updatePiece(8-0,6-0,6,BLACK);
	pieces[6-6][8-0]->updatePiece(8-0,6-6,7,BLACK);
	pieces[6-0][8-2]->updatePiece(8-2,6-0,8,BLACK);
}