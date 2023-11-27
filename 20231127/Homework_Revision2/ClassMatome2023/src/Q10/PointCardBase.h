#pragma once
// ----------------------------------------------
//	ポイントカード基底クラス（ヘッダーファイル）
//	 様々な種類のポイントカードの基底クラス
// ----------------------------------------------
// *********************************
//	このファイルを編集しないこと
// *********************************
class PointCardBase
{
public:
	enum TYPE
	{
		None = 0,
		Gold,
		Silver,
		MAX
	};
	void render();

	void operator+=(int var);

protected:
	int point_ = 0;

	void setType(TYPE type);
	virtual void addPoint(int var) = 0;	// ポイントの加算

private:
	TYPE type_ = TYPE::None;

};