#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "CircleBase.h"
#include "CircleScaling.h"
// =====================================================
//	�g�k����~�N���X�i�\�[�X�t�@�C���j
//	 �g��k������~
// =====================================================
// -----------------------------------------------------
//	�R���X�g���N�^
//	 �I�u�W�F�N�g��錾���ɉ~�̍ő�l�����߂���
//	 �w�肪�Ȃ���΁A�f�t�H���g�����ɂ���50���g�p�����
// -----------------------------------------------------
CircleScaling::CircleScaling(float size) :
	CircleBase(size),
	MAX_SIZE(size)
{

}

// -----------------------------------------------------
//	�X�V����
// -----------------------------------------------------
void CircleScaling::update()
{
	setColor(SKYBLUE);

	if (target_ != nullptr)
	{
		pos_ = target_->getPos();
	}

	++angle_;
	size_ = sinf(PI / 2 / 60 * angle_) * MAX_SIZE;
}

