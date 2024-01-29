#pragma once
// =====================================================
//	敵「金丸」クラス（ヘッダーファイル）
//	 左右に移動する敵クラス
// =====================================================

enum
{
	Bound = 0,
	Tornado,
};


class Enemy12Yukioka :
	public EnemyBase
{
private:
	void attack() override;

	float move_speed_ = 9;

	float angle_ = 0.0f;
	void power();

	int frame_ = 0;

	bool attack_mode_ = 0;

public:
	Enemy12Yukioka();
	virtual ~Enemy12Yukioka();

};