#include <iostream>

using namespace std;

int main()
{
	char str[32] = {};
	char previousword[32] = {};

	int charlength = 0;
	int previouscharlength = 0;

	int gamescount = 0;
	bool islastwrong = false;

	cout << "Shiritori　始め！" << endl;
	cout << "=========================" << endl;
	while (true)
	{
		//cout << (char)(-0) << endl;

		if (gamescount > 0 && islastwrong == false)
		{
			previouscharlength = charlength;
			for (int i = 0; str[i] != '\0'; i++)
			{
				previousword[i] = str[i];
			}
		}
		charlength = 0;

		cout << "input string > " <<flush;
		cin >> str;

		for (int i = 0; str[i] != '\0'; i++)
		{
			charlength++;
		}

		for (int i = 0; str[i] != '\0';i++)
		{
			if (int(str[i]) < 65 || int(str[i]) > 122)
			{
				cout << str << " は半角MOJI ではない！" << endl;
				exit(0);
			}
			//cout << (int)(str[0]) << endl;

		}

		if (charlength <= 2)
		{
			cout << "2文字以上の文字列にしてください" << endl;
			islastwrong = true;
			continue;
		}
		if (charlength > 31)
		{
			cout << "MORE THAN 32 SIZE, PROGRAM TERMINATING" << endl;
			break;
		}

		//cout << "the last letter was : " << str[charlength - 1] << endl;
		if (gamescount == 0)
		{
			cout << "=========================" << endl;
			cout << "Insert the next word!" << endl;
		}


		if ( gamescount > 0)
		{
			islastwrong = false;

			if (previousword[previouscharlength-1] == str[0])
			{
				cout << previousword << "→" << str << endl;
			}
			else
			{
				cout << "Your str first letter :  " << str[0]<<endl;
				cout << "Last shiritori :  " << previousword[previouscharlength-1]<<endl;
				cout << gamescount << " 個の文字列を続けられました " << endl;
				break;
			}
		}

		if (gamescount > 0)
		{
			cout << "=========================" << endl;
			cout << "Insert the next word!" << endl;
		}

		gamescount++;

	}

	


	system("pause");
	return 0;
}

