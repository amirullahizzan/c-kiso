#pragma once
// ============================================
//	 Player�N���X�i�w�b�_�[�t�@�C���j
//	  �L�[����ł̈ړ����s��
// ============================================
class Player
{
protected:
	//like public but accessible by Derived
	Pos2  pos_;			// ���W
	int   ghandle_ = 0;	// �摜
	float r_	   = 0;	// ���a
	const double EX_RATE = 1.0;	// �摜�g�嗦

private:
	

	int     damage_frame_ = 0;	// �_���[�W���Ԃ̌v��

public:
	// ------------------------
	// �R���X�g���N�^�E�f�X�g���N�^
	// ------------------------
	Player();
	~Player();

	// ------------------------
	// �����o�֐�
	// ------------------------
	void init();			// �����������֐�
	void update();			// �X�V�����֐�
	void render() const;	// �`�揈���֐�
	void exit();			// �I�������֐�

	void setDamage();		// �_���[�W������t��

	// ------------------------
	//	�����o�ϐ�getter�֐�
	// ------------------------
	const Pos2& getPos() const
	{
		return pos_;
	}
	float getX()		 const
	{
		return pos_.x;
	}
	float getY()		 const
	{
		return pos_.y;
	}
	float getR()		 const
	{
		return r_;
	}

};