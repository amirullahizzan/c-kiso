#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy() :
	m_n(0)
{

}

void Enemy::Set()
{
	cout << "Enemy::Set()" << endl;
	m_n = 10 + rand() % 10;
}

void Enemy::Mul()
{
	m_n *= 2;
}

int Enemy::Get() const
{
	return m_n;
}
