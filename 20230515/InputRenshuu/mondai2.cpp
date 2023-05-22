#include <iostream>

using namespace std;

//問題 2
//1. 整数値の入力
//2. 整数値の入力
//3. 「2.」で入力された値が 0 であれば、「0 では割れません」と出力
//そうじゃなければ、「1.」で入力された値を「2.」で入力された値で割った値を
//「「1.」で入力された値 ÷ 「2.」で入力された値 = 「1.」で入力された値と「2.」で
//入力された値を割った数値」
//という形式で出力
//※ 下線部分は、それぞれ数値が出力されます

void PrintIsDivible(int num1, int num2)
{
    if (num2 != 0)
    {
        int result = num1 / num2;
        cout << num1 << " ÷ " << num2 << " = \n";
        return;
    }
    cout << "0　で割れません" << endl;
}

int InputNumber(int num)
{
    cin >> num;
    //cout << num << endl;
    return num;
}

void ProcessNumber(int num1, int num2)
{
    num1 = InputNumber(num1);
    num2 = InputNumber(num2);

    PrintIsDivible(num1, num2);
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    
    ProcessNumber(num1,num2);
}