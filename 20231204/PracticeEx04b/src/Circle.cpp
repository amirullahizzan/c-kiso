#include "WinMain.h"
#include "ShapeBase.h"
#include "Circle.h"
// ------------------------------------------------
//	�}�`�u�~�v�N���X�i�\�[�X�t�@�C���j
//	 ���E�L�[�ňړ��E�~��`�悷��N���X
// ------------------------------------------------
// ================================
//	����������
// ================================
void Circle::init()
{
	pos_ = { WINDOW_W / 2, (float)(WINDOW_H - R - 10) };
}

// ================================
//	�X�V����
// ================================
void Circle::update()
{
	if (IsKeyRepeat(KEY_INPUT_LEFT))
	{
		pos_.x -= SPEED;
	}
	if (IsKeyRepeat(KEY_INPUT_RIGHT))
	{
		pos_.x += SPEED;
	}

	fitWindowW();
}

// ================================
//	�`�揈��
// ================================
void Circle::render()
{
	DrawCircleAA(pos_.x, pos_.y, R, 64, PINK, TRUE);

}

// ================================
//	��ʊO�ɍs���Ȃ��悤�ɂ���iX���W�j
// ================================
void Circle::fitWindowW()
{
	if (pos_.x > WINDOW_W - R)
	{
		pos_.x = WINDOW_W - R;
	}
	if (pos_.x < 0 + R)
	{
		pos_.x = 0 + R;
	}
}
