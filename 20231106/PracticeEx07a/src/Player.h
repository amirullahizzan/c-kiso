#pragma once
// ------------------------------------------
//	プレイヤークラス（宣言部: ヘッダファイル）
// ------------------------------------------
class Player
{
public:
	Player();

	void Init();
	void Update();
	void Draw();

	float GetPosX() const;
	float GetPosY() const;
	float GetR()    const;

	bool IsDamage() const;
	void SetDamage();

private:
		   float x_			   = 0,
				 y_			   = 0,
				 r_			   = 0;
			 int hp_		   = 0;
	unsigned int color_		   = 0;
			bool is_damage_	   = false;
			 int damage_frame_ = 0;

};