#pragma once
// =====================================================
//	�N���W�b�g�V�[���N���X�i�w�b�_�[�t�@�C���j
//	 ���ׂĂ̖��O������邩�A�X�y�[�X�L�[�Ń^�C�g����
// =====================================================
class SceneCredit :
	public SceneBase
{
private:
	FontManager* font_ = nullptr;
	
	// �N���W�b�g�ɕ\������郁�b�Z�[�W�֘A
	std::vector<std::string> messages_;
	int						 now_message_index_ = 0;

	// �\��
	const int	DISP_FRAME  = 60 * 2;
	const float ALPHA_SPEED = 0.05f;
		  int	disp_frame_ = 0;
		  float alpha_		= 255;
		  int	action_		= 1;


public:
	SceneCredit();
	virtual ~SceneCredit();

	bool update() override;
	void render() override;

};