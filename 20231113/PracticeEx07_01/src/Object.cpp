#include "Object.h"
#include <iostream>
int Object::getRandNum(int max, int min)
{
	return min + rand() % (max - min + 1);
}