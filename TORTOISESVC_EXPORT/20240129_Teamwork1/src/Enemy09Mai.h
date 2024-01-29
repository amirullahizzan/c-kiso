#pragma once
// =====================================================
//	敵「金丸」クラス（ヘッダーファイル）
//	 左右に移動する敵クラス
// =====================================================
class Enemy09Mai :
	public EnemyBase
{
private:
	void attack() override;
	int rot_speed = 0;
	float move_speed_ = 8;

public:
	Enemy09Mai();
	virtual ~Enemy09Mai();

};