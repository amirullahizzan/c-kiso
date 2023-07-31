#include <iostream>

using namespace std;


bool isHundred = false;
bool isZero = false;
int randomnum = 0;
int randomnumcount = 0;

int main()
{
	srand((unsigned int) time(NULL));

	while (true)
	{
		for (int i = 0; i < 15 ;i++) 
		{
		randomnum = rand() % 101;
		printf_s("%3d ", randomnum);
		randomnumcount++;
		if (randomnum == 100)
		{
			isHundred = true;
		}
		if (randomnum == 0)
		{
			isZero = true;
		}
		if (isHundred && isZero)
		{
			break;
		}
	}
	cout << endl;
	if (isHundred && isZero)
	{
		break;
	}
	}
	cout << "-------------------------------------------" << endl;
	cout << "0と100が出現するまで " << randomnumcount << " 回ループを回しました" << endl;


	cout << endl;
	cout << "プログラムは終了します..." << endl;

system("pause");
return 0;
}
