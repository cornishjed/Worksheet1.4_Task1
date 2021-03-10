#include "DungeonCrawl.h" // Use DungeonCrawl::output() to debug

int main()
{
	// find game parameters
	unsigned int traps = 0;

	while (traps == 0) {
		cout << "Enter number of traps (maximum 90): ";
		cin >> traps;
		if (cin.fail()) {
			cout << "Not a number" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (traps > 35) {
			cout << "Certain death awaits!" << endl;
			traps = 0;
		}
	}

	DungeonCrawl game1(traps);
	char input;
	bool game = false;

	while (game == false) {
		//game1.output();
		cout << endl << endl;
		cout << "Choose direction: ";
		cin >> input;
		game1.playerMovement(tolower(input));
		game = game1.getGameState();
		if (game == true) { // if end-game condition met
			break;
		}
	}
}