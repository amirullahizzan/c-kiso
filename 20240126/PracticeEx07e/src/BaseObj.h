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
	BaseObj(Pos pos);			// コンストラクタ
	virtual ~BaseObj();			// デストラクタ

	virtual void Update() = 0;	// 更新処理
	virtual void Draw();		// 描画

	Pos GetPos() const;
	float GetR() const;
};

