#pragma once
// ------------------------------------------------
//	図形「円」クラス（ヘッダーファイル）
//	 左右キーで移動・円を描画するクラス
// ------------------------------------------------
class Circle :
	public ShapeBase
{
private:
	const float R	  = 45;
	const float SPEED = 8;

	void fitWindowW();

public:
	void init()   override;
	void update() override;
	void render() override;

};