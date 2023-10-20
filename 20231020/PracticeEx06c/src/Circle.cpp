#include "WinMain.h"
#include "Circle.h"

// --------------------------------------------------
//	�R���X�g���N�^
// --------------------------------------------------
Circle::Circle()
{

}

// --------------------------------------------------
//	�f�X�g���N�^
// --------------------------------------------------
Circle::~Circle()
{

}

// --------------------------------------------------
//	�����Z�b�g�A�b�v
//	 �o������1�񂾂��Ă�
//	 �� ���t���[���ĂԂƁA�F����W�����t���[���ς��
// --------------------------------------------------
void Circle::spawn()
{
	if (isSpawn())
	{
		// ���łɏo�����Ă���ꍇ�́A�ȉ��̏������s��Ȃ�
		return;
	}
	// �o������
	is_spawn_ = true;	// �o���t���O��true(�o��)�ɂ���
	currentbouncecount = 0; //Reset

	randforce = GetRand(8-3) + 3; //3~8
	maxbouncecount = GetRand(5 - 2) + 2; //2~5

	// �T�C�Y(���a)�̐ݒ�
	r_ = 15.0f + ((float)GetRand(5) * 5);	// ���a: 15, 20, 25, 30, 35, 40 �̂����ꂩ
	// ���W�̐ݒ�
	x_ = WINDOW_W / 2;		// X���W: ��ʒ��S
	y_ = WINDOW_H - r_ * 2;	// Y���W: ��ʉ���
	// �ڕW���W�iY�j�̐ݒ�
	target_y_ = r_ + (float)GetRand(WINDOW_H / 2 - (int)r_ * 3);	// ��ʂ̏㔼���Ń����_��

	// �F�̐ݒ�
	const unsigned int COLORS[] =
	{
		RED, GREEN, BLUE, PINK, WHITE
	};
	const int COLORS_NUM = sizeof(COLORS) / sizeof(*COLORS);
	color_ = COLORS[GetRand(COLORS_NUM - 1)];

	// ���Ɠ���������z����g�킸�ɂ���ꍇ
	//switch (GetRand(4))
	//{
	//case 0:	color_ = RED;	break;
	//case 1:	color_ = GREEN;	break;
	//case 2:	color_ = BLUE;	break;
	//case 3:	color_ = PINK;	break;
	//case 4:	color_ = WHITE;	break;
	//}

}

// --------------------------------------------------
//	�X�V�����֐�
//	 GameUpdate�֐����Ŗ��t���[���ĂԂ���
// --------------------------------------------------
void Circle::bounce()
{
	enum
	{
		right = 0,
		left = 1,
	};
	
		switch (dirstate_)
		{
		case right:
			x_ += randforce;
			if (x_ > WINDOW_W - r_)
			{
				currentbouncecount++;
				dirstate_ = 1;
			}
			break;
		case left:
			x_ -= randforce;
			if (x_ < 0 + r_)
			{
				currentbouncecount++;
				dirstate_ = 0;
			}
			break;
		}

	
}

void Circle::update()
{
	if (!isSpawn())
	{
		// �o�����Ă��Ȃ��ꍇ�́A�ȍ~�̏������s��Ȃ�
		return;
	}

	// Y���W��ڕW���W�ɋ߂Â���
	y_ += (target_y_ - y_) * 0.05f;
	// ���݈ʒu�ƖڕW�ʒu�̋�����10��菬�����Ȃ�����j��
	if (getDistance(x_, y_, x_, target_y_) < 10.0f)
	{
		bounce();
		if (currentbouncecount > maxbouncecount)
		{
			is_spawn_ = false;
		}
	}
}

// --------------------------------------------------
//	�`�揈���֐�
//	 GameDraw�֐����Ŗ��t���[���ĂԂ���
// --------------------------------------------------
void Circle::render()
{
	
	if (!isSpawn())
	{
		// �o�����Ă��Ȃ��ꍇ�́A�ȍ~�̏������s��Ȃ�
		return;
	}

	DrawCircleAA(x_, y_, r_, 32, color_);

	// Debug
	//printfDx("dist: %.2f\n", getDistance(x_, y_, x_, target_y_));
}

void Circle::debuglog()
{
	//render
	printfDx("rand : %d\n", randforce);
	printfDx("rand : %d\n", currentbouncecount);
	printfDx("rand : %d\n", maxbouncecount);

	printfDx("����������ƌ����܂��B");
}

// --------------------------------------------------
//	�o�����Ă��邩�ǂ����擾�p�֐�
//	 �o�����Ă���ꍇ�Atrue���Ԃ�A
//	 �o�����Ă��Ȃ��ꍇ�Afalse���Ԃ�
// --------------------------------------------------
bool Circle::isSpawn() const
{
	return is_spawn_;
}

//inherits a class
//anything can be redefined except protected
class Box :
public Circle
{
private :
	int color = 255;
public :

};