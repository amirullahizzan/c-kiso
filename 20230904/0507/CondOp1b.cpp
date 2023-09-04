#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "2 つ値を入力してくだし > " << flush;
	cin >> a >> b;

	//if (a > b)
	//{
	//	cout << "大きいほうの値は " << a << " です。" << endl;
	//}
	//else
	//{
	//	cout << "大きいほうの値は " << b << " です。" << endl;
	//}


	cout << "大きいほうの値は " << (a > b ? a : b) << " です。" << endl;


}
