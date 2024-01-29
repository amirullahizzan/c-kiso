#include "WinMain.h"
#include "Hit.h"
#include "AnimationImage.h"
#include "ActorBase.h"
#include "Enemies.h"
#include "EnemyManager.h"
// =====================================================
//	敵管理クラス（ソースファイル）
//	 全ての敵の管理クラス
// =====================================================
// コンストラクタ
EnemyManager::EnemyManager(int num, int interval) :
	ENEMY_NUM(num),
	SPAWN_INTERVAL(interval)
{
	enemies_.reserve(num);
	enemies_.resize(num);
	std::fill(enemies_.begin(), enemies_.end(), nullptr);

}

EnemyManager::~EnemyManager()
{
	for (auto& e : enemies_)
	{
		if (e == nullptr)
			continue;

		delete e;
		e = nullptr;
	}
}

void EnemyManager::update()
{
	spawn();
	for (auto& e : enemies_)
	{
		if (e == nullptr)
			continue;
		e->update();
		if (e->isDead() == true)
		{
			delete e;
			e = nullptr;
		}
	}

	isHitToActor(target_ptr_);
}

// 当たり判定
bool EnemyManager::isHitToActor(const ActorBase* actor)
{
	for (const auto& e : enemies_)
	{
		if (e == nullptr)
			continue;
		if (e->isAttack() == false)
			continue;

		if (isHit(e->getPos(),			 e->getR(),
				  target_ptr_->getPos(), target_ptr_->getR()))
		{
			target_ptr_->onHit("Enemy");
		}
	}
	return false;
}

void EnemyManager::render()
{
	for (const auto& e : enemies_)
	{
		if (e == nullptr)
			continue;
		e->render();
	}
}

// 敵の出現
void EnemyManager::spawn()
{
	++spawn_frame_;
	spawn_frame_ %= SPAWN_INTERVAL;
	if (spawn_frame_ != 0)
		return;

	for (auto& e : enemies_)
	{
		if (e != nullptr)
			continue;

		e = factory();
		e->setTarget(target_ptr_);
		break;
	}
}


// 敵の生成
EnemyBase* EnemyManager::factory()
{
	switch (GetRand(100) % 10)
	{
	case 0:
		return new Enemy04Kitagawa();
	case 1:
		return new Enemy05Sasa();
	case 2:
		return new Enemy06Tanaka();
	case 3:
		return new Enemy07Hamaguchi();
	case 4:
		return new Enemy08Fujii();
	case 5:
		return new Enemy09Mai();
	case 6:
		return new Enemy11Mishima();
	case 7:
		return new Enemy12Yukioka();
	case 8:
		return new Enemy01Izzan();
	case 9:
		return new Enemy02Etoh();
	}

	return new EnemyKanamaru();
}
