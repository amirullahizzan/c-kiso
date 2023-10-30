#include "../src/WinMain.h"
#include "Player.h"
// ============================================
//	 Player�N���X�i�\�[�X�t�@�C���j
//	  �L�[����ł̈ړ����s��
// ============================================
// �R���X�g���N�^
Player::Player()
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// �����������֐�
//	GameInit�֐�����1�񂾂��Ă�
//	�܂��́A�Q�[�������Z�b�g����ۂ�exit�����o�֐����Ă񂾌�ɌĂяo����
//	�I�u�W�F�N�g��������Ԃɖ߂��ۂɌĂ�
void Player::init()
{
	// �摜�̓ǂݍ���
	ghandle_ = LoadGraph("data/red.png");
	// �����l�̃Z�b�g
	r_ = IMG_SIZE / 2;	// �����蔻��p�ɕK�v�Ȕ��a�̒l���Z�b�g
	// �����ʒu�̃Z�b�g
	pos_ = Pos2((float)WINDOW_W / 2, (float)WINDOW_H - r_ * 2);

	damage_frame_ = 0;
}

// �X�V�����֐�
//	GameUpdate�֐����Ŗ��t���[���Ă�
void Player::update()
{
	if (damage_frame_ > 0)
	{
		--damage_frame_;
	}

	// �㉺���E�̖��L�[�ňړ�
	if (IsKeyRepeat(KEY_INPUT_RIGHT))
	{
		pos_.x += 5;
	}
	if (IsKeyRepeat(KEY_INPUT_LEFT))
	{
		pos_.x -= 5;
	}
	if (IsKeyRepeat(KEY_INPUT_DOWN))
	{
		pos_.y += 5;
	}
	if (IsKeyRepeat(KEY_INPUT_UP))
	{
		pos_.y -= 5;
	}

	// ��ʔ͈͊O�ɍs���Ȃ��悤�ɂ��鏈��
	//	�����o�ϐ��̒l���Q�Ƃ��鎞�ɂ͂Ȃ�ׂ������o�֐����g�p����
	if (getX() < getR())
	{
		pos_.x = getR();
	}
	if (getY() < getR())
	{
		pos_.y = getR();
	}
	if (getX() > WINDOW_W - getR())
	{
		pos_.x = WINDOW_W - getR();
	}
	if (getY() > WINDOW_H - getR())
	{
		pos_.y = WINDOW_H - getR();
	}
}

// �`�揈���֐�
//	GameDraw�֐����Ŗ��t���[���Ă�
//	���̊֐����ł̓����o�ϐ���ύX���Ȃ��̂ŁAconst�t�������o�֐��Ƃ���
void Player::render() const
{
	if (damage_frame_ % 3 != 0)
		return;

	// DrawGraph�֐� �c �摜������W
	// DrawRotaGraph�֐� �c �摜���S���W(�����蔻��̌v�Z�ケ������g�p����)
	DrawRotaGraphF(getX(), getY(), EX_RATE, 0, ghandle_, TRUE);
}

// �I�������֐�
//	GameExit�֐�����1�񂾂��Ă�
//	�܂��́A�Q�[�������Z�b�g����ۂ�init�����o�֐����ĂԑO�ɌĂяo����
//	�I�u�W�F�N�g��������Ԃɖ߂��ۂɌĂ�
void Player::exit()
{
	// �g�p�����摜�̍폜
	DeleteGraph(ghandle_);
}

// �_���[�W�̕t��
void Player::setDamage()
{
	if (damage_frame_ > 0)
		return;

	damage_frame_ = (int)(60 * 1.5f);
}
