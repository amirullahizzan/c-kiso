#include <iostream>
#include <cmath>

using namespace std;

//辺 = side
//斜辺 = hypotenuse
//隣辺 = adjacent
//平方根 = sqrt
int main()
{
	double a, b;
	cout << "直角を挟む２辺の長さを入力してください > " << flush;
	cin >> a >> b;

	cout << "辺の長さは" << sqrtf(a * a + b * b) << " です。" << endl;
}

//sqrt or sqrtf