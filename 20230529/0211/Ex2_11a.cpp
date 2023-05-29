#include <iostream>

using namespace std;

int numbers[] = {5,85,67,91,23,41,13,38,91, 2 };

int main()
{
	int sum = 0;
	float avg = 0;

	cout << "====================================" << endl;
	cout << "10 個の数値の合計と平均を出力します"	   << endl;
	cout << "====================================" << endl;

	for (int i = 0;i<10;i++)
	{
		cout << i<<": " << numbers[i]<<endl;
		sum += numbers[i];
	}

	avg = sum / 10.0;

	cout << "10 個の数値の合計: " << sum << endl;
	cout << "10 個の数値の平均: " << avg << endl;
}