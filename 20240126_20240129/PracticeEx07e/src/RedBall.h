#pragma once

class RedBall :
	public BaseObj
{

public:
	RedBall(Pos pos_);		// �R���X�g���N�^
	virtual ~RedBall();		// �f�X�g���N�^
	void Update() override;

private:
	bool isExpanding = false;
};

