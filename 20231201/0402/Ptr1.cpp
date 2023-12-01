#include <iostream>

using namespace std;

int* test()
{
	int a = 0;

	return &a;
}

int main()
{
	test();

	int a;
	int* p;

	void* voidptr = nullptr;
	cout << " = " << (size_t)&voidptr << endl;
}