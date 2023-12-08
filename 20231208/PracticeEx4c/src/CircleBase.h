#pragma once
// *************************************************************
//	編集禁止
// *************************************************************
// =====================================================
//	円の基底クラス（ヘッダーファイル）
//	 すべての円の基本情報を管理するクラス
// =====================================================
class CircleBase
{
private:
	unsigned int  color_   = 0;		// 円の色
			 bool is_fill_ = false;	// 円を塗りつぶす/塗りつぶさない

protected:
	const ActorBase* target_ = nullptr;

	Pos	  pos_  = { WINDOW_W / 2, WINDOW_H / 2 };
	float size_ = 0;
	// 色の変更を行う
	//	派生クラスのupdate関数で呼ぶので、protectedにする
	void setColor(unsigned int color, bool is_fill = false)
	{
		color_ = color;
		is_fill_ = is_fill;
	}

public:
	CircleBase(float size);

	// ターゲットになる対象物のアドレスを変更する
	//	派生クラスではこのtarget_にあるアドレスを使って
	//	様々な処理を実装する
	void setTarget(const ActorBase* target)
	{
		target_ = target;
	}

	// 座標の設定
	void setPos(const Pos& pos)
	{
		pos_ = pos;
	}
	// 座標を取得
	Pos getPos() const
	{
		return pos_;
	}

	virtual void update() {}
	virtual void render() final;

};