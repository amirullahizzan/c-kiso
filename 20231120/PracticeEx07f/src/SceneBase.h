#pragma once
// =============================================
//	全シーンの基底クラス（ヘッダーファイル）
//	  全シーンの共通する部分があるクラス
// =============================================
class SceneBase
{
private:
	bool  is_next_ = false;
	float alpha_   = 0;

protected:
	virtual void updateBody();
	virtual void renderBody();

	// シーン終了時にこのメンバを呼ぶと
	// フェードアウトを行い、シーンが切り替わる
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



