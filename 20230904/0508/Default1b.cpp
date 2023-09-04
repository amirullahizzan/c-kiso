#include <iostream>

//modified Default1.cpp from sensei

using namespace std;

//setting default arg
void func1(int a1 = 0)
{
	cout << a1 << endl;
}

int main()
{
	func1(127);
	func1();

	system("pause");
	return 0;
}


//default args forward declaration

//void func1(int a1 = 0);
//
//int main()
//{
//	func1(127);
//	func1();
//
//	system("pause");
//	return 0;
//}
//
//void func1(int a1)
//{
//	cout << a1 << endl;
//}

// double default args, DEFAULT ARGS MUST BE PUT IN THE BACK

//void func1(int b, int a1 = 0)
//{
//	cout << a1 << endl;
//}
//int main()
//{
//	func1(127); //--> WILL AUTOMATICALLY FILL DEFAULT ARGS int a1
//	func1();
//
//	system("pause");
//	return 0;
//}
//
