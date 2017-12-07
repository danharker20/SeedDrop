#include "Background.h"
#include "Game.h"
#include <fstream>

Background::Background()
{
}

Background::~Background()
{
}

//load background
//puts tiles on screen
void Background::loadBG(std::string path, int sizeX, int sizeY)
{
	char tile;
	std::fstream mapFile;
	mapFile.open(path);

	//loop that reads file and puts tiles on accordingly 
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			Game::addTile(atoi(&tile), x * 64, y * 64);
			mapFile.ignore(); // ignore comma or newline char
		}
	}

	mapFile.close();
}
