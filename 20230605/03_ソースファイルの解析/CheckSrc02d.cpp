// CheckSrc02d.exe�Ɠ������s���ʂɂȂ�悤�ɂ��Ă�������
#include <iostream>
using namespace std;

// ���͂��ꂽ���l���擾����֐�
int get_input_num()
{
	int n;
	cout << "���l����� > " << flush;
	cin >> n;
	return n;
}

int main()
{
	int num = 0;

	for (int i = 0; i < 5; ++i)
	{
		cout << i << ": " << (i + 1) * 2 << endl;
	}

	system("pause");
	return 0;
}