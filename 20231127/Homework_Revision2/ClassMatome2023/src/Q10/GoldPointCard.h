#pragma once
// ----------------------------------------------
//	ゴールドポイントカードクラス（ヘッダーファイル）
//	 ポイント加算時、加算ポイント×1.5倍で加算
//	 ※ 小数点以下のポイントは切り捨て
// ----------------------------------------------
class GoldPointCard : public PointCardBase
{
private:
	void addPoint(int var) override;
public:
	GoldPointCard();
};