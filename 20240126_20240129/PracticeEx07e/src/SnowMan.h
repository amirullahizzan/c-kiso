#pragma once

class SnowMan :
	public BaseObj
{

public:
	SnowMan(Pos pos_);	// �R���X�g���N�^
	virtual ~SnowMan();	// �f�X�g���N�^
	void Update() override;

private:
	bool isFalling = true;
	float moveAmount = 0.0f;

};

