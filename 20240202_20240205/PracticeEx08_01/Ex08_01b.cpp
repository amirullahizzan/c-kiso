#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "���������� > " << flush;
	string inputstr;
	getline(cin, inputstr);

	string inputSkip;
	while (inputSkip.size() <= 0)
	{
		cout << "�X�L�b�v���镶������� > " << flush;
		getline(cin, inputSkip);

		if (inputSkip.size() <= 0)
		{
			cout << "�X�L�b�v���镶����1�����ł�\n" << flush;
		}

	}

	string::size_type skipPos = inputstr.find(inputSkip);

	for (size_t i = 0; i < inputstr.size(); i++)
	{
		if (skipPos != string::npos)
		{
			inputstr.replace(skipPos, 1, "");
			//inputstr.erase(skipPos,5); //deletes all lines from a pos until N pos
		}
		skipPos = inputstr.find(inputSkip);
	}

	//inputstr.insert(skipPos, "");

	cout << inputstr << endl;

	system("pause");
	return 0;
}