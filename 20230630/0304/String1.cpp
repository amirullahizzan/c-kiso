#include <iostream>

using namespace std;


int main()
{
	char hello[] = "Hello!";

	cout << "�u" << hello << "�v�𕶎��R�[�h�ɕς����" << endl;

	for (int i = 0; i < (int)sizeof hello; i++)
	{
		cout << (int)(unsigned char)hello[i] << "�A";
	}

	cout << endl
	<< "�ɂȂ�܂��B" << endl;
}