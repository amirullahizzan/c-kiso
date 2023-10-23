//Operator Overload

#include <iostream>
using namespace std;

class Pos
{
private :
	int x_ = 0,	y_ = 0;

public :
	Pos(int x, int y); //コンストラクト

	int getX() const; //座標ｘを取得
	int getY() const; //座標yを取得

	void setX(int x); //座標ｘに代入
	void setY(int y); //座標yに代入

	bool operator==(const Pos& other_pos);
};

Pos::Pos(int x, int y)
{
	x_ = x;
	y_ = y;
}

// can save some memory
int Pos::getX()const 
{
	return x_;
}

int Pos::getY()const
{
	return y_;
}

void Pos::setX(int x)
{
	x_ = x;
}

void Pos::setY(int y)
{
	y_ = y;
}

bool Pos::operator==(const Pos& other_pos)
{
	return x_ == other_pos.getX() &&
		   y_ == other_pos.getY();
}

int main()
{
	Pos pos1(1, 2);
	Pos pos2(0, 0);

	printf_s("NPC1[X] : %d [Y] : %d\n", pos1.getX(), pos1.getY());
	printf_s("NPC2[X] : %d [Y] : %d\n", pos2.getX(), pos2.getY());

	if (pos1 == pos2)
	{
		cout << "同じ場所にいます" << endl;
	}
	else
	{
		cout << "同じ場所にいます" << endl;
	}

	system("pause");
	return 0;
}