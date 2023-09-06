#include <iostream>

using namespace std;

struct Enemy
{
	int health = 0;
	int damage = 0;


};

char input[64];
int numinput;
Enemy* enemies[4];

void PrintEnemy()
{
	for (int i = 0; i < sizeof(enemies) / sizeof(enemies[0]); i++) 
	{
		std::cout << "Enemy " << i + 1 << " health: " << enemies[i]->health << std::endl;
		//std::cout << "Enemy " << i << " attack: " << enemies[i]->damage << std::endl;
	}
}
int maxenemies = 0;

void PlayerTurnIO()
{
	PrintEnemy();
	cout << "command : attack | exitgame" << endl;
	cin >> input;
	if (strcmp(input, "attack") == 0)
	{
		cout << "enemy number : " << endl;
		cin >> numinput;
		if (numinput > 0 && numinput < maxenemies)
		{
			enemies[numinput-1]->health -= 20;
		}
		else
		{
			cout << "Not a correct enemy number, input was : "<< numinput << endl; return;
		} 
	}
	if (strcmp(input, "exitgame") == 0)
	{
		std::cout << "Exiting realm" << std::endl;
		exit(0);
	}
}

bool inBattle = true;

int main()
{
	maxenemies = sizeof(enemies) / sizeof(enemies[0]);
	for (int i = 0; i < sizeof(enemies) / sizeof(enemies[0]); i++)
	{
		enemies[i] = new Enemy();
		enemies[i]->health = 100;
		enemies[i]->damage = 20;
	}

	// Allocate memory for the Enemy struct.
	while (inBattle)
	{
		

		PlayerTurnIO();
		
	}
	

	// Print the health and attack of the Enemy struct.
		

	


	// Delete the Enemy struct.
	for (int i = 0; i < 5; i++)
	{
		delete enemies[i];
	}

	system("pause");
	return 0;
}