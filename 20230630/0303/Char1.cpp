#include <iostream>

using namespace std;

void ShowCode(char ch)
{
	cout << "「" << ch << "」にふられた番号は "
		 << (int)(unsigned char)ch << "　です。　" << endl;
}

int main()
{
	ShowCode('0');
	ShowCode('A');
}