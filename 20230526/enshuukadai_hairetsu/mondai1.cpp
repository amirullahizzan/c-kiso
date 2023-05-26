#include <iostream>

using namespace std;

int input[5];
int i = 0;
float sum = 0;
float heikin = 0;



int main()
{
	for (int j = 0;j<3 ;j++)
	{
		
		i = 0;
		sum = 0;
		heikin = 0;
	

	for (;i < 5; i++)
	{
		cout << "input " << i << "‚Â–Ú‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n";
		cin >> input[i];
		sum += input[i];
	}

	heikin = sum / i;
	
	cout << "‡Œv’l = " << sum << "\n•½‹Ï’l = " << heikin << endl << endl;

	//reset
	
	}
}