#pragma once
// ------------------------------------------
//	敵クラス（宣言部: ヘッダファイル）
// ------------------------------------------
class ActorBase
{

};
class Enemy : public ActorBase
{
public:
	Enemy();

	void Init();
	void Update();
	void Draw();

	void SetPos(float x, float y);

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