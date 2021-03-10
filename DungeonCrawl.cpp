#include "DungeonCrawl.h"
#include <ctime>
#include <cstdlib>

DungeonCrawl::DungeonCrawl(int t)
{
	traps = t;
	vectorX = 20;
	vectorY = 6;
	initialise();
	gameState = false;
}

void DungeonCrawl::initialise()
{
	srand(time(0));

	vector<char> v1;

	// set up vectors
	for (int i = 0; i < vectorY; ++i) {
		while (v1.size() != vectorX) {
				v1.push_back(' ');
		}
		grid.push_back(v1);
		v1.clear();
	}

	// set traps
	int setTrapX;
	int setTrapY;

	while (traps != 0) {
		setTrapX = rand() % vectorX;
		setTrapY = rand() % vectorY;
		if (grid[setTrapY][setTrapX] != 'T') {
			grid[setTrapY][setTrapX] = 'T';
			traps--;
		}
	}

	// plant treasure
	int treasureX;
	int treasureY;
	bool placed = false;

	while (placed == false) {
		treasureX = rand() % vectorX;
		treasureY = rand() % vectorY;
		if (grid[treasureY][treasureX] == ' ') {
			grid[treasureY][treasureX] = 'X';
			placed = true;
		}
	}

	// position player
	placed = false;
	while (placed == false) {
		playerX = rand() % vectorX;
		playerY = rand() % vectorY;
		if (grid[playerY][playerX] == ' ') {
			grid[playerY][playerX] = '@';
			placed = true;
		}
	}

	// populate blank space
	for (int y = 0; y < vectorY; ++y) {
		for (int x = 0; x < vectorX; x++) {
			if (grid[y][x] == ' ') {
				grid[y][x] = '.';
			}
		}
	}
}

void DungeonCrawl::output()
{
	for (int i = 0; i < vectorY; ++i) {
		for (int j = 0; j < vectorX; ++j) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

void DungeonCrawl::playerMovement(char direction)
{
	if (direction == 'w') {
		cout << "going up..." << endl;
		playerY--;
		grid[playerY + 1][playerX] = '.'; // simulate player movement
		collisionDetection();
		grid[playerY][playerX] = '@'; // by changing '.' and '@' characters 
	}
	else if (direction == 's') {
		cout << "going down..." << endl;
		playerY++;
		grid[playerY - 1][playerX] = '.';
		collisionDetection();
		grid[playerY][playerX] = '@';
	}
	else if (direction == 'a') {
		cout << "going left..." << endl;
		playerX--;
		grid[playerY][playerX + 1] = '.';
		collisionDetection();
		grid[playerY][playerX] = '@';
	}
	else if (direction == 'd') {
		cout << "going right..." << endl;
		playerX++;
		grid[playerY][playerX - 1] = '.';
		collisionDetection();
		grid[playerY][playerX] = '@';
	}
	else
		cout << "Invalid input.." << endl;
}

void DungeonCrawl::collisionDetection()
{
	// if wall hit
	if (playerY < 0) {
		playerY = vectorY - 1; // reposition player onto the other side
	}
	else if (playerY > vectorY - 1) {
		playerY = 0;
	}

	if (playerX < 0) {
		playerX = vectorX - 1;
	}
	else if (playerX > vectorX - 1) {
		playerX = 0;
	}

	// end-game conditions
	if ((grid[playerY][playerX]) == 'T') {
		grid[playerY][playerX] = '@';
		output();
		cout << "TRAPPED!\nGame Over!!!" << endl;
		setGameState(true);
	}
	else if ((grid[playerY][playerX]) == 'X') {
		grid[playerY][playerX] = '@';
		output();
		cout << "TREASURE FOUND!\nCongratulations!!!" << endl;
		setGameState(true);
	}
}

void DungeonCrawl::setGameState(bool gs)
{
	gameState = gs;
}

bool DungeonCrawl::getGameState()
{
	return gameState;
}