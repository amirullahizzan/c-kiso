#include <iostream>
#include "Teacher.h"
// ===============================================
//	�搶�N���X�i�\�[�X�t�@�C���j
//	 ���O�ƒS�����Ȃ̃����o�ϐ��Ƃ���ɑ΂���A
//	 getter�����o�֐�������
//	�܂��Aset�����o�֐����g�p���Ė��O�ƒS�����Ȗ���
//	�����̒l�������o�ϐ��ɑ�����邱�Ƃ��ł���
// ===============================================
// �����̒l�������o�ϐ��uname_�v�A�usubject_�v�ɑ������
void Teacher::set(const char* name, const char* subject)
{
	name_	 = name;
	subject_ = subject;
}
