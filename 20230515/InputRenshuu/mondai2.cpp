#include <iostream>

using namespace std;

//��� 2
//1. �����l�̓���
//2. �����l�̓���
//3. �u2.�v�œ��͂��ꂽ�l�� 0 �ł���΁A�u0 �ł͊���܂���v�Əo��
//��������Ȃ���΁A�u1.�v�œ��͂��ꂽ�l���u2.�v�œ��͂��ꂽ�l�Ŋ������l��
//�u�u1.�v�œ��͂��ꂽ�l �� �u2.�v�œ��͂��ꂽ�l = �u1.�v�œ��͂��ꂽ�l�Ɓu2.�v��
//���͂��ꂽ�l�����������l�v
//�Ƃ����`���ŏo��
//�� ���������́A���ꂼ�ꐔ�l���o�͂���܂�

void PrintIsDivible(int num1, int num2)
{
    if (num2 != 0)
    {
        int result = num1 / num2;
        cout << num1 << " �� " << num2 << " = \n";
        return;
    }
    cout << "0�@�Ŋ���܂���" << endl;
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