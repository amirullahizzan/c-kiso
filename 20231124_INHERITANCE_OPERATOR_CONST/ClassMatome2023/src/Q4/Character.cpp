#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(const char* str_) :
	m_str(str_)
{
	
}

bool Character::Search(char c) const
{
	for (int i = 0; m_str[i] != '\0'; ++ i) {
		if (c == m_str[i])	return true;
	}
	return false;
}

void Character::Show() const
{
	cout << m_str << flush;
}