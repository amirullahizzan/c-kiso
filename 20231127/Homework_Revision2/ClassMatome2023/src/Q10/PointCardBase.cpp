#include <iostream>
#include "PointCardBase.h"
using namespace std;
// ----------------------------------------------
//	�|�C���g�J�[�h���N���X�i�\�[�X�t�@�C���j
//	 �l�X�Ȏ�ނ̃|�C���g�J�[�h�̊��N���X
// ----------------------------------------------
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
namespace
{
	const char* CARD_STR[PointCardBase::TYPE::MAX] =
	{
		"�Ȃ�", "�S�[���h���", "�V���o�[���"
	};

}
// �|�C���g�J�[�h�̎�ʂ�ݒ�
void PointCardBase::setType(TYPE type)
{
	type_ = type;
}
// �J�[�h���̕`��
void PointCardBase::render()
{
	printf_s("[%s]: %d\n", CARD_STR[type_], point_);
}
// ���Z�q�u+=�v�̃I�[�o�[���[�h
void PointCardBase::operator+=(int var)
{
	addPoint(var);
}
