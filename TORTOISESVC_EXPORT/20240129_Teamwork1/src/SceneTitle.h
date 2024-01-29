#pragma once
// =====================================================
//	�^�C�g���V�[���N���X�i�w�b�_�[�t�@�C���j
//	 Enter�L�[�����Ŏ��̃V�[���֐؂�ւ���
// =====================================================
class SceneTitle :
	public SceneBase
{
private:
	int   select_no_  = 0;	 // �J�[�\���ʒu
	int   select_max_ = 0;	 // �I���̍ő吔

	Pos   select_left_;		 // �J�[�\���̍����̉~
	Pos	  select_right_;	 // �J�[�\���̉E���̉~
	float select_count_ = 0; // �J�[�\�����ӂ�ӂ퓮�����߂̃J�E���g�p�ϐ�

	const int   MENU_NUM	= 2;
	const char* MENU_STR[2] = 
	{
		 " GAME "
		,"CREDIT"
	};
	const int MENU_START_Y   = 280;	// ���j���[�̍���
	const int MENU_FONT_SIZE = 32;	// ���j���[�̃t�H���g�T�C�Y


	const char* SCORE_FILE_NAME = "data/txt/score.txt";
	bool is_score_find_			= false;	// �X�R�A�̃t�@�C�������������ǂ����i�Ȃ���΁A���j���[��CREDIT��\�������Ȃ��j
	int  getScoreTxt();				// �n�C�X�R�A�擾����

public:
	SceneTitle();
	virtual ~SceneTitle();

	bool update() override;
	void render() override;

	SCENE getNext() const override;

};