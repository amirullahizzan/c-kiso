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

int main()
{
	srand((unsigned int)time(NULL));

	Account account[] = 
	{
		{ 0,"user1" }, { 0,"user2" }, { 0,"user3" }, { 0,"user4" }
	};

	for (int i = 0; i < 4; i++)
	{
		account[i].show();
	}

	cout << "\n�A�J�E���g��ID��U�蕪���܂�\n" << endl;

	for (int i = 0;i < 4;i++)
	{
		account[i].setId();
		account[i].show();
	}

	std::system("pause");
	return 0;
}

//ID:   0 / User : user1
//ID : 0 / User : user2
//ID : 0 / User : user3
//ID : 0 / User : user4
//
//�A�J�E���g��ID��U�蕪���܂�
//
//ID : 196 / User : user1
//ID : 133 / User : user2
//ID : 132 / User : user3
//ID : 114 / User : user4
//���s����ɂ͉����L�[�������Ă������� . . .
