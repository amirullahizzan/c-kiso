#pragma once
// ============================================
//	 Bullet�N���X�i�w�b�_�[�t�@�C���j
//	  �e1��������
// ============================================
class Bullet
{
private:
	const double EX_RATE = 0.1;		// �摜�g�嗦

	const int IMG_SIZE_W	  = 120;// �摜���i�G�ЂƂ��j
	const int IMG_SIZE_H	  = 120;// �摜�����i�G�ЂƂ��j
	const int ANIMATION_W_MAX = 4;	// �A�j���[�V���� ���̍ő吔
	const int ANIMATION_H_MAX = 3;	// �A�j���[�V���� �c�̍ő吔

	Pos2  pos_;								// ���W
	float r_	   = 120 * (float)EX_RATE;	// �T�C�Y
	bool  is_shot_ = false;					// ���˂������ǂ���

	/////////////////////////
	//	�A�j���[�V�����֌W
	/////////////////////////
	int	ghandle_		= -1;	// �摜
	int animation_frame = 0;	// �A�j���[�V�����o�ߎ���
	int	animation_x		= 0;	// �A�j���[�V����X
	int animation_y		= 0;	// �A�j���[�V����Y
	
	void animationInit();					// �A�j���[�V�����̏���������
	void animationLoad(const char* fname_);	// �A�j���[�V�����̉摜�̓ǂݍ��ݏ���
	void animationUpdate();					// �A�j���[�V�����̍X�V����
	void animationExit();					// �A�j���[�V�����̏I������
	int  getAnimationX() const
	{
		return animation_x;
	}
	int  getAnimationY() const
	{
		return animation_y;
	}

public:
	// ------------------------
	// �R���X�g���N�^�E�f�X�g���N�^
	// ------------------------
	Bullet();
	~Bullet();

	// ------------------------
	// �����o�֐�
	// ------------------------
	void init();			// �����������֐�
	void update();			// �X�V�����֐�
	void render() const;	// �`�揈���֐�
	void exit();			// �I�������֐�
	
	// �e�������Ă����Ԃ��ǂ���
	bool isShot() const
	{
		return is_shot_;
	}
	// �o������
	void setShot(const Pos2& pos)
	{
		if (isShot())
			return;

		pos_ = pos;
		is_shot_ = true;
		animationInit();
	}
	// ��������
	void setErase()
	{
		is_shot_ = false;
	}

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

	//CUSTOM
};