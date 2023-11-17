#include "Stream.h"
#include "InputStream.h"
#include "ArrayStream.h"
#include <iostream>

using namespace std;


bool Average(InputStream& stream)
{
	int	count;
	double avg = 0;

	for (count = 0; stream.Set(); count++)
	{
		avg += stream.Get();
	}

	if (count == 0)
	{
		return false;
	}

	avg = avg / count;

	cout << count << "個の値の平均値は " << avg << " です。" << endl;
	return true;
}


//returns whether the value is average or not and calculates the average
bool Average(ArrayStream& stream)
{
	int	count;
	double avg = 0;

	for (count = 0; stream.Set(); count++)
	{
		avg += stream.Get();
	}

	if (count == 0)
	{
		return false;
	}

	avg = avg / count;

	cout << count << "個の値の平均値は " << avg << " です。" << endl;
	return true;
}

int main()
{
	cout << "<<<<<<<INPUTSTREAM<<<<<<<<<" << endl;
	while (true)
	{
		InputStream stream;
		if (!Average(stream))
		{
			break;
		}
	}
	cout << "<<<<<<<ARRAYSTREAM<<<<<<<<<" << endl;

	static const double ARRAY1[] = { 1,2,3,-1 };
	static const double ARRAY2[] = { 0.5,1.5,-1 };
	static const double ARRAY3[] = { -1 };
	static const double* ARRAYS[] = { ARRAY1 ,ARRAY2,ARRAY3 };
	static const int SIZE = sizeof ARRAYS / sizeof * ARRAYS;
	for (int i = 0; i < SIZE; i++)
	{
		ArrayStream stream(ARRAYS[i]);
		if (!Average(stream))
		{
			break;
		}
	}

	cout << "プログラムは終了しました" << endl;

	system("pause");
	return 0;
}

