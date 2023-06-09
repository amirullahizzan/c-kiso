
#include <iostream>
using namespace std;


int input[3];

void InputDigit()
{
	for (int i = 0; i < 3;)
	{
	cout << "ˆêŒ…‚Ì”Žš‚ð3‰ñ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > " << flush;
	cin >> input[i];
	cout << endl;
	if (input[i] > 9)
	{
		continue;
	}
	i++;
	}
}

void DisplayDigits()
{
	cout << "‚ ‚È‚½‚Ì”Žš :" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << "‰ñ–Ú ‚Í " << input[i] << endl;
	}
}

int main()
{
	InputDigit();
	DisplayDigits();
}