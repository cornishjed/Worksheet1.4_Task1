#include <iostream>
#include <vector>
using namespace std;

class DungeonCrawl
{
public:
	DungeonCrawl(int);
	void initialise();
	void output();
	void collisionDetection();
	void playerMovement(char);
	void setGameState(bool);
	bool getGameState();

private:
	vector<vector<char>> grid;
	int traps;
	int vectorX;
	int vectorY;
	int playerX;
	int playerY;
	bool gameState;
};
