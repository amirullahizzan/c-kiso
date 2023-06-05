#include <iostream>
using namespace std;

int input[5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > ";
		cin >> input[i];

		cout << "“ü—Í‚³‚ê‚½”’l:    " << input[i] << endl;
			if (input[i] % 2 != 0)
			{
				cout << input[i] << "‚ÍŠï”‚Å‚·" << endl;
			}
		cout << "---------------------------------" << endl;
	}
	
	system("pause");
	return 0;
}	