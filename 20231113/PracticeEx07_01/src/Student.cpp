#include <iostream>
#include "Student.h"
// ===============================================
//	�w���N���X�i�w�b�_�[�t�@�C���j
//	 ���O�Ɗw�Z���Ɗw�N�̃����o�ϐ��Ƃ���ɑ΂���A
//	 getter�����o�֐�������
//	 �܂��Aset�����o�֐����g�p���Ĉ����̒l��
//	 �����o�ϐ����O�Ɗw�Z���A�w�N�ɑ�����邱�Ƃ��ł���
// ===============================================
// �����̒l�������o�ϐ����O�Ɗw�Z���A�w�N�ɑ������
void Student::set(const char* name, const char* school, int year)
{
	name_	= name;
	school_ = school;
	year_	= year;
}
