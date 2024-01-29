#pragma once

class SnowMan :
	public BaseObj
{

public:
	SnowMan(Pos pos_);	// コンストラクタ
	virtual ~SnowMan();	// デストラクタ
	void Update() override;

private:
	bool isFalling = true;
	float moveAmount = 0.0f;

};

