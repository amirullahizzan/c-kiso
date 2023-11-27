#pragma once
// ----------------------------------------------
//	シルバーポイントカードクラス（ヘッダーファイル）
//	 ポイント加算時、加算ポイント×1.25倍で加算
//	 ※ 小数点以下のポイントは切り捨て
// ----------------------------------------------
class SilverPointCard : public PointCardBase
{
private:
	void addPoint(int var) override;
public:
	SilverPointCard();

};