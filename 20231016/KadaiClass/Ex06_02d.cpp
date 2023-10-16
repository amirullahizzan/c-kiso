// Book�N���X��getSaleNum�����o�֐����g�p���āA
// �ł����ꂽ�{��T���v���O���������������Ă��������B
#include <iostream>
using namespace std;

// --------------------------------------------------
//	��������ҏW�֎~
class Book
{
private:
	const char* title_		 = nullptr;	// �^�C�g��
	const char* author_name_ = nullptr;	// ���Җ�
		  int	year_		 = 0;		// ������(�N)
		  int   sale_num_	 = 0;		// �̔�����

public:
	// �����o�ϐ��Ƀf�[�^��n���ď���������֐�
	//	�^�C�g���A���Җ��A���������w������ɗ^����
	void init(const char* title, const char* author_name, int year, int sale_num);
	// �̔��������擾����֐�
	int  getSaleNum();
	// �{�̏����o�͂���֐�
	void show();
};

// �����o�ϐ��Ƀf�[�^��n���ď���������֐�
//	�^�C�g���A���Җ��A���������w������ɗ^����
void Book::init(const char* title, const char* author_name, int year, int sale_num)
{
	title_		 = title;
	author_name_ = author_name;
	year_		 = year;
	sale_num_	 = sale_num;
}
// �̔��������擾����֐�
int Book::getSaleNum()
{
	return sale_num_;
}
// �{�̏����o�͂���֐�
void Book::show()
{
	printf_s("%s/%s ������: %d�N(%d����)\n",
			 title_, author_name_, year_, sale_num_);
}
//	�����܂ŕҏW�֎~
// --------------------------------------------------

int main()
{
	static int i;
	std::cout << i << endl;
	Book book[] = { {}, {}, {} };
	//Book book[3] = { };

	std::cout << "�n���[�|�b�^�[�V���[�Y�ōł����ꂽ�^�C�g���́A" << endl;

	book[0].init("�n���[�|�b�^�[�ƌ��҂̐�", "J.K.���[�����O", 1999, 508);
	book[1].init("�n���[�|�b�^�[��Half blood prince", "J.K.���[�����O", 2009, 208);
	book[2].init("�n���[�|�b�^�[��Yamada taro", "J.K.���[�����O", 2009, 5555);

	int highest = 0;
	int highestindex = 0;
	for (int i = 0;i<3;i++)
	{
		if (book[i].getSaleNum() >= highest)
		{
			highest = book[i].getSaleNum();
		}
	}

	for(int i = 0 ; i < 3 ; i++)
	{

	if (book[i].getSaleNum() == highest)
	{
	book[i].show();
	}

	}

	std::system("pause");
	return 0;
}