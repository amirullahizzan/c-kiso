#include <iostream>
#include <cmath>

using namespace std;

//�� = side
//�Ε� = hypotenuse
//�ו� = adjacent
//������ = sqrt
int main()
{
	double a, b;
	cout << "���p�����ނQ�ӂ̒�������͂��Ă������� > " << flush;
	cin >> a >> b;

	cout << "�ӂ̒�����" << sqrtf(a * a + b * b) << " �ł��B" << endl;
}

//sqrt or sqrtf