#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		int a, b, op, result;

		cout << "‘æ@‚P@€ > " << flush;
		cin >> a;
		cout << "‘æ@‚Q@€ > " << flush;
		cin >> b;
		cout << "1: ‰ÁŽZ, 2: Œ¸ŽZ, 3: æŽZ, 4: œŽZ > " << flush;
		cin >> op;

		switch (op)
		{
		case 1:
			result = a + b;
			break;

		case 2:
			result = a - b;
			break;

		case 3:
			result = a * b;
			break;

		case 4:
			result = a / b;
			break;

		default:
			cout << "^–Ê–Ú‚¹‚ñ‚©‚¢I" << endl;
			//can use continue instead of break;
			continue;
		}

		cout << "“š‚¦‚Í@" << result << " ‚Å‚·B" << endl;

	}
}