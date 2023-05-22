#include <iostream>

using namespace std;

int main()
{
	int number = 0;
	cin >> number;
	cout << endl;
	
	int numberdigit1 = 0;
	int numberdigit2 = 0;
	int numberdigit3 = 0;
	if (number > 99 && number < 1000)
	{
		
		numberdigit1 = (number % 100)%10;
		numberdigit2 = (number % 100) - numberdigit1;
		numberdigit3 = number - (number % 100);

		int numberdigit3b = numberdigit3 / 100;
		int numberdigit1b = numberdigit1 * 100;

		int reversenumber = numberdigit3b+numberdigit2+numberdigit1b;

		cout << "Your reverse number" << reversenumber << endl;
	}
	else
	{
		cout << "“ü—Í‚ÉŒë‚è‚ª‚ ‚è‚Ü‚·" << endl;
	}
}