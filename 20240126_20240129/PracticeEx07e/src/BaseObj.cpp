#include "BaseObj.h"

void BaseObj::SetGhandle(const char* fname)
{
	m_ghandle = LoadGraph(fname);
}

// �R���X�g���N�^
BaseObj::BaseObj(Pos pos) :
	m_pos(pos), m_ghandle(-1),
	m_angle(0), m_ex_rate(1)
{

}

// �f�X�g���N�^
BaseObj::~BaseObj()
{
	DeleteGraph(m_ghandle);
}

// �`�揈��
void BaseObj::Draw()
{
	DrawRotaGraphF(m_pos.x, m_pos.y, m_ex_rate, m_angle, m_ghandle, TRUE);
}

// ���W�擾
Pos BaseObj::GetPos() const
{
	return m_pos;
}

// �T�C�Y�擾
float BaseObj::GetR() const
{
	return IMG_SIZE * m_ex_rate;
}