#pragma once
// *************************************************************
//	�ҏW�֎~
// *************************************************************
// =====================================================
//	�A�j���[�V�����L�����N�^�[�N���X�i�w�b�_�[�t�@�C���j
//	 �A�j���[�V��������L�����N�^�[���Ǘ�����N���X
// =====================================================
class ActorBase
{
private:
	AnimationImage* anim_ = nullptr;	// �A�j���[�V����
	bool is_target_		  = false;		// ���݃^�[�Q�b�g���ǂ���

protected:
	Pos pos_ = { 0, 0 };	// ���W
	DIR dir_ = DIR::DOWN;	// ����

	virtual void updateBody() = 0;	// �X�V�����{��

public:
	virtual ~ActorBase();

	virtual void init(const char* fname); // ����������
	virtual void update() final;		  // �X�V�����i�I�[�o�[���C�h�s�j
	virtual void render();				  // �`�揈��
	virtual void exit() final;			  // �I�������i�I�[�o�[���C�h�s�j

	// ���W�̐ݒ�
	void setPos(const Pos& pos)
	{
		pos_ = pos;
	}
	// ���W�̎擾
	Pos getPos() const
	{
		return pos_;
	}
	// �^�[�Q�b�g�ł�
	void setTarget()
	{
		is_target_ = true;
	}
	// �^�[�Q�b�g�ł͂Ȃ��ł�
	void unsetTarget()
	{
		is_target_ = false;
	}

};
