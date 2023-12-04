#include "WinMain.h"
#include "ShapeBase.h"
#include "Box.h"
// ------------------------------------------------
//	�}�`�u�l�p�v�N���X�i�w�b�_�[�t�@�C���j
//	 �~�N���X��Ǐ]����N���X
// ------------------------------------------------
// ================================
//	����������
// ================================
void Box::init()
{
	pos_ = { WINDOW_W / 2, (float)(H + 10) };
}

// ================================
//	�`�揈��
// ================================
void Box::render()
{
	DrawBoxAA(pos_.x - W / 2, pos_.y - H / 2,	// ����
			  pos_.x + W / 2, pos_.y + H / 2,	// �E��
			  SKYBLUE, TRUE);

	// for Debug
	// �l�p��pos_�͎l�p�̒��S���W�ɂ��Ă��邽�߁A
	// �f�o�b�O�Œ��S�ʒu�ɉ~��`��
	DrawCircleAA(pos_.x, pos_.y, 5, 64, RED, TRUE);
}

void Box::update()
{
	pos_.x = _circlepos_ptr->x;
}
