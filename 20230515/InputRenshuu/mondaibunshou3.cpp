#include <iostream>

using namespace std;

int main()
{
	int jikan;
	cin >> jikan;
	int newjikan = jikan % 12;
	int newjikan2 = jikan % 24;
	if (jikan < 1 && jikan!=0)
	{
		cout << "Œë‚è‚ª‚ ‚è‚Ü‚·"<<endl;
	}
	else if (jikan == 0)
	{
		cout << newjikan;
		cout << " AM ";
	}
	else
	{
		cout << newjikan;
		if (newjikan2 < 12)
		{
			cout << " AM ";
		}
		else if (newjikan == 12)
		{
			cout << " PM ";
		}
		else
		{
			cout << " PM ";
		}
	}
	
}