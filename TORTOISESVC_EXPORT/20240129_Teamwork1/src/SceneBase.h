#pragma once
// =====================================================
//	�S�ẴV�[���̊��N���X�i�w�b�_�[�t�@�C���j
//	 �e�V�[���ł�update��render���I�[�o�[���C�h����
// =====================================================
class SceneBase
{
private:
	const std::string name_;

protected:

public:
	SceneBase(std::string name);	// �R���X�g���N�^
	virtual ~SceneBase();			// �f�X�g���N�^

	virtual bool update() = 0;		// �X�V�����i�V�[�����I���^�C�~���O��true��Ԃ��j
	virtual void render();			// �`�揈��

	virtual SCENE getNext() const;	// ���̃V�[���̔ԍ���Ԃ�

};