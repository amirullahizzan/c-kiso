//	最高速度
//	加速
//	重さ
//	曲がりやすさ
//	滑りにくさ
#include <iostream>
using namespace std;


void ShowParameters(int max_speed_, int acceleration_, int weight_, int corner_, int slip_)
{
	cout << "-----------------------------------------------" << endl;
	cout << "最高速度: "		 << max_speed_	  << flush
		 <<   " ,加速: "		 << acceleration_ << flush
		 <<   " ,重さ: "		 << weight_		  << flush
		 <<   " ,曲がりやすさ: " << corner_		  << flush
		 <<   " , 滑りにくさ: "  << slip_		  << endl;
}


int main()
{
	const int CAR_TYPE_NUM = 4;
	int max_speed[CAR_TYPE_NUM] = {
		150, 180, 200, 300
	};
	int acceleration[CAR_TYPE_NUM] = {
		100, 80, 50, 30
	};
	int weight[CAR_TYPE_NUM] = {
		10, 20, 50, 100
	};
	int corner[CAR_TYPE_NUM] = {
		100, 100, 80, 50
	};
	int slip[CAR_TYPE_NUM] = {
		10, 15, 50, 100
	};

	for (int i = 0; i < CAR_TYPE_NUM; ++i) {
		ShowParameters(max_speed[i], acceleration[i], weight[i], corner[i], slip[i]);
	}
	cout << "-----------------------------------------------" << endl;

	system("pause");
	return 0;
}