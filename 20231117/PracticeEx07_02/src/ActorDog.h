#pragma once
// -----------------------------------------------------
//	���N���X�i�w�b�_�[�t�@�C���j
//	 �L�[���͂ňړ�����L�����N�^�[�N���X
// -----------------------------------------------------
class ActorDog : public ActorBase
{
private:
	void posReset();			// ���W����

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

public:
	void init() override;		// ����������
	void update()override;	// �X�V����

};