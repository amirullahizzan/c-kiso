#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "2 �l����͂��Ă����� > " << flush;
	cin >> a >> b;

	//if (a > b)
	//{
	//	cout << "�傫���ق��̒l�� " << a << " �ł��B" << endl;
	//}
	//else
	//{
	//	cout << "�傫���ق��̒l�� " << b << " �ł��B" << endl;
	//}


	cout << "�傫���ق��̒l�� " << (a > b ? a : b) << " �ł��B" << endl;


}
