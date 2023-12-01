#include <iostream>

using namespace std;

int main()
{
	char array[10];

	cout << "array      :    " << (size_t)array << endl;
	for (int i = 0 ;i < 10; i++)
	{
		cout << "&array      [" << i << "]   :" << (size_t)&array[i] << endl;
		cout << "&array      [" << i << "]   :" << (size_t)array[i] << endl;
	}
}

//&array 0 0x00000078900FFB78
//&array 1 0x00000078900FFB79
//&array 2 0x00000078900FFB7A

