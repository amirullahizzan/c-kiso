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
	cout <<       "�V�C: " << weather_ << endl
		 <<  " �ō��C��: " << htemp_   << flush
		 << ", �Œ�C��: " << ltemp_   << flush
		 << ", �~���m��: " << rain_    << endl;
}

int main()
{
	Forecast forecast[7];

	const int WEEK = 7;
	// �V�C
	const char* weather[WEEK] = 
	{
		"����", "�J",  "����", "�܂�", "����̂��J", "����", "����"
	};
	// �ō��C��
	for (int i = 0 ;i < WEEK;i++)
	{
	forecast[i].highest_temp =	{
		20, 22, 25, 20, 19, 23, 21
	};

	}
	// �Œ�C��
	int lowest_temp[WEEK] = {
		16, 18, 15, 16, 14, 18, 16
	};
	// �~���m��
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