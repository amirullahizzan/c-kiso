#pragma once
// -----------------------------------------------------
//	�L�����N�^�[���N���X�i�w�b�_�[�t�@�C���j
//	 �L�[���͂����ăA�j���[�V����������L�����N�^�[��
//	 �Ǘ�����N���X
// -----------------------------------------------------
class ActorBase
{
public:
	void render();						 // �`�揈��
	void exit();						 // �I������

	virtual void init()
	{

	}		// ����������
	virtual void update()
	{
		playAnimation();
		Move();
		posReset();
	}	// �X�V����
	virtual void posReset()
	{
	
	}

protected:
	virtual void Move()
	{

	}

	Pos pos_;							 // ���W
	DIR dir_	 = DIR::DOWN;			 // ����
	int ghandle_ = -1;					 // �A�j���[�V�����摜

	void playAnimation();				 // �A�j���[�V�����Đ��p
	bool attachImage(const char* fname); // �A�j���[�V�����摜��t����

	int GetRandomTimer()
	{
		return GetRand(80)+80;
	}


private:
	// ==================================
	//	 �A�j���[�V���������p�萔�ꗗ
	// ==================================
	//	�摜�؂蔲�����Ԃ̈ꗗ
	const int AnimationOrderList[4] =
	{
		1, 0, 1, 2
	};
	//	�摜�؂蔲�����Ԃ̈ꗗ�z��̃T�C�Y
	const int AnimationOrderSize = sizeof(AnimationOrderList) / sizeof(*AnimationOrderList);
	//	�A�j���[�V�������x
	const int AnimationSpeed = 10;

	int animation_frame_ = 0;	// �A�j���[�V�����J�E���^�[
	int animation_index_ = 0;	// �A�j���[�V��������

};	// class ActorBase
