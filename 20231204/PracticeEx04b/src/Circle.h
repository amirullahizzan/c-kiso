#pragma once
// ------------------------------------------------
//	�}�`�u�~�v�N���X�i�w�b�_�[�t�@�C���j
//	 ���E�L�[�ňړ��E�~��`�悷��N���X
// ------------------------------------------------
class Circle :
	public ShapeBase
{
private:
	const float R	  = 45;
	const float SPEED = 8;

	void fitWindowW();

public:
	void init()   override;
	void update() override;
	void render() override;

};