#include <iostream>
using namespace std;

int input;
int amari = 0;
int i = 0;
int j = 0;
int k = 0;
int star1 = 0;

int main()
{
	
		cout << "”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > ";
		cin >> input;
		amari = input % 5;
		for (; j < input; j++)
		{
			cout << "™";
			if (input%5 > 0 && j>5)
			{
				cout << endl;
				amari = input % 5;
				j -= amari;
			}
			
		}
		cout << endl;

}