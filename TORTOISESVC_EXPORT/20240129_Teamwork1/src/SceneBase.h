#pragma once
// =====================================================
//	全てのシーンの基底クラス（ヘッダーファイル）
//	 各シーンではupdateとrenderをオーバーライドする
// =====================================================
class SceneBase
{
private:
	const std::string name_;

protected:

public:
	SceneBase(std::string name);	// コンストラクタ
	virtual ~SceneBase();			// デストラクタ

	virtual bool update() = 0;		// 更新処理（シーンが終わるタイミングでtrueを返す）
	virtual void render();			// 描画処理

	virtual SCENE getNext() const;	// 次のシーンの番号を返す

};