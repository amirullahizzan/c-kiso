#pragma once
// ------------------------------------------------
//	�}�`�u�l�p�v�N���X�i�w�b�_�[�t�@�C���j
//	 �~�N���X��Ǐ]����N���X
// ------------------------------------------------
class Box :
	public ShapeBase
{
private:
	const float W = 120;
	const float H = 60;
public:
	Pos* _circlepos_ptr = nullptr;
	void init() override;
	void render() override;
	void update() override;

};
