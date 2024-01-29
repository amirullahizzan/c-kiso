#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
// =====================================================
//	�A�j���[�V�����L�����N�^�[�Ǘ��N���X�i�w�b�_�[�t�@�C���j
//	 �Q�[�����̃A�j���[�V����������L�����N�^�[�̊��N���X
// =====================================================
// �R���X�g���N�^
//	�摜�̃p�X���w�肷��
ActorBase::ActorBase(std::string img_path, int anim_speed)
{
	anim_ = new AnimationImage();
	anim_->load(img_path.c_str());
	anim_->attach({ {1, 0, 1, 2}, anim_speed, true });
	animPlay();

}

// �f�X�g���N�^
ActorBase::~ActorBase()
{
	delete anim_;
	anim_ = nullptr;

}

// �X�V����
void ActorBase::update()
{
	assert(anim_ != nullptr);
	if (isAnimPlay())
	{
		anim_->update();
	}

	updateBody();
}

// �`�揈��
void ActorBase::render()
{
	DrawRectRotaGraphF(getPos().x, getPos().y,
					   anim_->get() * IMG_SIZE,
					   getDir() * IMG_SIZE,
					   IMG_SIZE, IMG_SIZE,
					   scale_, D2R(angle_),
					   anim_->getGhandle(),
					   TRUE);

#ifndef NDEBUG
	DrawCircleAA(getPos().x, getPos().y, getR(), 32, RED, FALSE);
#endif // !NDEBUG

}

// �����ɓ�������
void ActorBase::onHit(std::string tag)
{
	// �����ł͉������Ȃ�
}
