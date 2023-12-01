#include <iostream>

using namespace std;

void Foo()
{
	int a;
	a = 0;
	char b[10];
	cout << "a : " << (size_t)&a << endl;
	cout << "b : " << (size_t)b << endl;
	cout << "Foo : " << (size_t)Foo << endl;
	cout << "size_t : " << sizeof(size_t) << endl;

}

int main()
{

	Foo();
}