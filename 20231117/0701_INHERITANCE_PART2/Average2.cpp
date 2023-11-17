#include <iostream>
#include "InputStream.h"
using namespace std;

//returns whether the value is average or not and calculates the average
bool Average(InputStream& stream)
{
	int	count;
	double avg = 0;

	for (count = 0; stream.Set(); count++)
	{
		avg+=stream.Get();
	}

	if (count == 0)
	{
		return false;
	}

	avg = avg / count;

	cout << count << "�̒l�̕��ϒl�� " << avg << " �ł��B" << endl;
	return true;
}

int main()
{
	while (true)
	{
		InputStream stream;
		if (!Average(stream))
		{
			break;
		}
	}

	cout << "�v���O�����͏I�����܂���" << endl;

	system("pause");
	return 0;
}

