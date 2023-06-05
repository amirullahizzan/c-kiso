#include <iostream>
using namespace std;

int value[10] = { 51, 62, 94, 71, 10, 86, 46, 33, 7, 1};

int main()
{
	int i = 0;
	int sum = 0;
	for (;i<10;i++)
	{
		cout << i << ": " << value[i] << endl;
		sum += value[i];
	}
	cout << "----------------------" << endl;
	cout << "‡Œv :" << sum << endl;
	system("pause");
	return 0;
}