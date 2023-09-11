#include <iostream>

using namespace std;



enum CompareResult
{
    CR_LESS_THAN = 0,
    CR_EQUAL_TO = 1,
    CR_GREATER_THAN = 2,
    CR_MAX = 3
};


CompareResult Compare(int a, int b)
{
    if (a < b)
    {
        return CR_LESS_THAN;
    }
    else if (a > b)
    {
        return CR_GREATER_THAN;
    }
    else
    {
        return CR_EQUAL_TO;
    }

}

bool Compare()
{
    const char* message[CR_MAX] =
    {
         "�O�҂͌�҂�菬�����ł��B","���҂͓������ł��B","�O�҂͌�҂��傫���ł��B"
    };
    int a, b;

    cout << "������ 2 ���͂��Ă������� > " << flush;
    cin >> a >> b;

    if (a == -1)
    {
        return false;
    }

    cout << message[Compare(a, b)] << endl;


    return true;
}


int main()
{
    cout << "����ɂ���" << endl;
    cout << "����ɂ���\n";
    while (Compare())
    {
        //�������Ȃ�
    }

}