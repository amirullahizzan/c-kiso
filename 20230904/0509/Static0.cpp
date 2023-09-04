#include <iostream>

using namespace std;

void Func1()
{
	int a = 0;
	cout << a << endl;
	a++;
}


void Func2()
{
	static int a;
	cout << a << endl;
	a++;
}

int main()
{
	const int LOOP_NUM = 5;

	cout << "-- Func1() --" << endl;
	for(int i = 0;i< LOOP_NUM;i++)
	{
		Func1();
	}
	
	cout << "-- Func2() --" << endl;
	for(int i = 0;i< LOOP_NUM;i++)
	{
		Func2();
	}

	system("pause");
	return 0;

}