#pragma once
// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
class IchimatsuMark
{
	int m_w, m_h;					// �T�C�Y - m_w(��), m_h(����)

	bool CheckRange(int val_);		// �����œn���ꂽ���l��2�`25�܂ł̐��l����Ȃ��ꍇ�Atrue��Ԃ�

public:
	IchimatsuMark();				// �R���X�g���N�^

	void Show();					// �T�C�Y���̖͗l���o�͂���
	void Resize();					// �T�C�Y���Đݒ肷��
};


