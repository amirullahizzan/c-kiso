#pragma once
#include "BaseObj.h"
class Tree :
	public BaseObj
{
	int m_ghandle2;
public:
	Tree();
	virtual ~Tree();

	void Update() override;
	void Draw() override;
};

