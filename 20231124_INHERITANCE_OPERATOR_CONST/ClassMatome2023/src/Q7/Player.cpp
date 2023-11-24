#include "Player.h"
#include <iostream>
using namespace std;

Player::Player() :
	m_n(0)
{

}

void Player::Set()
{
	cout << "Player::Set()" << endl;
	m_n = 1;
}

void Player::Mul()
{
	m_n *= 2;
}

int Player::Get() const
{
	return m_n;
}
