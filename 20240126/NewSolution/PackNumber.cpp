#include "PackNumber.h"
#include <iostream>
#include <cassert>
using namespace std;
// --------------------------------------------------------
//	PackNumber�N���X�i�\�[�X�t�@�C���j
//	 �w�肳�ꂽ�T�C�Y�̔z����쐬���A
//	 ���̔z��ɐ��l��ۑ����Ă����N���X
// --------------------------------------------------------
///////////////////////////////////////////////////////////
//	�R���X�g���N�^
//	 ����:
//		���I�m�ۂ���z��̃T�C�Y
//	 ���e:
//		�����œn���ꂽ���l�Ŕz��𓮓I�Ɋm�ۂ���
///////////////////////////////////////////////////////////
PackNumber::PackNumber(int size) :
	SIZE(size)
{
	// �w�肳�ꂽ�T�C�Y��0�ȉ��̏ꍇ�̓G���[���o�͂����ăv���O�������I������
	assert(SIZE > 0);

	// SIZE���̔z����m��
	nums_ = new int[SIZE];
	// ���I�m�ۂɎ��s�����ꍇ�A����ȍ~�̏������s��Ȃ�
	if (nums_ == nullptr)
		return;

	// ���I�m�ۂ����z��̑S�Ă̗v�f�ɏ����l�Ƃ���0����
	for (int i = 0; i < SIZE; ++i)
	{
		nums_[i] = 0;
	}
}

///////////////////////////////////////////////////////////
//	�f�X�g���N�^
///////////////////////////////////////////////////////////
PackNumber::~PackNumber()
{
	delete[] nums_;
	nums_ = nullptr;
}

PackNumber::PackNumber(const PackNumber& other):
	SIZE(other.SIZE)
{
}

///////////////////////////////////////////////////////////
//	Set�֐�
//	 �߂�l:
//		�Ȃ�
//	 ����:
//		int i	  �c �z��̃C���f�b�N�X
//		int value �c �v�f�֑������l
//	 ���e:
//		���I�m�ۂ����z��unums_�v��i�Ԗڂ�value_��������
///////////////////////////////////////////////////////////
void PackNumber::Set(int i, int value)
{
	// �z��͈̔͊O�ɃA�N�Z�X���悤�Ƃ����ꍇ�A
	// ���������Ɋ֐����I������
	if (CheckIndex(i) == false)
		return;

	nums_[i] = value;
}

///////////////////////////////////////////////////////////
//	Get�֐�
//	 �߂�l:
//		���I�m�ۂ����z��unums_�v��i�Ԗڂ̗v�f
//	 ����:
//		int i	  �c �z��̃C���f�b�N�X
//	 ���e:
//		���I�m�ۂ����z��unums_�v��i�Ԗڂ̗v�f��Ԃ�
///////////////////////////////////////////////////////////
int PackNumber::Get(int i)const
{
	// �z��͈̔͊O�ɃA�N�Z�X���悤�Ƃ����ꍇ�A
	// �z��̍ŏ��̗v�f��Ԃ�
	if (CheckIndex(i) == false)
		return nums_[0];

	return nums_[i];
}

///////////////////////////////////////////////////////////
//	CheckIndex�֐�
//	 �߂�l:
//		true  �c ����i��0�ȏ�SIZE�����i�z��̃C���f�b�N�X�Ƃ��Đ���j
//		false �c ����i��0����SIZE�ȏ�i�z��̃C���f�b�N�X�Ƃ��ĕs���j
//	 ����:
//		int i	  �c �z��̃C���f�b�N�X
//	 ���e:
//		����i�����I�m�ۂ����z��unums_�v�̃C���f�b�N�X�Ƃ���
//		���킩�ǂ����𔻒f����
//		�i�z��I�[�o�[�t���[�̃`�F�b�N�j
///////////////////////////////////////////////////////////
bool PackNumber::CheckIndex(int i) const
{
	if (i < 0)
		return false;
	if (i >= SIZE)
		return false;

	return true;
}
