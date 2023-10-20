#include <iostream>
#include <ctime>

using namespace std;

const int INTARRAY_SIZE = 100;

class IntArray
{
public : 
	int m_array[INTARRAY_SIZE];

	IntArray();

	int Get(int i);
	void Set(int i, int value);

	void CheckIndex(int i);

};

IntArray::IntArray()
{
	//fill_n は指定したデータで配列などを埋める関数のようなものです
	fill_n(m_array, INTARRAY_SIZE, 0);

	

	cout << "コンストラクターが呼ばれました" << endl;
}

int IntArray::Get(int i)
{
	CheckIndex(i);
	return m_array[i];
}

void IntArray::Set(int i, int value)
{
	CheckIndex(i);
	m_array[i] = value;
}

void IntArray::CheckIndex(int i)
{

	if (0 <= i && i < INTARRAY_SIZE)
	{
		//Index 正常
	}
	else
	{
		cout << "インデックスが不正です！！" << endl
		<< "値：" << i << endl;
		exit(EXIT_FAILURE);
	}

}

int main()
{
	srand((unsigned int)time(NULL));

	IntArray iarray;

	for (int i = 0; i < INTARRAY_SIZE; i++)
	{
		int n = rand() % 101+1-1;
		int m = rand() % 501;
		
		//printfs("[%2d]",i, iarray.Set(i));

	}

		//printfs("[%2d]",i, iarray.Get(i));


	system("pause");

	return 0;
}
