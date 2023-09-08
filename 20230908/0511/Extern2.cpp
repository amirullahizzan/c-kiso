#include <iostream>

extern int a; // Extern1.cpp ‚Ì a ‚ğQÆ
void Func(); // Extern1.cpp ‚Ì Func ‚ğQÆ

int main()
{
	Func();
	a = 5;
	Func();
}