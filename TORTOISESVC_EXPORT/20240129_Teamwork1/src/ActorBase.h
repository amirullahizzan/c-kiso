#pragma once
// =====================================================
//	�A�j���[�V�����L�����N�^�[�Ǘ��N���X�i�w�b�_�[�t�@�C���j
//	 �Q�[�����̃A�j���[�V����������L�����N�^�[�̊��N���X
// =====================================================
class ActorBase
{
private:
	AnimationImage* anim_	   = nullptr;
	bool			anim_play_ = false;

protected:
	Pos	   pos_	  = { 0, 0 };	// ���W
	DIR	   dir_	  = DIR::DOWN;	// ����
	double scale_ = 1.0;		// �g�k��
	double angle_ = 0;			// ��]�p�x�i�x�Ŏw��j

	virtual void updateBody() = 0;

	// �A�j���[�V�����Đ������ǂ���
	bool isAnimPlay() const
	{
		return anim_play_;
	}
	// �A�j���[�V�����Đ�
	void animPlay()
	{
		anim_play_ = true;
	}
	// �A�j���[�V������~
	void animStop()
	{
		anim_play_ = false;
		anim_->reset();
	}

public:
	ActorBase(std::string img_path, int anim_speed = 20);
	virtual ~ActorBase();

			void update();
	virtual void render();

	const Pos& getPos() const
	{
		return pos_;
	}
	const DIR& getDir() const
	{
		return dir_;
	}
	// �T�C�Y�̎擾
	const float getSize() const
	{
		return (float)(IMG_SIZE * scale_);
	}
	// ���a�̎擾
	const float getR() const
	{
		return getSize() / 2;
	}
	// �����ɓ�������
	virtual void onHit(std::string tag);

};