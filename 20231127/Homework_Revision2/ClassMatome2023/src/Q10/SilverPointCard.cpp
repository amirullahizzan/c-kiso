#include <iostream>
#include "PointCardBase.h"
#include "SilverPointCard.h"
using namespace std;
// ----------------------------------------------
//	シルバーポイントカードクラス（ソースファイル）
//	 ポイント加算時、加算ポイント×1.25倍で加算
//	 ※ 小数点以下のポイントは切り捨て
// ----------------------------------------------
SilverPointCard::SilverPointCard()
{
	setType(TYPE::Silver);
}

void SilverPointCard::addPoint(int var)
{
	point_ += static_cast<int>(var * 1.25f);
}