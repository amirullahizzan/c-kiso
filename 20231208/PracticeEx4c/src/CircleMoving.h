#pragma once
// =====================================================
//	�ړ�����~�N���X�i�w�b�_�[�t�@�C���j
//	 �^�[�Q�b�g�Ɉړ�����~
// =====================================================
class CircleMoving :
	public CircleBase
{
private:
	const float MAX_SIZE;
	float angle_ = 0;
	const float base_speed = 3.0f;
	float speed = base_speed;
public:
	Pos force;
	CircleMoving(float size = 50.0f);
	void update() override;

	void MoveTo(Pos _targetpos);
	void ResetSpeed( );
};