#pragma once
#include "Object.h"
// ===============================================
//	�����`�N���X�i�w�b�_�[�t�@�C���j
//	 X���W�AY���W�A���A�����̃����o�ϐ���
//	 ���ꂼ��ɑ΂���getter�����o�֐�������
//	 �����o�ϐ���X���W�AY���W�A���A�����Ɉ����̒l��������A
//	 set�����o�֐�������
//	 �w�肳�ꂽ�͈͓��Ń����_���Ȑ��l���擾����A
//	 getRandNum�����o�֐�������
// ===============================================
class Square : public Object
{
private:

	int w_ = 0;
	int h_ = 0;

public:
	void set(int x, int y, int w);

	// getter

	int getSize() const
	{
		// �����`�Ȃ̂ŕ��E�����ǂ����Ԃ��Ă�����
		return w_;
	}


};