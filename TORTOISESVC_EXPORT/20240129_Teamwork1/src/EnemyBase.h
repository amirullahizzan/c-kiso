#pragma once
// =====================================================
//	敵基底クラス（ヘッダーファイル）
//	 登場⇒攻撃⇒退場、の管理をするクラス
// =====================================================
class EnemyBase :
	public ActorBase
{
private:
	enum ACTION
	{
		MOVE_IN = 0, // 入場
		ATTACK,		 // 攻撃
		MOVE_OUT,	 // 退場
		DEAD,		 // 死亡
	};
	ACTION action_no_ = ACTION::MOVE_IN;

	// 登場シーン用
	const int EFFECT_W = 64;
	const int EFFECT_H = 112;
	AnimationImage* move_in_eff_ = nullptr;
	bool			is_effe_in_	 = false;
	float			eff_alpha_	 = 0;
	bool moveInUpdate();
	void moveInRender();

	// 退場シーン
	bool moveOutUpdate();

	// キャラクター用
	const int ATTACK_FRAME = 15 * 60;	// 攻撃時間
	int	  attack_frame_ = 0;
	float alpha_		= 0;

	void updateBody() override;

	// 攻撃シーン
	virtual void attackRender();

protected:
	virtual void attack()  = 0;

	ActorBase* target_ptr_ = nullptr;

public:
	EnemyBase(std::string img_path);
	virtual ~EnemyBase();

	void render() override;

	// 死んでいるかどうか
	bool isDead() const
	{
		return action_no_ == EnemyBase::DEAD;
	}
	// 攻撃している最中かどうか
	bool isAttack() const
	{
		return action_no_ == EnemyBase::ATTACK;
	}
	// ターゲット（プレイヤー）のポインタ設定
	void setTarget(ActorBase* target)
	{
		target_ptr_ = target;
	}


};