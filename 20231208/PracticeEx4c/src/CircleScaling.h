#pragma once
// =====================================================
//	�g�k����~�N���X�i�w�b�_�[�t�@�C���j
//	 �g��k������~
// =====================================================
class CircleScaling :
	public CircleBase
{
private:
	const float MAX_SIZE;
	float angle_ = 0;

public:
	CircleScaling(float size = 50.0f);

	void update() override;

};