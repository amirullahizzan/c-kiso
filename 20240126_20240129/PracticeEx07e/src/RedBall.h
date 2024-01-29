#pragma once

class RedBall :
	public BaseObj
{

public:
	RedBall(Pos pos_);		// コンストラクタ
	virtual ~RedBall();		// デストラクタ
	void Update() override;

private:
	bool isExpanding = false;
};

