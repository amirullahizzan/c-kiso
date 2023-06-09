#include <iostream>
using namespace std;

int input;

void InputNumber()
{
    cout << "数字を入力してください > ";
    cin >> input;
    cout << endl;
}

int counter7 = 0;

void CheckIfSeven()
{
    if (input == 7)
    {
        counter7++;
    }
}

void DisplayMultiply()
{
    cout << input << " の 3倍した数は = " << input * 3 << endl;
    cout << "==========================" << endl;
}

//USING WHILE

int main()
{
    while(true)
    {
        InputNumber();
        CheckIfSeven();
        if (counter7 == 3)
        {
            cout << "7が３回入力された為、プログラムは終了になります" << endl;
            //break;
            return 0;
        }
        DisplayMultiply();
    }

}


//USING FOR
// 
//int main()
//{
//    int counter7 = 0;
//    for (;;)
//    {
//    std::cout << "数字を入力してください ";
//    cin >> input;
//    cout << endl;
//   
//    if (input == 7) 
//    {
//        counter7++;
//        if (counter7 == 3)
//        {
//            break;
//        }
//    }
//    cout << input << " の 3倍した数は = " << input * 3 << endl;
//    cout << "==========================" << endl;
//    }
//
//}
