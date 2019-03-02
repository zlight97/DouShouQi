#include "keyboardHandler.h"
//Written by Zach Light
//Holds a map of keys that have been pressed but not released
//Used to determine if a key is being held, allowing for smooth hold movement

keyboardHandler::keyboardHandler()
{

}

void keyboardHandler::keyDown(unsigned char key)
{
	held.insert(std::make_pair(key,1));
}
void keyboardHandler::keyUp(unsigned char key)
{
	held.erase(key);
}
bool keyboardHandler::getHold(unsigned char key)
{
	if(held.find(key)==held.end())
		return 0;
	return 1;

}