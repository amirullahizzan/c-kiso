#pragma once
// ----------------------------------------------
//	���ɂ��N���X�i�w�b�_�[�t�@�C���j
//	 1�`31�܂ł̐��l���Ǘ�����
// ----------------------------------------------
class Day
{
private:
	int day_ = 1;

	int CheckDay()
	{
		day_ %= 31;
		if (day_ < 1)
		{
			day_ += 31;
		}
		return day_;
	}

public:
	Day(int day = 1);

	// �����o�ϐ��uday_�v���擾����֐�
	int get() const
	{
		return day_;
	}

	
	int operator+=(int value) { day_ += value; return CheckDay(); }
	int operator-=(int value) { day_ -= value; return CheckDay(); }
};