#pragma once

class SnowFlake :
	public BaseObj
{

public:
	SnowFlake(Pos pos_);	// �R���X�g���N�^
	virtual ~SnowFlake();	// �f�X�g���N�^
	void Update() override;

};

