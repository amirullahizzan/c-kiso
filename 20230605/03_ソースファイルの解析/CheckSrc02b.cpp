// CheckSrc02b.exe�Ɠ������s���ʂɂȂ�悤�ɂ��Ă�������
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
	int a = 0;	... �ЂƂ߂̓���
	int b = 0;	... �ӂ��߂̓���

	cout << "���l1: " << a << " / ���l2: " << b << endl;
	cout << a << " + " << b << " = " << (a + b) << endl;
	cout << a << " - " << b << " = " << (a - b) << endl;
	cout << a << " * " << b << " = " << (a * b) << endl;
	cout << a << " / " << b << " = " << (a / b)
		 << " ...���܂�"		<< (a % b) << endl;

	system("pause");
	return 0;
}
