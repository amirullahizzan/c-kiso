#pragma once
// =====================================================
//	�Q�[�����C���V�[���N���X�i�w�b�_�[�t�@�C���j
//	 �v���C���[��HP���Ȃ��Ȃ�܂őς���
// =====================================================
class SceneGameMain :
	public SceneBase
{
private:
	// UI�p
	FontManager*   font_ = nullptr;
	AnimationImage player_hp_anim_;
	void updateUI();
	void renderUI();

	Player*		  player_	 = nullptr;
	EnemyManager* enemy_mgr_ = nullptr;


	// �Q�[���I���p
	bool is_game_end_		  = false;
	bool is_end_message_disp_ = false;
	int  flash_count_		  = 0;		// �L�[���͗U�����b�Z�[�W�_�ŗp
	bool updateGameEnd();
	void renderGameEnd();

	// �n�C�X�R�A�p
	const char* SCORE_FILE_NAME = "data/txt/score.txt";
	int  high_score_ = -1;
	int  getScoreTxt();		// �n�C�X�R�A�擾����
	void updateScoreTxt();	// �n�C�X�R�A�㏑������


public:
	SceneGameMain();
	virtual ~SceneGameMain();

	bool update() override;
	void render() override;

	SCENE getNext() const override;

};
