#include <iostream>

using namespace std;

bool Input(double& n)
{
	cin >> n;
	return n >= 0;
}

//returns whether the value is average or not and calculates the average
bool Average()
{
	int	count;
	double n;
	double avg = 0;
	for (count = 0; Input(n);count++)
	{
		avg = avg + n;
	}

	if (count==0)
	{
		return false;
	}

	avg = avg / count;

	cout << count << "個の値の平均値は " << avg << " です。" << endl;
	return true;
}

int main()
{
	while (true)
	{
		if (Average() == false)
		{
			break;
		}
	}

	cout << "プログラムは終了しました" << endl;

	system("pause");
		return 0;
}

