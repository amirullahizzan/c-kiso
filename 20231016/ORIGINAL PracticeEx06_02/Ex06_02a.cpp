// Person�N���X�̃I�u�W�F�N�g���g�p���āA
// ���D�u�L���ˏ��v����̔N������o�͂���v���O���������������Ă��������B
#include <iostream>
using namespace std;

// --------------------------------------------------
//	��������ҏW�֎~
class Person
{
public:
	const char* name = nullptr;	// ���O
		  int   age	 = 0;		// �N��

	void show();				// ���O�ƔN����u���O(�N��)�v�̌`���ŏo��
};
// ���O�ƔN����u���O(�N��)�v�̌`���ŏo��
void Person::show()
{
	printf_s("%s(%d)\n", name, age);
}
//	�����܂ŕҏW�֎~
// --------------------------------------------------

