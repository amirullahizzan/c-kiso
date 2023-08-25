#include <iostream>

using namespace std;

int numbers[15];
int numbersequence[15];
int middlenumber = 0;
int temp;

void GenerateRand(int& num)
{
	//-100`100
	num = rand()% 201 - 100;
}

void PrintSorted()
{

	for (int i = 0; i < 15; i++)
	{
		printf_s("[%2d] : %4d\n", i, numbersequence[i]);
		//cout << "[" << i << "]" << " : " << numbers[i] << endl;
	}
}
int main()
{
	srand((unsigned int)(time(NULL)));

	cout << "------------------------------------" << endl;

	for (int i = 0; i < 15; i++)
	{
		GenerateRand(numbers[i]);
		numbersequence[i] = numbers[i];
		printf_s("[%2d]: %4d\n", i, numbers[i]);
		//cout << "[" << i << "]" << " : " << numbers[i] << endl;
	}

	for (int i = 0; i < 15 ; i++)
	{
		for (int j = i + 1; j < 15; j++)
		{
			if (numbersequence[i] > numbersequence[j])
			{
				temp = numbersequence[i];
				numbersequence[i] = numbersequence[j];
				numbersequence[j] = temp;
			}
		}

	}

	//PrintSorted();

	middlenumber = numbersequence[7];

	cout << "------------------------------------"    <<
										 endl << endl <<
		    "^‚ñ’†‚Ì’l‚ÍA" << middlenumber << " ‚Å‚·" <<
										 endl << endl <<
		    "------------------------------------"    << endl;

	system("pause");
	return 0;
}