#include <iostream>
//#include "../Person.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;



int main()
{
	Teacher person1;	
	Student person2;

	person1.set("Mike", "Mathematics");
	person2.set("Alice", "High School", 2);

	cout << person1.getName() << endl;
	cout << person2.getName() << endl;

	system("pause");
	return 0;
}