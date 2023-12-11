#include <iostream>

using namespace std;

void CalcMultiples(int*  array, int size, int n)
{
	for (int i = 0;i< size ; i++)
	{
		array[i] = n * (i + 1);
	}
}

void ShowArray(const int* array, int size)
{
	for (int i = 0 ; i < size;i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main()
{
	int* array = nullptr;
	int size = 0;

	cout << "‚Ç‚±‚Ü‚ÅŒvŽZ‚µ‚Ü‚·‚©H > " << flush;
	cin  >> size;

	array = new int[size];

	CalcMultiples(array,size,3);
	ShowArray(array, size);

	delete[] array;	

	//Differs
	/*for (int i = 0; i < size;i++)
	{
		delete[] array;
	}*/
}