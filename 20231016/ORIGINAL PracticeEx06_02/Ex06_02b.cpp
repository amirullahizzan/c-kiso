// Account�N���X��setId�֐����g�p���āA
// �A�J�E���g��ID�𔭍s����v���O���������������Ă��������B
#include <iostream>
#include <ctime>
using namespace std;

// --------------------------------------------------
//	��������ҏW�֎~
class Account
{
public:
	// �����o�ϐ�
		  int	id_		   = 0;			// ID
	const char* user_name_ = nullptr;	// ���[�U�[��

	// �����o�֐�
	void setId();	// ID�̐ݒ�
	void show();	// �A�J�E���g���̏o��
};
// ID�̐ݒ�
//	100 �` 200 �܂ł̗�����id_�Ɋ���U��
void Account::setId()
{
	id_ = 100 + rand() % 101;
}
// �A�J�E���g���̏o��
//	�uID: xxxx / User: xxxx�v�̌`���ŏo�͂���
void Account::show()
{
	printf_s("ID: %3d / User: %s\n", id_, user_name_);
}
//	�����܂ŕҏW�֎~
// --------------------------------------------------
