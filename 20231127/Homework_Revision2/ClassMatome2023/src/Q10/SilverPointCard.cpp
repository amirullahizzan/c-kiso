#include <iostream>
#include "PointCardBase.h"
#include "SilverPointCard.h"
using namespace std;
// ----------------------------------------------
//	�V���o�[�|�C���g�J�[�h�N���X�i�\�[�X�t�@�C���j
//	 �|�C���g���Z���A���Z�|�C���g�~1.25�{�ŉ��Z
//	 �� �����_�ȉ��̃|�C���g�͐؂�̂�
// ----------------------------------------------
SilverPointCard::SilverPointCard()
{
	setType(TYPE::Silver);
}

void SilverPointCard::addPoint(int var)
{
	point_ += static_cast<int>(var * 1.25f);
}