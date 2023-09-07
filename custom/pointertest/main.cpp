#include <iostream>
#include <vector>

using namespace std;



class Enemy
{
public :
	Enemy(int health, int damage) : health_(health), damage_(damage) {}
	int health_ = 0;
	int damage_ = 0;

private :
	

};
const int MAXENEMY = 4+1;
char input[64];
int numinput;

std::vector<Enemy> enemies;

void PrintEnemy()
{
	for (size_t i = 1; i < enemies.size(); i++) 
	{
		std::cout << "Enemy " << i << " health: " << enemies[i].health_ << std::endl;
		std::cout << "Enemy " << i << " attack: " << enemies[i].damage_ << std::endl;
		std::cout << std::endl;
	}
}

void PlayerTurnIO()
{
	while (true)
	{
	PrintEnemy();
	cout << "command : attack | exitgame > " << flush;
	cin >> input;
	if (strcmp(input, "attack") == 0)
	{
		cout << "enemy number > " << flush;
		cin >> numinput;
		if (numinput > 0 && numinput < enemies.size())
		{
			enemies[numinput].health_ -= 20;
			PrintEnemy();
			break;
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

}

void EnemyTurnIO()
{
	int waittime = 0;
	while (waittime <= 180)
	{
	waittime++;
	switch (waittime) 
	{
	case 0 :
		std::cout << "Enemies turn";
		break;
	case 60 :
		std::cout << ".";
		break;
	case 120 :
		std::cout << ".";
		break;
	case 180 :
		std::cout << "." << endl;
		break;
	default:
		break;
	}
	}

}

bool inBattle = true;
int main()
{
	for (size_t i = 1; i <= MAXENEMY; i++)
	{
		enemies.push_back( Enemy(100,40) );
	}

	// Allocate memory for the Enemy struct.
	while (inBattle)
	{
		PlayerTurnIO();
		EnemyTurnIO();
	}
	

	// Print the health and attack of the Enemy struct.

	system("pause");
	return 0;
}