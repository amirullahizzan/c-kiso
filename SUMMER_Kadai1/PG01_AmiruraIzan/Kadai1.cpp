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
			<< "    �����̏���l" << endl
			<< "--------------------" << endl;

	for (;;)
	{
		
		cout << "���l���� > ";
		cin >> maxinput;
		if (maxinput < 0 || maxinput > 100)
		{
			cout << "ERROR: ���͂�0�`100�܂łł�" << endl;
			continue;
		}

		break;
	}

	cout << "--------------------" << endl
		<< "    �����̉����l" << endl
		<< "--------------------" << endl;

	for (;;)
	{
		cout << "���l���� > ";
		cin >> mininput;

		if (maxinput < mininput || maxinput == mininput || mininput < -100)
		{
			cout << "ERROR: ���͂�" << MINNUMBER << "�`" << maxinput - 1 << "�܂łł�" << endl;
			continue;
		}

		break;
	}

	cout << mininput << "�`" << maxinput << "�܂ł̗����𐶐����܂�" << endl << endl;

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

	cout << endl << endl << "����l:" << maxinput << " �����l : " << mininput << " ���o������܂�" << randomcounter << "�񃋁[�v���܂���" << endl;

	system("pause");
	return 0;
}