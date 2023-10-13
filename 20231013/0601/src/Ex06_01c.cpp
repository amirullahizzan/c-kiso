#include <iostream>
using namespace std;

class PlayerData
{

};

void ShowParameter(const char* job_, int hp_, int mp_)
{
	printf_s("êEã∆: %s\n HP: %2d / MP: %2d\n", job_, hp_, mp_);
}

int main()
{
	PlayerData playerdata;
	const int MEMBER_NUM = 4;
	const char* job[MEMBER_NUM] = {
		"óEé“", "êÌém", "ñÇñ@égÇ¢", "ëmóµ"
	};
	const int hp[MEMBER_NUM] = {
		11, 23, 21, 14,
	};
	const int mp[MEMBER_NUM] = {
		11,  9, 25, 17
	};

	for (int i = 0; i < MEMBER_NUM; ++i) {
		ShowParameter(job[i], hp[i], mp[i]);
	}

	system("pause");
	return 0;
}