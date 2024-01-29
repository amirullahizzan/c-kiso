#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
// =====================================================
//	敵基底クラス（ソースファイル）
//	 登場⇒攻撃⇒退場、の管理をするクラス
// =====================================================
// 更新処理（本体）
void EnemyBase::updateBody()
{
	switch (action_no_)
	{
	case EnemyBase::MOVE_IN:
		if (moveInUpdate() == true)
		{
			action_no_ = EnemyBase::ATTACK;
		}
		break;
	case EnemyBase::ATTACK:
		++attack_frame_;
		if (attack_frame_ >= ATTACK_FRAME)
		{
			action_no_ = EnemyBase::MOVE_OUT;
		}
		attack();
		break;
	case EnemyBase::MOVE_OUT:
		if (moveOutUpdate() == true)
		{
			action_no_ = EnemyBase::DEAD;
		}
		break;
	case EnemyBase::DEAD:
		break;
	default:
		assert("miss action_no");
		break;
	}
}

// 攻撃シーン
void EnemyBase::attackRender()
{
}

// 登場：更新処理
bool EnemyBase::moveInUpdate()
{
	if (is_effe_in_ == false)
	{
		move_in_eff_->update();
		eff_alpha_ += (255 - eff_alpha_) * 0.05f;

		if (move_in_eff_->isPlay() == false &&
			eff_alpha_ > 240)
		{
			eff_alpha_  = 255;
			is_effe_in_ = true;
		}
		return false;
	}

	eff_alpha_ += (  0 - eff_alpha_) * 0.075f;
	alpha_	   += (255 - alpha_)	 * 0.05f;

	if (eff_alpha_ < 5)
	{
		eff_alpha_ = 0;
	}
	if (alpha_ > 250)
	{
		alpha_ = 255;

		delete move_in_eff_;
		move_in_eff_ = nullptr;

		return true;
	}
	return false;
}

// 登場：描画処理
void EnemyBase::moveInRender()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)eff_alpha_);
	DrawRectRotaGraphF(getPos().x, getPos().y - getSize() * 0.75f,
					   move_in_eff_->get() * EFFECT_W,
					   0,
					   EFFECT_W, EFFECT_H,
					   scale_, 0,
					   move_in_eff_->getGhandle(),
					   TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// 退場：更新処理
bool EnemyBase::moveOutUpdate()
{
	alpha_ += (0 - alpha_) * 0.05f;
	if (alpha_ < 5)
	{
		alpha_ = 0;
		return true;
	}

	return false;
}

// コンストラクタ
EnemyBase::EnemyBase(std::string img_path) :
	ActorBase(img_path)
{
	move_in_eff_ = new AnimationImage();
	move_in_eff_->load("data/effect/pipo-hikarimono016.png");
	move_in_eff_->attach({ { 2, 1, 0, -1 }, 10, false });
	
	scale_ = 1.25;
	// ランダムな場所にする
	pos_ = { 
		getSize() / 2 + GetRand((int)(WINDOW_W - getSize() * 2)),//WINDOW_W / 2,
		getSize() / 2 + GetRand((int)(WINDOW_H - getSize() * 2))//WINDOW_H / 2
	};
}

// デストラクタ
EnemyBase::~EnemyBase()
{
	if (move_in_eff_ != nullptr)
	{
		delete move_in_eff_;
		move_in_eff_ = nullptr;
	}
}

// 描画
void EnemyBase::render()
{
	switch (action_no_)
	{
	case EnemyBase::MOVE_IN:
		moveInRender();
		break;
	case EnemyBase::ATTACK:
		attackRender();
		break;
	case EnemyBase::MOVE_OUT:
		break;
	case EnemyBase::DEAD:
		return;
	default:
		assert("miss action_no");
		break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)alpha_);
	__super::render();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
