// CheckSrc02e.exe�Ɠ������s���ʂɂȂ�悤�ɂ��Ă�������
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		int num;
		cout << "���l����� > " << flush;
		cin >> num;

		if (num > 10)
		{

		}
		cout << num << " * 2  = " << num * 2 << endl;
	}

	system("pause");
	return 0;
}