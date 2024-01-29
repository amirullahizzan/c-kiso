#pragma once
// =====================================================
//	ゲームメインシーンクラス（ヘッダーファイル）
//	 プレイヤーのHPがなくなるまで耐える
// =====================================================
class SceneGameMain :
	public SceneBase
{
private:
	// UI用
	FontManager*   font_ = nullptr;
	AnimationImage player_hp_anim_;
	void updateUI();
	void renderUI();

	Player*		  player_	 = nullptr;
	EnemyManager* enemy_mgr_ = nullptr;


	// ゲーム終了用
	bool is_game_end_		  = false;
	bool is_end_message_disp_ = false;
	int  flash_count_		  = 0;		// キー入力誘導メッセージ点滅用
	bool updateGameEnd();
	void renderGameEnd();

	// ハイスコア用
	const char* SCORE_FILE_NAME = "data/txt/score.txt";
	int  high_score_ = -1;
	int  getScoreTxt();		// ハイスコア取得処理
	void updateScoreTxt();	// ハイスコア上書き処理


public:
	SceneGameMain();
	virtual ~SceneGameMain();

	bool update() override;
	void render() override;

	SCENE getNext() const override;

};
