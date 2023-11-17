#pragma once

// -----------------------------------------------------
//	王様クラス（ヘッダーファイル）
//	 上下にうろうろするキャラクタークラス
// -----------------------------------------------------
class ActorKing : public ActorBase
{
private:
	int facingMode = 0;
	void MoveDown()
	{
		pos_.y++;
		dir_ = DIR::DOWN;
	}
	void MoveUp()
	{
		pos_.y--;
		dir_ = DIR::UP;
	}
	void Move() override
	{
		switch (facingMode)
		{
		case 0:
			MoveDown();
			break;
		case 1:
			MoveUp();
			break;
		}
	}
public:
	void init() override
	{
		attachImage("data/animation/pipo-charachip011b.png");
		pos_ = { WINDOW_W / 3 * 2 + (WINDOW_W / 3 / 2), WINDOW_H / 2 };
	}
	void posReset() override
	{
		if (pos_.y <= 0 + IMG_SIZE)
		{
			pos_.y = 0 + IMG_SIZE;
		}
		if (pos_.y >= WINDOW_H - IMG_SIZE)
		{
			pos_.y = WINDOW_H - IMG_SIZE;
		}
		static int timer = 0;
		timer--;
		if (timer <= 0)
		{
			facingMode = GetRand(1);
			timer = GetRandomTimer();
		}
	}
};