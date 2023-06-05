#include <iostream>
using namespace std;

int input[5];

int main()
{
	int i = 0;
	
	for (;i<5;i++)
	{
		cout << "”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > ";
		cin  >> input[i];

		cout << "“ü—Í‚³‚ê‚½”’l:    " << input[i]	 << endl
			 << "‚»‚ê‚ğ2”{‚µ‚½”’l: " << input[i] * 2 << endl
			 << "---------------------------------"  << endl;
	}
	
	system("pause");
	return 0;
}