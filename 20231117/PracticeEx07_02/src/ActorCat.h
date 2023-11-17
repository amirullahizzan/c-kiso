#pragma once

// -----------------------------------------------------
//	�L�N���X�i�w�b�_�[�t�@�C���j
//	 ���E�ɂ��낤�낷��L�����N�^�[�N���X
// -----------------------------------------------------
class ActorCat : public ActorBase
{
private :
	int facingMode = 0;
	void MoveLeft()
	{
		pos_.x--;
		dir_ = DIR::LEFT;
	}
	void MoveRight()
	{
		pos_.x++;
		dir_ = DIR::RIGHT;
	}
	void Move() override
	{
		switch (facingMode)
		{
		case 0:
			MoveRight();
			break;
		case 1:
			MoveLeft();
			break;
		}
	}
protected :

public :
	void init() override
	{
		dir_ = DIR::RIGHT;			 // ����
		attachImage("data/animation/pipo-charachip010b.png");
		pos_ = { WINDOW_W / 3 * 1 + (WINDOW_W / 3 / 2), WINDOW_H / 2 };
	}

	void posReset() override
	{
		if (pos_.x>= WINDOW_W / 3 * 2 - IMG_SIZE)
		{
			pos_.x = WINDOW_W / 3 * 2 - IMG_SIZE;
		}
		if (pos_.x <= WINDOW_W / 3 * 1 + IMG_SIZE)
		{
			pos_.x = WINDOW_W / 3 * 1 + IMG_SIZE;
		}
		static int timer = 0;
		timer--;
		if (timer<=0)
		{
			facingMode = GetRand(1);
			timer = GetRandomTimer();
		}
	}
};