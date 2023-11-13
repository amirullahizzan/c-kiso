#pragma once
#include "Person.h"

// ===============================================
//	�搶�N���X�i�w�b�_�[�t�@�C���j
//	 ���O�ƒS�����Ȃ̃����o�ϐ��Ƃ���ɑ΂���A
//	 getter�����o�֐�������
//	�܂��Aset�����o�֐����g�p���Ė��O�ƒS�����Ȗ���
//	�����̒l�������o�ϐ��ɑ�����邱�Ƃ��ł���
// ===============================================
class Teacher : public Person
{
private:
	const char* subject_ = nullptr;

public:
	void set(const char* name, const char* subject);

	// getter
	const char* getSubject() const
	{
		return subject_;
	}

};