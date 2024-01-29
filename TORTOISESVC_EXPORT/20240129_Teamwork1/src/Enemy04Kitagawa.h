#pragma once
// =====================================================
//	敵「北川」クラス（ヘッダーファイル）
//	 
// =====================================================
class Enemy04Kitagawa :
	public EnemyBase
{
private:
	void attack() override;


public:
	Enemy04Kitagawa();
	virtual ~Enemy04Kitagawa();

	float speed_y = 5.0f;
	float speed_x = 5.0f;

	int time = 0;

};