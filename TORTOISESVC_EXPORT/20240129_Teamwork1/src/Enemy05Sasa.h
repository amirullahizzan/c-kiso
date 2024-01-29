#pragma once
// =====================================================
//	敵「佐々」クラス（ヘッダーファイル）
//	 左右に移動する敵クラス
// =====================================================
class Enemy05Sasa :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_ = 8;

public:
	Enemy05Sasa();
	virtual ~Enemy05Sasa();

};