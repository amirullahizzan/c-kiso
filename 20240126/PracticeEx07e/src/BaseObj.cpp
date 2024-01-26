#include "BaseObj.h"

void BaseObj::SetGhandle(const char* fname)
{
	m_ghandle = LoadGraph(fname);
}

// コンストラクタ
BaseObj::BaseObj(Pos pos) :
	m_pos(pos), m_ghandle(-1),
	m_angle(0), m_ex_rate(1)
{

}

// デストラクタ
BaseObj::~BaseObj()
{
	DeleteGraph(m_ghandle);
}

// 描画処理
void BaseObj::Draw()
{
	DrawRotaGraphF(m_pos.x, m_pos.y, m_ex_rate, m_angle, m_ghandle, TRUE);
}

// 座標取得
Pos BaseObj::GetPos() const
{
	return m_pos;
}

// サイズ取得
float BaseObj::GetR() const
{
	return IMG_SIZE * m_ex_rate;
}