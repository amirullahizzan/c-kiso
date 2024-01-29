#include "WinMain.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "EnemyBase.h"
#include "Enemy02Etoh.h"
// =====================================================
//	敵「江頭」クラス（ソースファイル）
// =====================================================
// 攻撃処理
void Enemy02Etoh::attack()
{
	//pos_.x++;
	enemy_frame++;
	if (enemy_frame >= 100)
	{
		enemy_mode = GetRand(3);
		enemy_frame = 0;
	}
	//上か下に移動したあとジグザク移動する
	switch (enemy_mode)
	{
	case ENEMY_UP:
		pos_.y -= 5;
		break;
	case ENEMY_DOWN:
		pos_.y += 5;
		break;
	case ENEMY_RIGHT:
		pos_.x += 5;
		break;
	case ENEMY_LEFT:
		pos_.x -= 5;
		break;
	}
	//画面買いに出ない処理
	if (pos_.x >= WINDOW_W)
	{
		pos_.x = WINDOW_W;
		enemy_mode = GetRand(3);
	}
	if (pos_.x <= 0)
	{
		pos_.x = 0;
		enemy_mode = GetRand(3);
	}
	if (pos_.y >= WINDOW_H)
	{
		pos_.y = WINDOW_H;
		enemy_mode = GetRand(3);
	}
	if (pos_.y <= 0)
	{
		pos_.y = 0;
		enemy_mode = GetRand(3);
	}

}

// コンストラクタ
Enemy02Etoh::Enemy02Etoh() :
	EnemyBase("data/animation/enemy/enemy01.png")
	,enemy_frame(0)
{

}

// デストラクタ
Enemy02Etoh::~Enemy02Etoh()
{

}
