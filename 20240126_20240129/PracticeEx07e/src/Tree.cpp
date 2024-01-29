#include "BaseObj.h"
#include "Tree.h"

Tree::Tree() :
	BaseObj({ WINDOW_W / 2, WINDOW_H / 2 + 45 }),
	m_ghandle2(-1)
{
	SetGhandle("data/Tree1.png");
	m_ghandle2 = LoadGraph("data/Tree2.png");

	m_ex_rate = 1;
}

Tree::~Tree()
{
	DeleteGraph(m_ghandle2);
}

void Tree::Update()
{

}

void Tree::Draw()
{
	BaseObj::Draw();
	DrawRotaGraph(WINDOW_W / 2, 75, 1.0, 0.0, m_ghandle2, TRUE);
}