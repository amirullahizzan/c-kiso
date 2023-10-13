#include <iostream>
using namespace std;

class Forecast
{
	const char* weather = nullptr;
	int highest_temp;
	int lowest_temp;
	int rain;

	public :
		void ShowWeather(const char* weather_, int htemp_, int ltemp_, int rain_);

};

void Forecast::ShowWeather(const char* weather_, int htemp_, int ltemp_, int rain_)
{
	cout << "-------------------------------------------" << endl;
	cout <<       "天気: " << weather_ << endl
		 <<  " 最高気温: " << htemp_   << flush
		 << ", 最低気温: " << ltemp_   << flush
		 << ", 降水確率: " << rain_    << endl;
}

int main()
{
	Forecast forecast[7];

	const int WEEK = 7;
	// 天気
	const char* weather[WEEK] = 
	{
		"晴れ", "雨",  "晴れ", "曇り", "晴れのち雨", "晴れ", "晴れ"
	};
	// 最高気温
	for (int i = 0 ;i < WEEK;i++)
	{
	forecast[i].highest_temp =	{
		20, 22, 25, 20, 19, 23, 21
	};

	}
	// 最低気温
	int lowest_temp[WEEK] = {
		16, 18, 15, 16, 14, 18, 16
	};
	// 降水確率
	int rain[WEEK] = 
	{
		0, 100, 20, 30, 50, 20, 0
	};

	for (int i = 0; i < WEEK; ++i) {
		forecast.ShowWeather(weather[i], highest_temp[i], lowest_temp[i], rain[i]);
	}
	cout << "-------------------------------------------" << endl;

	system("pause");
	return 0;
}