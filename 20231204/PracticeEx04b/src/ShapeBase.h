#pragma once
// ------------------------------------------------
//	�}�`���N���X�i�w�b�_�[�t�@�C���j
//	 �l�X�Ȑ}�`�̋��ʕ��������̃N���X�ɐ錾�E��������
// ------------------------------------------------
class ShapeBase
{
private:


protected:
	Pos pos_;

public:
	virtual void init()   = 0;	// ����������
	virtual void update();		// �X�V����
	virtual void render() = 0;	// �`�揈��

	float getX() const
	{
		return pos_.x;
	}
	float getY() const
	{
		return pos_.y;
	}

	Pos* getPos()
	{
		return &pos_;
	}
};