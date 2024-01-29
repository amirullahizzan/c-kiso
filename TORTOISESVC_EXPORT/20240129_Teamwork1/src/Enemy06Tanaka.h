#pragma once
// =====================================================
//	敵「田中」クラス（ヘッダーファイル）
//	 
// =====================================================
class Enemy06Tanaka :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_x = 5;
	float move_speed_y = 10;

public:
	Enemy06Tanaka();
	virtual ~Enemy06Tanaka();

};