#include <iostream>
#include "PointCardBase.h"
#include "GoldPointCard.h"
using namespace std;
// ----------------------------------------------
//	�S�[���h�|�C���g�J�[�h�N���X�i�\�[�X�t�@�C���j
//	 �|�C���g���Z���A���Z�|�C���g�~1.5�{�ŉ��Z
//	 �� �����_�ȉ��̃|�C���g�͐؂�̂�
// ----------------------------------------------
GoldPointCard::GoldPointCard()
{
	setType(TYPE::Gold);
}

void GoldPointCard::addPoint(int var)
{
	point_ += static_cast<int>(var * 1.5f);
}