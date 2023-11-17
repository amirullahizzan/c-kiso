#include "WinMain.h"
#include "ActorBase.h"
// -----------------------------------------------------
//	�L�����N�^�[���N���X�i�\�[�X�t�@�C���j
//	 �L�[���͂����ăA�j���[�V����������L�����N�^�[��
//	 �Ǘ�����N���X
// -----------------------------------------------------
// =====================================================
//	�`�揈��
// =====================================================
void ActorBase::render()
{
	Pos src_pos = 
	{
		AnimationOrderList[animation_index_] * IMG_SIZE, dir_ * IMG_SIZE
	};
	DrawRectRotaGraph(pos_.x, pos_.y,		// �`��ʒu
					  src_pos.x, src_pos.y,	// �摜�؂蔲���ʒu
					  IMG_SIZE, IMG_SIZE,
					  1, 0,
					  ghandle_, TRUE);
}
// =====================================================
//	�I������
// =====================================================
void ActorBase::exit()
{
	if (ghandle_ == -1)
		return;

	DeleteGraph(ghandle_);
}
// =====================================================
//	�A�j���[�V�����摜��t����
//	 �����͉摜�t�@�C�����ɂ���
//	 �摜�̓ǂݍ��݂Ɏ��s�����Ƃ���false��Ԃ�
// =====================================================
bool ActorBase::attachImage(const char* fname)
{
	// ���łɉ��炩�̉摜������ꍇ�͉摜�f�[�^��j������
	if (ghandle_ != -1)
	{
		DeleteGraph(ghandle_);
	}

	ghandle_ = LoadGraph(fname);

	return ghandle_ != -1;
}
// =====================================================
//	�A�j���[�V�����Đ�����
// =====================================================
void ActorBase::playAnimation()
{
	++animation_frame_;
	animation_frame_ %= AnimationSpeed;
	if (animation_frame_ == 0)
	{
		++animation_index_;
		animation_index_ %= AnimationOrderSize;
	}
}
