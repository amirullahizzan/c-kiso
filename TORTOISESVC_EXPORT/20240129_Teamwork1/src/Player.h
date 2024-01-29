#pragma once
// =====================================================
//	�v���C���[�N���X�i�w�b�_�[�t�@�C���j
//	 �㉺���E�L�[�ňړ�����
// =====================================================
class Player :
	public ActorBase
{
private:
	const float MOVE_SPEED	 = 5.0f;
	const int   DAMAGE_FRAME = 60 * 1;
	const int   HP_MAX		 = 3;

	int   damage_frame_ = 0;		// �_���[�W���t���[����
	int	  hp_			= HP_MAX;	// HP
	float move_num_		= 0;		// �ړ�����

	void keyMove();
	void updateBody() override;

	// �_���[�W����
	void updateDamage();

public:
	Player();

	void render() override;
	void onHit(std::string tag) override;	// �����ɓ�������

	// ���񂾂��ǂ���
	bool isDead() const
	{
		return (hp_ <= 0);
	}
	// ���݂�HP
	int getHp() const
	{
		return hp_;
	}
	// ���݂̈ړ�����
	float getMoveNum() const
	{
		return move_num_;
	}

};