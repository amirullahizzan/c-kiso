

#include <iostream>
#include <cstdlib>

using namespace std;

int Dice()
{
    return rand() % 6 + 1;
}

void InitRand()
{
    srand((unsigned int)time(NULL));
}


int main()
{
    InitRand();
    for (int i = 0; i < 20; i++)
    {
        cout << Dice() + Dice() << ' ';
    }
    cout << endl;
}

//‹^Ž—
//—•ss