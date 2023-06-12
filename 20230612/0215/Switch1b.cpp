#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i<5; i++)
	{
		int a, b, op, result;

		cout << "第　１　項 > " << flush;
		cin >> a;
		cout << "第　２　項 > " << flush;
		cin >> b;
		
		cout << "1: 加算, 2: 減算, 3: 乗算, 4: 除算 > " << flush;
		cin >> op;

		if (b == 0)
		{
			cout << "エラー！ 0 で割れませんよ！。 " << "(CANNOT DIVIDE BY 0)" << endl;
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
					cout << "エラー！ 0 で割れませんよ！。 " << "(CANNOT DIVIDE BY 0)" << endl;
					continue;
				}*/
				result = a / b;
				break;

			default :
				cout << "真面目せんかい！" << endl;
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
			cout << "真面目にせんかい！" << endl;
			continue;
		}*/
	
		cout << "答えは　" << result << " です。" << endl;


	}
}