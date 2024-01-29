#pragma once
// =====================================================
//	敵「金丸」クラス（ヘッダーファイル）
//	 左右に移動する敵クラス
// =====================================================
class Enemy01Izzan :
	public EnemyBase
{
private:
	void attack() override;

	bool isPlayerCloseTriggered = false;
	float move_speed_x = 4;
	float move_speed_y = 8;
	int spinTimer = 0;

	void SpinEnemy();
	void EnlargeSpriteAI();
	void EnemyAI();

public:
	Enemy01Izzan();
	virtual ~Enemy01Izzan();

};