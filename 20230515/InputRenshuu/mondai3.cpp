#include <iostream>

using namespace std;

//��� 3
//1. �����l�̓���
//2. �����l�̓���
//3. �u1.�v�œ��͂��ꂽ�l�������́u2.�v�œ��͂��ꂽ�l�� 100 �ȏ�ł���΁u���͂��ꂽ
//���l�� 100 �ȏ�Ȃ̂Ōv�Z�ł��܂���v�Əo��
// 
//��������Ȃ���΁A�u1.�v�œ��͂��ꂽ�l�Ɓu2.�v�œ��͂��ꂽ�l�̈ꌅ�ڂ̐��l������
//�u�u1.�v�œ��͂��ꂽ�l�̈ꌅ�ڂ́A�u1.�v�œ��͂��ꂽ�l�̈ꌅ�ڂ̐��l
//�u2.�v�œ��͂��ꂽ�l�̈ꌅ�ڂ́A�u2.�v�œ��͂��ꂽ�l�̈ꌅ�ڂ̐��l�v
// 
//�Ƃ����`���ŏo��
//�� �ꌅ�ڂƂ́u123�v�Ƃ������l�ł���΁A�u3�v�ɂȂ�܂�
//�܂��A���������́A���ꂼ�ꐔ�l���o�͂���܂�

//��
void PrintLastDigit(int num1, int num2)
{
    if (num1 >= 100 || num2 >= 100)
    {
        cout << "���͂��ꂽ���l���@100 �ȏ�Ȃ̂Ōv�Z�ł��܂���" << endl;
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