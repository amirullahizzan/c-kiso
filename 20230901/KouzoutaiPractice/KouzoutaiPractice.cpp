#include <iostream>

using namespace std;

struct Date
{
//private : 
    int year = 0;
    int month = 0;
    int day = 0;
};

struct Weather
{
//private : 
    char weather[256] = {};
    int highesttemp = 0;
    int lowesttemp = 0;
    int chanceofrain = 0;
};

struct Game
{
//private : 
    char gamename[256] = {};
    char device[256] = {};
    int lowesttemp = 0;
    int chanceofrain = 0;
};

 int main()
{
    Date date[] = 
    { 
        { 2023,3,24 }, { 1998, 4, 15 }, { 2002, 12, 9 }, { 2007, 7, 31 } 
    };

    int size = sizeof date / sizeof *date; //date[0] same

    Weather weather[] =
    {
        { "晴れ",15,10,10 }, { "晴れ", 16, 10,0 }, { "雨", 11, 8, 100 }, { "曇り", 12, 9,40 }
    };

    int size = sizeof date / sizeof * date; //date[0] same


    for (int i = 0 ; i < size; i++)
    {
        printf_s("%4d年、%2d月、%2d日", date[i].year, date[i].month, date[i].day);
        cout << endl;
    }

    

    system("pause");
    return 0;
}

