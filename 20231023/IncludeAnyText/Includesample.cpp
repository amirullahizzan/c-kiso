#include <iostream>

using namespace std;

//Add file from outside, and compile it. (not /Data so not retroactive)
int map[5][10] =
{
#include "Sample.txt"
};

int main()
{

	//多次元配列MAPを出力
	for (int y = 0; y < 5;y++)
	{
		for (int x = 0; x < 10; x++)
		{
			cout << map[y][x] << flush;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}