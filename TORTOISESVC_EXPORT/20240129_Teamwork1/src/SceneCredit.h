#pragma once
// =====================================================
//	クレジットシーンクラス（ヘッダーファイル）
//	 すべての名前が流れるか、スペースキーでタイトルへ
// =====================================================
class SceneCredit :
	public SceneBase
{
private:
	FontManager* font_ = nullptr;
	
	// クレジットに表示されるメッセージ関連
	std::vector<std::string> messages_;
	int						 now_message_index_ = 0;

	// 表示
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