#include "../src/WinMain.h"
#include "Bullet.h"
// ============================================
//	 Bullet�N���X�i�\�[�X�t�@�C���j
//	  �e1��������
// ============================================
// �A�j���[�V�����̏���������
void Bullet::animationInit()
{
	animation_frame = 0;
	animation_x		= 0;
	animation_y		= 0;
}
// �A�j���[�V�����̉摜�̓ǂݍ��ݏ���
void Bullet::animationLoad(const char* fname_)
{
	// ���łɉ摜���ǂݍ��܂�Ă���ꍇ�ALoadGraph����O�ɉ摜��j������
	// ��������Ȃ��ƃ�������ɉ摜���c�葱���čŏI�I�ɃN���b�V������
	if (ghandle_ != -1)
	{
		animationExit();
	}

	ghandle_ = LoadGraph(fname_);
}
// �A�j���[�V�����̍X�V����
void Bullet::animationUpdate()
{
	++animation_frame;
	animation_frame %= 3;
	if (animation_frame == 0)
	{
		++animation_x;
		animation_x %= ANIMATION_W_MAX;
		if (animation_x != 0)
			return;

		++animation_y;
		if (animation_y >= ANIMATION_H_MAX)
		{
			animation_y = ANIMATION_H_MAX;
		}
	}
}
// �A�j���[�V�����̏I������
void Bullet::animationExit()
{
	DeleteGraph(ghandle_);
}

// �R���X�g���N�^
Bullet::Bullet()
{
}

// �f�X�g���N�^
Bullet::~Bullet()
{
}

// �����������֐�
//	GameInit�֐�����1�񂾂��Ă�
//	�܂��́A�Q�[�������Z�b�g����ۂ�exit�����o�֐����Ă񂾌�ɌĂяo����
//	�I�u�W�F�N�g��������Ԃɖ߂��ۂɌĂ�
void Bullet::init()
{
	// �摜�̓ǂݍ���
	animationLoad("data/bullet_red.png");
	// �����l�̃Z�b�g
	r_ = (120 * (float)EX_RATE) / 2.0f;
	// �����ʒu�̃Z�b�g
	pos_ = Pos2((float)WINDOW_W / 2, (float)WINDOW_H - r_ * 2);
	// ���ˏ�Ԃ��u�����ˁv�ɂ���
	is_shot_ = false;
}

// �X�V�����֐�
//	GameUpdate�֐����Ŗ��t���[���Ă�
void Bullet::update()
{
	if (!isShot())
		return;

	animationUpdate();

	pos_.y = pos_.y - 8;
	if (getY() < -getR())
	{
		setErase();
	}

}

// �`�揈���֐�
//	GameDraw�֐����Ŗ��t���[���Ă�
//	���̊֐����ł̓����o�ϐ���ύX���Ȃ��̂ŁAconst�t�������o�֐��Ƃ���
void Bullet::render() const
{
	if (!isShot())
		return;

	DrawRectRotaGraph((int)getX(), (int)getY(),
					  IMG_SIZE_W * getAnimationX(), IMG_SIZE_H * getAnimationY(),
					  IMG_SIZE_W, IMG_SIZE_H,
					  EX_RATE, 0, ghandle_, TRUE);
}

// �I�������֐�
//	GameExit�֐�����1�񂾂��Ă�
//	�܂��́A�Q�[�������Z�b�g����ۂ�init�����o�֐����ĂԑO�ɌĂяo����
//	�I�u�W�F�N�g��������Ԃɖ߂��ۂɌĂ�
void Bullet::exit()
{
	animationExit();

}
