#include <iostream>
using namespace std;



int main()
{
	cout << "----------------------------------" << endl
		<< "�� �K���ϐ����g�p���Ă������� ��" << endl
		<< "----------------------------------" << endl;

		int a = 14;
		int b = 73;
		int add = a + b;
		int sub = a - b;
		int mlt = a * b;
		int div = b / a;
		int mod = b % a;

		cout << a << " + " << b << " = " << add;
		cout << endl;
		cout << a << " - " << b << " = " << sub;
		cout << endl;

		cout << a << " * " << b << " = " << mlt;
		cout << endl;

		cout << b << " / " << a << " = " << div << " ...���܂� " << mod;
		cout << endl;

	system("pause");
	return 0;
}