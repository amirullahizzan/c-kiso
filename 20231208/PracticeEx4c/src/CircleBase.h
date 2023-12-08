#pragma once
// *************************************************************
//	�ҏW�֎~
// *************************************************************
// =====================================================
//	�~�̊��N���X�i�w�b�_�[�t�@�C���j
//	 ���ׂẲ~�̊�{�����Ǘ�����N���X
// =====================================================
class CircleBase
{
private:
	unsigned int  color_   = 0;		// �~�̐F
			 bool is_fill_ = false;	// �~��h��Ԃ�/�h��Ԃ��Ȃ�

protected:
	const ActorBase* target_ = nullptr;

	Pos	  pos_  = { WINDOW_W / 2, WINDOW_H / 2 };
	float size_ = 0;
	// �F�̕ύX���s��
	//	�h���N���X��update�֐��ŌĂԂ̂ŁAprotected�ɂ���
	void setColor(unsigned int color, bool is_fill = false)
	{
		color_ = color;
		is_fill_ = is_fill;
	}

public:
	CircleBase(float size);

	// �^�[�Q�b�g�ɂȂ�Ώە��̃A�h���X��ύX����
	//	�h���N���X�ł͂���target_�ɂ���A�h���X���g����
	//	�l�X�ȏ�������������
	void setTarget(const ActorBase* target)
	{
		target_ = target;
	}

	// ���W�̐ݒ�
	void setPos(const Pos& pos)
	{
		pos_ = pos;
	}
	// ���W���擾
	Pos getPos() const
	{
		return pos_;
	}

	virtual void update() {}
	virtual void render() final;

};