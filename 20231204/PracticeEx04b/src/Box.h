#pragma once
// ------------------------------------------------
//	図形「四角」クラス（ヘッダーファイル）
//	 円クラスを追従するクラス
// ------------------------------------------------
class Box :
	public ShapeBase
{
private:
	const float W = 120;
	const float H = 60;
public:
	Pos* _circlepos_ptr = nullptr;
	void init() override;
	void render() override;
	void update() override;

};
