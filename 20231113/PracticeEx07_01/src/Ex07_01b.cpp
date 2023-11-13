#include <iostream>
#include "Square.h"
#include "Circle.h"

using namespace std;

int main()
{
	Square obj_square;
	Circle obj_circle;

	int size = 0;
	int x	 = 0;
	int y	 = 0;

	size = 10 + obj_square.getRandNum(50);
	x	 = obj_square.getRandNum(960);
	y	 = obj_square.getRandNum(540);
	obj_square.set(x, y, size);


	size = 10 + obj_circle.getRandNum(50);
	x	 = obj_circle.getRandNum(960);
	y	 = obj_circle.getRandNum(540);
	obj_circle.set(x, y, size);


	printf_s("[x]: %3d [Y]: %3d\n", obj_square.getX(), obj_square.getY());
	printf_s("[x]: %3d [Y]: %3d\n", obj_circle.getX(), obj_circle.getY());

	system("pause");
	return 0;
}