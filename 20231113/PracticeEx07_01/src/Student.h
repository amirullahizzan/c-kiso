#pragma once
#include "Person.h"
// ===============================================
//	�w���N���X�i�w�b�_�[�t�@�C���j
//	 ���O�Ɗw�Z���Ɗw�N�̃����o�ϐ��Ƃ���ɑ΂���A
//	 getter�����o�֐�������
//	 �܂��Aset�����o�֐����g�p���Ĉ����̒l��
//	 �����o�ϐ����O�Ɗw�Z���A�w�N�ɑ�����邱�Ƃ��ł���
// ===============================================
class Student : public Person
{
private:
	const char* school_ = nullptr;
	int			year_	= 0;

public:
	void set(const char* name, const char* school, int year);

	// getter
	const char* getSchool() const
	{
		return school_;
	}
	int getYear() const
	{
		return year_;
	}

};