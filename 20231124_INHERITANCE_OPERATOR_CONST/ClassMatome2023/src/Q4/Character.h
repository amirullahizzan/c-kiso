#pragma once
class Character
{
public:
	const char* m_str;
	Character(const char* str_);	// �R���X�g���N�^
	
	bool Search(char c) const;		// �����Ŏw�肳�ꂽ������������ɂ��邩�ǂ���
	void Show() const;				// ��������o��
};

