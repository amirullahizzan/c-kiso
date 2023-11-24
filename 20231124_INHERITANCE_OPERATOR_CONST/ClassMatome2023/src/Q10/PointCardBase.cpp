#include <iostream>
#include "PointCardBase.h"
using namespace std;
// ----------------------------------------------
//	ポイントカード基底クラス（ソースファイル）
//	 様々な種類のポイントカードの基底クラス
// ----------------------------------------------
// *********************************
//	このファイルを編集しないこと
// *********************************
namespace
{
	const char* CARD_STR[PointCardBase::TYPE::MAX] =
	{
		"なし", "ゴールド会員", "シルバー会員"
	};

}
// ポイントカードの種別を設定
void PointCardBase::setType(TYPE type)
{
	type_ = type;
}
// カード情報の描画
void PointCardBase::render()
{
	printf_s("[%s]: %d\n", CARD_STR[type_], point_);
}
// 演算子「+=」のオーバーロード
void PointCardBase::operator+=(int var)
{
	addPoint(var);
}
