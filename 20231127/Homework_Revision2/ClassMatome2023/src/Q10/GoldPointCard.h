#pragma once
// ----------------------------------------------
//	�S�[���h�|�C���g�J�[�h�N���X�i�w�b�_�[�t�@�C���j
//	 �|�C���g���Z���A���Z�|�C���g�~1.5�{�ŉ��Z
//	 �� �����_�ȉ��̃|�C���g�͐؂�̂�
// ----------------------------------------------
class GoldPointCard : public PointCardBase
{
private:
	void addPoint(int var) override;
public:
	GoldPointCard();
};