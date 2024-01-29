#pragma once
#include "WinMain.h"

class BaseObj
{
protected:
	Pos m_pos;
	int m_ghandle;
	float m_angle;
	float m_ex_rate;

	void SetGhandle(const char* fname);

public:
	BaseObj(Pos pos);			// �R���X�g���N�^
	virtual ~BaseObj();			// �f�X�g���N�^

	virtual void Update() = 0;	// �X�V����
	virtual void Draw();		// �`��

	Pos GetPos() const;
	float GetR() const;
};

