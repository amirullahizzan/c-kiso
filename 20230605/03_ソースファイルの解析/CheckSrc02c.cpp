// CheckSrc02c.exe�Ɠ������s���ʂɂȂ�悤�ɂ��Ă�������
#include <iostream>
using namespace std;

// ���͂��ꂽ���l���擾����֐�
int get_input_num()
{
	int n;
	cout << "���l����� > " << flush;
	cin >> n;
	return 0;
}

// ������2�̐��l�𑫂�������{�ɂ����������߂�֐�
int get_answer(int a, int b)
{
	return 0;
}

// ������2�̐��l���u(a + b) + 2 = �����v�̌`�ŏo�͂���֐�
void show_answer(int a, int b)
{
	int answer = 0;
	cout << "(" << a << " + " << b << ") * 2 = " 
		 << answer
		 << endl;
	cout << "--------------------------------------" << endl;
}

int main()
{
	for (int i = 0; i < 2; ++i)
	{
		int num1 = get_input_num();
		int num2 = get_input_num();
		show_answer(num1, num2);
	}

	system("pause");
	return 0;
}