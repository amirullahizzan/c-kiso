#pragma once
// ----------------------------------------------
//	�|�C���g�J�[�h���N���X�i�w�b�_�[�t�@�C���j
//	 �l�X�Ȏ�ނ̃|�C���g�J�[�h�̊��N���X
// ----------------------------------------------
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
class PointCardBase
{
public:
	enum TYPE
	{
		None = 0,
		Gold,
		Silver,
		MAX
	};
	void render();

	void operator+=(int var);

protected:
	int point_ = 0;

	void setType(TYPE type);
	virtual void addPoint(int var) = 0;	// �|�C���g�̉��Z

private:
	TYPE type_ = TYPE::None;

};