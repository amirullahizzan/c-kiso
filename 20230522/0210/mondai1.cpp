#include <iostream>

using namespace std;

int func(int a, int b)
{
	return a + b;
}

void displayfunc(int a, int b)
{

}

int main() 
{
	int favoritenum2[] =
	{
		7,-5,0,9,6,10,-3,24
	};

	int favoritenum[8];

	favoritenum[0] = 7;
	favoritenum[1] = -5;
	favoritenum[2] = 0;
	favoritenum[3] = 9;
	favoritenum[4] = 6;
	favoritenum[5] = 10;
	favoritenum[6] = -3;
	favoritenum[7] = 24;

	int ans1 = func(favoritenum[1], favoritenum[3]);
	int ans2 = func (favoritenum[4], favoritenum[0]);
	int ans3 = func(favoritenum[7], favoritenum[6]);
	int ans4 = func(favoritenum[5], favoritenum[2]);

	cout << "好きな「1」＋ 好きな「3」 = " << ans1 << endl;
	cout << "好きな「4」＋ 好きな「0」 = " << ans2 << endl;
	cout << "好きな「6」＋ 好きな「7」 = " << ans3 << endl;
	cout << "好きな「5」＋ 好きな「2」 = " << ans4 << endl;
}