#pragma once

class SnowFlake :
	public BaseObj
{

public:
	SnowFlake(Pos pos_);	// コンストラクタ
	virtual ~SnowFlake();	// デストラクタ
	void Update() override;

};

