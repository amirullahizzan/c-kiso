#include <iostream>

using namespace std;

int input[5];
int i = 0;
float sum = 0;
float heikin = 0;



int main()
{
	for (int j = 0;j<3 ;j++)
	{
		
		i = 0;
		sum = 0;
		heikin = 0;
	

	for (;i < 5; i++)
	{
		cout << "input " << i << "つ目を入力してください\n";
		cin >> input[i];
		sum += input[i];
	}

	heikin = sum / i;
	
	cout << "合計値 = " << sum << "\n平均値 = " << heikin << endl << endl;

	//reset
	
	}
}