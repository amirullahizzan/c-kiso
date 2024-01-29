#pragma once
// =====================================================
//	プレイヤークラス（ヘッダーファイル）
//	 上下左右キーで移動する
// =====================================================
class Player :
	public ActorBase
{
private:
	const float MOVE_SPEED	 = 5.0f;
	const int   DAMAGE_FRAME = 60 * 1;
	const int   HP_MAX		 = 3;

	int   damage_frame_ = 0;		// ダメージ中フレーム数
	int	  hp_			= HP_MAX;	// HP
	float move_num_		= 0;		// 移動距離

	void keyMove();
	void updateBody() override;

	// ダメージ処理
	void updateDamage();

public:
	Player();

	void render() override;
	void onHit(std::string tag) override;	// 何かに当たった

	// 死んだかどうか
	bool isDead() const
	{
		return (hp_ <= 0);
	}
	// 現在のHP
	int getHp() const
	{
		return hp_;
	}
	// 現在の移動距離
	float getMoveNum() const
	{
		return move_num_;
	}

};