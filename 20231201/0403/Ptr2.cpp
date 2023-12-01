#include <iostream>
using namespace std;

int main()
{
	int a;
	int* p = &a;
	
	a = 0;
	cout << " a = " << a << endl;
	cout << " *p = " << *p << endl; //dereference it once and show the value

	*p = 5;

	cout << " a = " << a << endl;
	cout << " *p = " << *p << endl;


	int b = -1;
	p = &b;

	cout << " a = " << a << endl;
	cout << " *p = " << *p << endl;

	system("pause");
	return 0;
}