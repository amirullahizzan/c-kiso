#pragma once
// =====================================================
//	タイトルシーンクラス（ヘッダーファイル）
//	 Enterキー押下で次のシーンへ切り替える
// =====================================================
class SceneTitle :
	public SceneBase
{
private:
	int   select_no_  = 0;	 // カーソル位置
	int   select_max_ = 0;	 // 選択の最大数

	Pos   select_left_;		 // カーソルの左側の円
	Pos	  select_right_;	 // カーソルの右側の円
	float select_count_ = 0; // カーソルがふわふわ動くためのカウント用変数

	const int   MENU_NUM	= 2;
	const char* MENU_STR[2] = 
	{
		 " GAME "
		,"CREDIT"
	};
	const int MENU_START_Y   = 280;	// メニューの高さ
	const int MENU_FONT_SIZE = 32;	// メニューのフォントサイズ


	const char* SCORE_FILE_NAME = "data/txt/score.txt";
	bool is_score_find_			= false;	// スコアのファイルがあったかどうか（なければ、メニューのCREDITを表示させない）
	int  getScoreTxt();				// ハイスコア取得処理

public:
	SceneTitle();
	virtual ~SceneTitle();

	bool update() override;
	void render() override;

	SCENE getNext() const override;

};