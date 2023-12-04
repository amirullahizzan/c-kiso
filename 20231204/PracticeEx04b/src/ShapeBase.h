#pragma once
// ------------------------------------------------
//	図形基底クラス（ヘッダーファイル）
//	 様々な図形の共通部分をこのクラスに宣言・実装する
// ------------------------------------------------
class ShapeBase
{
private:


protected:
	Pos pos_;

public:
	virtual void init()   = 0;	// 初期化処理
	virtual void update();		// 更新処理
	virtual void render() = 0;	// 描画処理

	float getX() const
	{
		return pos_.x;
	}
	float getY() const
	{
		return pos_.y;
	}

	Pos* getPos()
	{
		return &pos_;
	}
};