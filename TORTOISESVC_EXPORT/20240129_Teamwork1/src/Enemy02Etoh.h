#pragma once
// =====================================================
//	�G�u�]���v�N���X�i�w�b�_�[�t�@�C���j
// =====================================================
class Enemy02Etoh :
	public EnemyBase
{
private:
	void attack() override;
	//ActorBase* act;
	//�G���ǂ̕����ɐi�ނ����߂�񋓑�
	enum {
		ENEMY_UP,
		ENEMY_DOWN,
		ENEMY_RIGHT,
		ENEMY_LEFT
	};
	//�G���ǂ̕����ɐi�ނ����߂�ϐ�
	int enemy_mode;
	int enemy_frame;

public:
	Enemy02Etoh();
	virtual ~Enemy02Etoh();

};