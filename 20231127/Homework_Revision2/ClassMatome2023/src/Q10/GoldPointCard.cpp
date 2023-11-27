#include <iostream>
#include "PointCardBase.h"
#include "GoldPointCard.h"
using namespace std;
// ----------------------------------------------
//	ゴールドポイントカードクラス（ソースファイル）
//	 ポイント加算時、加算ポイント×1.5倍で加算
//	 ※ 小数点以下のポイントは切り捨て
// ----------------------------------------------
GoldPointCard::GoldPointCard()
{
	setType(TYPE::Gold);
}

void GoldPointCard::addPoint(int var)
{
	point_ += static_cast<int>(var * 1.5f);
}