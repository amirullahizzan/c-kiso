#pragma once
// =====================================================
//	敵「金丸」クラス（ヘッダーファイル）
//	 左右に移動する敵クラス
// =====================================================
class EnemyKanamaru :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_ = 8;
	void attackRender() override;

public:
	EnemyKanamaru();
	virtual ~EnemyKanamaru();

};