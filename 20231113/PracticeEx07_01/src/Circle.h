#pragma once
#include "Object.h"

// ===============================================
//	�~�N���X�i�w�b�_�[�t�@�C���j
//	 X���W�AY���W�A���a�̃����o�ϐ���
//	 ���ꂼ��ɑ΂���getter�����o�֐�������
//	 �����o�ϐ���X���W�AY���W�A���a�ɒl��������A
//	 set�����o�֐�������
//	 �w�肳�ꂽ�͈͓��Ń����_���Ȑ��l���擾����A
//	 getRandNum�����o�֐�������
// ===============================================
class Circle : public Object
{
private:

	int r_ = 0;

public:
	void set(int x, int y, int r);

	// getter
	int getSize() const
	{
		return r_;
	}

};