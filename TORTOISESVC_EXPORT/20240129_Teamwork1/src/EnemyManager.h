#pragma once
// =====================================================
//	敵管理クラス（ヘッダーファイル）
//	 全ての敵の管理クラス
// =====================================================
class EnemyManager
{
private:
	const int ENEMY_NUM;		// 敵の数
	const int SPAWN_INTERVAL;	// 出現間隔（秒数）

	void	   spawn();
	EnemyBase* factory();

	std::vector<EnemyBase*> enemies_;
	ActorBase*				target_ptr_  = nullptr;
	int						spawn_frame_ = 0;

	bool isHitToActor(const ActorBase* actor);

public:
	EnemyManager(int num = 15, int interval = 60 * 3);
	virtual ~EnemyManager();

	void update();
	void render();

	void setTarget(ActorBase* target)
	{
		target_ptr_ = target;
	}

};