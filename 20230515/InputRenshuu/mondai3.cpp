#include <iostream>

using namespace std;

//問題 3
//1. 整数値の入力
//2. 整数値の入力
//3. 「1.」で入力された値もしくは「2.」で入力された値が 100 以上であれば「入力された
//数値が 100 以上なので計算できません」と出力
// 
//そうじゃなければ、「1.」で入力された値と「2.」で入力された値の一桁目の数値だけを
//「「1.」で入力された値の一桁目は、「1.」で入力された値の一桁目の数値
//「2.」で入力された値の一桁目は、「2.」で入力された値の一桁目の数値」
// 
//という形式で出力
//※ 一桁目とは「123」という数値であれば、「3」になります
//また、下線部分は、それぞれ数値が出力されます

//桁
void PrintLastDigit(int num1, int num2)
{
    if (num1 >= 100 || num2 >= 100)
    {
        cout << "入力された数値が　100 以上なので計算できません" << endl;
        return;
    }
    else
    {
        cout << num1 % 10 << endl;
        cout << num2 % 10 << endl;
    }
}

int InputDigit(int num)
{
    cin >> num;
    //cout << num << endl;
    return num;
}

void ProcessNumber(int num1, int num2) 
{
    num1 = InputDigit(num1);
    num2 = InputDigit(num2);

    PrintLastDigit(num1, num2);
}

int main()
{
    int num1 = 0;
    
    int num2 = 0;
    
    ProcessNumber(num1, num2);
}