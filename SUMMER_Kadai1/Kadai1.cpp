#include <iostream>

using namespace std;

#define MAXNUMBER 100
#define MINNUMBER -100

int main()
{
	int maxinput = 0;
	int mininput = 0;
	bool isMaxInputStored = false;
	bool isMinInputStored = false;
	int randomizednumbers = 0;
	int randomcounter = 0;

	srand((unsigned int)time(NULL));

		cout<< "--------------------" << endl
			<< "    乱数の上限値" << endl
			<< "--------------------" << endl;

	for (;;)
	{
		
		cout << "数値入力 > ";
		cin >> maxinput;
		if (maxinput < 0 || maxinput > 100)
		{
			cout << "ERROR: 入力は0～100までです" << endl;
			continue;
		}

		break;
	}

	cout << "--------------------" << endl
		<< "    乱数の下限値" << endl
		<< "--------------------" << endl;

	for (;;)
	{
		cout << "数値入力 > ";
		cin >> mininput;

		if (maxinput < mininput || maxinput == mininput || mininput < -100)
		{
			cout << "ERROR: 入力は" << MINNUMBER << "～" << maxinput - 1 << "までです" << endl;
			continue;
		}

		break;
	}

	cout << mininput << "～" << maxinput << "までの乱数を生成します" << endl << endl;

	for (int i = 1;;i++)
	{
		randomizednumbers = rand() % (maxinput - mininput + 1) + mininput; //prints out desired pos and negative. modulo cannot handle negative number
		printf_s("%4d ", randomizednumbers);
		if (randomizednumbers == mininput)
		{
			isMinInputStored = true;
		}
		if (randomizednumbers == maxinput)
		{
			isMaxInputStored = true;
		}
		if (isMinInputStored && isMaxInputStored)
		{
			break;
		}
		if (i != 0 && i % 8 == 0)
		{
			cout << endl;
		}

		randomcounter++;
	}

	cout << endl << endl << "上限値:" << maxinput << " 下限値 : " << mininput << " が出現するまで" << randomcounter << "回ループしました" << endl;

	system("pause");
	return 0;
}