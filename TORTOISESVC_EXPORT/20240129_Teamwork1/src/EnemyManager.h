#pragma once
// =====================================================
//	�G�Ǘ��N���X�i�w�b�_�[�t�@�C���j
//	 �S�Ă̓G�̊Ǘ��N���X
// =====================================================
class EnemyManager
{
private:
	const int ENEMY_NUM;		// �G�̐�
	const int SPAWN_INTERVAL;	// �o���Ԋu�i�b���j

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