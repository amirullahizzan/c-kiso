// Rect�N���X��setSize�֐�, getW�֐�, getH�֐����g�p���āA
// 2�̒����`�̖ʐς����߂āA�ǂ��炪�傫���̂��i�������͓����T�C�Y�Ȃ̂��j��
// �o�͂���v���O���������������Ă��������B
// �Ȃ��A�����`�̃T�C�Y�͈ȉ��̒ʂ�ł��B
// 1�ڂ̒����`: ��/10, 20, 30, 40, 50�̗���, ����/20
// 2�ڂ̒����`: ��/20, 50�̗���, ����/10, 20, 30, 40, 50�̗���
#include <iostream>
#include <ctime>
using namespace std;

// --------------------------------------------------
//	��������ҏW�֎~
class Rect
{
private:
	int width_  = 0;	// ��
	int height_ = 0;	// ����

public:
	// �����`�̃T�C�Y��ݒ肷��֐�
	//	���ƍ����������ɓn���āA�����o�ϐ��ɒl��������
	void setSize(int w, int h);
	// �����擾����
	int getW();
	// �������擾����
	int getH();

};

// ���ƍ����������ɓn���āA�����o�ϐ��ɒl��������
void Rect::setSize(int w, int h)
{
	width_  = w;
	height_ = h;
}

// �����擾����
int Rect::getW()
{
	return width_;
}

// �������擾����
int Rect::getH()
{
	return height_;
}
//	�����܂ŕҏW�֎~
// --------------------------------------------------

int main()
{

	srand((unsigned int)time(NULL));

	Rect rect1;
	rect1.setSize(rand() % (5)  * 10 + 10,
								   20);
	
	Rect rect2;

	{
		int randomsize2 = rand() % 2;
		rect2.setSize(randomsize2 == 0 ? 20 : 50 , rand() % (5) * 10 + 10);
		//cout << randomsize2 << "=========";
	}

	cout << "�� : " << rect1.getW() << " / ";
	cout << " ���� : " << rect1.getH();
	cout << " �̎l�p1��";
	cout << "�� : " << rect2.getW() << " / ";
	cout << " ���� : " << rect2.getH();
	cout << " �̎l�p2�ł́A" << endl;

	int size1 = rect1.getW() * rect1.getH();
	int size2 = rect2.getW() * rect2.getH();
	//�ʐ�

	//cout << "�l�p" << ((size1 < size2 && size1 != size2) ? "2�̂ق����傫���ł�" : "1�̂ق����傫���ł�") << (size1 == size2 ? "�����̑傫���͓����ł�" : "") 
	//	 << endl;
	cout << "�l�p" << (
						(size1 == size2 ? 
						"�����̑傫���͓����ł�" : (size1 < size2 && size1 != size2 ? "2�̂ق����傫���ł�" : "1�̂ق����傫���ł�")
						) 
					  )
		 << endl;

	std::system("pause");
	return 0;
}
