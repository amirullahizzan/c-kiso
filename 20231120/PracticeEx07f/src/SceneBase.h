#pragma once
// =============================================
//	�S�V�[���̊��N���X�i�w�b�_�[�t�@�C���j
//	  �S�V�[���̋��ʂ��镔��������N���X
// =============================================
class SceneBase
{
private:
	bool  is_next_ = false;
	float alpha_   = 0;

protected:
	virtual void updateBody();
	virtual void renderBody();

	// �V�[���I�����ɂ��̃����o���ĂԂ�
	// �t�F�[�h�A�E�g���s���A�V�[�����؂�ւ��
	void setSceneEnd()
	{
		is_next_ = true;
	}

public:
	virtual void init();
	bool update();
	void render();
	void exit();

};



