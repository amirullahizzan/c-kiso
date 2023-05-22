#include <iostream>
#include "mondai1.h"

using namespace std;

//問題 1
//1. 整数値の入力
//2. 整数値の入力
//3. 「1.」で入力された値と「2.」で入力された値が等しければ、OK と出力

void DisplayOK(int num1, int num2)
{
    if (num1 != num2) return;
        cout << "OK!" << endl;
    
}

int InputNumber(int num)
{
    cin >> num;
    //cout << num << endl;
    return num;
}

void ProcessNumber(int& num1, int& num2)
{
    num1 = InputNumber(num1);
    num2 = InputNumber(num2);

    DisplayOK(num1, num2);
}

int main()
{
    int num1 = 0;
    int num2 = 0;

    ProcessNumber(num1, num2);
}
