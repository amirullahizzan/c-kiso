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

		cout << "何か文字を入力してください > " << flush;
		cin >> ch;
		if (IsQuit(ch))
		{
			break;
		}

		if (IsDigit(ch))
		{
			cout << "数字です。" << endl;
		}
		else
		{
			cout << "数字ではありません。" << endl;
		}
	}

	cout << "終了します。" << endl;
}