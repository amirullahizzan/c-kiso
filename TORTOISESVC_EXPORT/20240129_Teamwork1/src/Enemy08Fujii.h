#pragma once
// =====================================================
//	敵「藤井」クラス（ヘッダーファイル）
//	 
// =====================================================
class Enemy08Fujii :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_ = 5;

public:
	Enemy08Fujii();
	virtual ~Enemy08Fujii();

};