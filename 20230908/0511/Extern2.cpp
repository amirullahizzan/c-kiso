#include <iostream>

extern int a; // Extern1.cpp �� a ���Q��
void Func(); // Extern1.cpp �� Func ���Q��

int main()
{
	Func();
	a = 5;
	Func();
}