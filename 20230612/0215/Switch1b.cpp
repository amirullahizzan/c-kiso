#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i<5; i++)
	{
		int a, b, op, result;

		cout << "��@�P�@�� > " << flush;
		cin >> a;
		cout << "��@�Q�@�� > " << flush;
		cin >> b;
		
		cout << "1: ���Z, 2: ���Z, 3: ��Z, 4: ���Z > " << flush;
		cin >> op;

		if (b == 0)
		{
			cout << "�G���[�I 0 �Ŋ���܂����I�B " << "(CANNOT DIVIDE BY 0)" << endl;
			continue;
		}

		switch (op)
		{
			case 1 :
				
				result = a + b;
				break;

			case 2:
				result = a - b;
				break;

			case 3:
				result = a * b;
				break;

			case 4:
				/*if (b == 0)
				{
					cout << "�G���[�I 0 �Ŋ���܂����I�B " << "(CANNOT DIVIDE BY 0)" << endl;
					continue;
				}*/
				result = a / b;
				break;

			default :
				cout << "�^�ʖڂ��񂩂��I" << endl;
				//can use continue instead of break; 
				continue;
				//or just don't fill it unless you want to loop the switch with continue.
		}

		/*if (op == 1)
		{
			result = a + b;
		}
		else if (op == 2)
		{
			result = a - b;

		}
		else if (op == 3)
		{
			result = a * b;

		}
		else if (op == 4)
		{
			result = a / b;

		}
		else
		{
			cout << "�^�ʖڂɂ��񂩂��I" << endl;
			continue;
		}*/
	
		cout << "�����́@" << result << " �ł��B" << endl;


	}
}