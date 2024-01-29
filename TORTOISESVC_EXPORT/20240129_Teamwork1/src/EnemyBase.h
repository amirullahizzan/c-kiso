#pragma once
// =====================================================
//	�G���N���X�i�w�b�_�[�t�@�C���j
//	 �o��ˍU���ˑޏ�A�̊Ǘ�������N���X
// =====================================================
class EnemyBase :
	public ActorBase
{
private:
	enum ACTION
	{
		MOVE_IN = 0, // ����
		ATTACK,		 // �U��
		MOVE_OUT,	 // �ޏ�
		DEAD,		 // ���S
	};
	ACTION action_no_ = ACTION::MOVE_IN;

	// �o��V�[���p
	const int EFFECT_W = 64;
	const int EFFECT_H = 112;
	AnimationImage* move_in_eff_ = nullptr;
	bool			is_effe_in_	 = false;
	float			eff_alpha_	 = 0;
	bool moveInUpdate();
	void moveInRender();

	// �ޏ�V�[��
	bool moveOutUpdate();

	// �L�����N�^�[�p
	const int ATTACK_FRAME = 15 * 60;	// �U������
	int	  attack_frame_ = 0;
	float alpha_		= 0;

	void updateBody() override;

	// �U���V�[��
	virtual void attackRender();

protected:
	virtual void attack()  = 0;

	ActorBase* target_ptr_ = nullptr;

public:
	EnemyBase(std::string img_path);
	virtual ~EnemyBase();

	void render() override;

	// ����ł��邩�ǂ���
	bool isDead() const
	{
		return action_no_ == EnemyBase::DEAD;
	}
	// �U�����Ă���Œ����ǂ���
	bool isAttack() const
	{
		return action_no_ == EnemyBase::ATTACK;
	}
	// �^�[�Q�b�g�i�v���C���[�j�̃|�C���^�ݒ�
	void setTarget(ActorBase* target)
	{
		target_ptr_ = target;
	}


};