#include <iostream>

using namespace std;

int main()
{
	
	for (int i =0;i <5; ++i)
	{
		cout << "***********" << endl ;
		
	}
	

	for(int i = 0; i <5;i++)
	{
		for (int j = 0; j < 5; ++j)
		{
		cout << "*";
		}
	cout << endl;
	}
	
	cout << endl << endl;

	for (int i = 0;i<6;i++)
	{
		cout << "+";
		cout << "-";
	}
	cout << endl <<endl;

	for (int j = 0; j < 5; j++)
	{
		cout << "-";
		
	}
	for (int i = 0; i < 6; i++)
	{
		cout << "+";

	}

	cout << endl;

	for (int i = 0; i < 11; i++)
	{
		if (i < 5)
		{
			cout << "-";
		}
		else
		{
			cout << "+";
		}
	}

	cout << endl<<endl;

	for (int j = 0; j < 3; j++)
	{

		for (int i = 0; i < 3; i++)
		{
			cout << "*";
		}
		cout << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << 0;
		}
		cout << endl;

	}
}