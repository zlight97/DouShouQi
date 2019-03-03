#include "Game.h"
#include <iostream>
using namespace std;
Game::Game()
{
	newGame();
	staged = false;
    //this initilizes the Pieces array with their given data
}

Game::~Game(){
	for(int i = 0; i<9;i++) 
		for(int j =0; j<7;j++) 
			if(pieces[j][i]!=NULL) 
				delete pieces[j][i];

	for(int i = 0; i<9;i++) 
		for(int j =0; j<7;j++) 
			if(mapTiles[j][i]!=NULL) 
				delete mapTiles[j][i];
}	


void Game::draw()
{
	drawBackground();
	
    for(int i = 0; i<col;i++)
	{
		for(int j = 0; j<row;j++)
		{
			// float xFac = 2./col;
			// float yFac = 1./row;
			// MapTiles.push_back(new Map((i*xFac)-1,j*yFac,xFac,yFac, (j/3)+1));
			if(pieces.size()>=7&&pieces[j][i]!=NULL && pieces[j][i]->getID()!="empty")
				pieces[j][i]->draw();
				
				
			if (mapTiles.size() >= 7 && mapTiles[j][i] != NULL)
				mapTiles[j][i]->draw();
		}

	}
	// for(int i = 0; i<col;i++){
	// 	for(int j = 0; j<row;j++){
	// 	}
	// }
}

validDir Game::checkValid(Piece *p)
{
	validDir ret;
	ret.up = 0;
	ret.down = 0;
	ret.left = 0;
	ret.right = 0;
	Team t = p->getTeam();
	int cX = p->getX();
	int cY = p->getY();
	if(p->getStrength()==1)
	{
		if(cX>0)
			if((pieces[cY][cX-1]->getID()=="empty"||pieces[cY][cX-1]->getStrength()==1||pieces[cY][cX-1]->getStrength()==8)&&pieces[cY][cX-1]->getTeam()!=t)
				ret.left = 1;
		if(cX<8)
			if((pieces[cY][cX+1]->getID()=="empty"||pieces[cY][cX+1]->getStrength()==1||pieces[cY][cX+1]->getStrength()==8)&&pieces[cY][cX+1]->getTeam()!=t)
				ret.right = 1;
		if(cY>0)
			if((pieces[cY-1][cX]->getID()=="empty"||pieces[cY-1][cX]->getStrength()==1||pieces[cY-1][cX]->getStrength()==8)&&pieces[cY-1][cX]->getTeam()!=t)
				ret.up = 1;
		if(cY<6)
			if((pieces[cY+1][cX]->getID()=="empty"||pieces[cY+1][cX]->getStrength()==1||pieces[cY+1][cX]->getStrength()==8)&&pieces[cY+1][cX]->getTeam()!=t)
				ret.down = 1;
	}
	// else if(p->getStrength()==6||p->getStrength()==7)
	// {

	// }
	else
	{
		if(cX>0)
			if((pieces[cY][cX-1]->getID()=="empty"||pieces[cY][cX-1]->getStrength()>=p->getStrength())&&mapTiles[cY][cX-1]->getType()!=WATER&&pieces[cY][cX-1]->getTeam()!=t)
				ret.left = 1;
		if(cX<8)
			if((pieces[cY][cX+1]->getID()=="empty"||pieces[cY][cX+1]->getStrength()>=p->getStrength())&&mapTiles[cY][cX+1]->getType()!=WATER&&pieces[cY][cX+1]->getTeam()!=t)
				ret.right = 1;
		if(cY>0)
			if((pieces[cY-1][cX]->getID()=="empty"||pieces[cY-1][cX]->getStrength()>=p->getStrength())&&mapTiles[cY-1][cX]->getType()!=WATER&&pieces[cY-1][cX]->getTeam()!=t)
				ret.up = 1;
		if(cY<6)
			if((pieces[cY+1][cX]->getID()=="empty"||pieces[cY+1][cX]->getStrength()>=p->getStrength())&&mapTiles[cY+1][cX]->getType()!=WATER&&pieces[cY+1][cX]->getTeam()!=t)
				ret.down = 1;
	}

	cout<<ret.up<<" "<<ret.down<<" "<<ret.left<<" "<<ret.right<<endl;
	return ret;
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

		// cout<<"(Matt"<<xCh<<", "<<yCh<<")\n";
		validDir valid = checkValid(stagedPiece);
		stagedPiece->stage(valid);

	}else if(staged)
	{
		int curX = stagedPiece->getX();
		int curY = stagedPiece->getY();
		
		if ((((curX-xCh)==1)&&(curY==yCh))||(((curX-xCh)==-1)&&(curY==yCh))
		   ||(((curY-yCh)==1)&&(curX==xCh))||(((curY-yCh)==-1)&&(curX==xCh))){
			pieces[curY][curX] = pieces[yCh][xCh];
			pieces[yCh][xCh] = stagedPiece;
			pieces[curY][curX]->move(curX,curY);
			stagedPiece->move(xCh,yCh);

			staged = false;
			stagedPiece->stage();
			stagedPiece=NULL;
		}
		/*
		pieces[curY][curX] = pieces[yCh][xCh];
		pieces[yCh][xCh] = stagedPiece;
		pieces[curY][curX]->move(curX,curY);
		stagedPiece->move(xCh,yCh);

		staged = false;
		stagedPiece->stage();
		stagedPiece=NULL;
		*/
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

	for(int i = 0; i<7; i++) {
		mapTiles.push_back(vector<Tile*>());
		for(int j = 0; j<9;j++) {
			 mapTiles[i].push_back(new Tile());
		}
	}
	// // Top river
	mapTiles[1][3] -> updateTile(WATER, 3,1);
	mapTiles[1][4] -> updateTile(WATER, 4,1);
	mapTiles[1][5] -> updateTile(WATER, 5,1);
	mapTiles[2][3] -> updateTile(WATER, 3,2);
	mapTiles[2][4] -> updateTile(WATER, 4,2);
	mapTiles[2][5] -> updateTile(WATER, 5,2);
	
	//Bottom River
	mapTiles[4][3] -> updateTile(WATER, 3,4);
    mapTiles[4][4] -> updateTile(WATER, 4,4);
	mapTiles[4][5] -> updateTile(WATER, 5,4);
	mapTiles[5][3] -> updateTile(WATER, 3,5);
    mapTiles[5][4] -> updateTile(WATER, 4,5);
    mapTiles[5][5] -> updateTile(WATER, 5,5);

	//  Left Traps
	mapTiles[2][0] -> updateTile(TRAP,0,2);
	mapTiles[4][0] -> updateTile(TRAP,0,4);
	mapTiles[3][1] -> updateTile(TRAP,1,3);
       
	// Right Traps
	mapTiles[2][8] -> updateTile(TRAP,8,2);
	mapTiles[4][8] -> updateTile(TRAP,8,4);
	mapTiles[3][7] -> updateTile(TRAP,7,3);
        
	//Left Den
    mapTiles[3][0] -> updateTile(DEN,0,3);

    //Right Den
	mapTiles[3][3] -> updateTile(DEN,8,3);
}