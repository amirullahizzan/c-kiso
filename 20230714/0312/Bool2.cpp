#include <iostream>

using namespace std;

bool IsDigit(char ch)
{
	return '0' <= ch && ch <= '9'; //CHR's 0, not zero or null
}

bool IsQuit(char ch)
{
	return ch == 'Q' || ch == 'q';
}


int main()
{
	while (true)
	{
		char ch;

		cout << "������������͂��Ă������� > " << flush;
		cin >> ch;
		if (IsQuit(ch))
		{
			break;
		}

		if (IsDigit(ch))
		{
			cout << "�����ł��B" << endl;
		}
		else
		{
			cout << "�����ł͂���܂���B" << endl;
		}
	}

	cout << "�I�����܂��B" << endl;
}