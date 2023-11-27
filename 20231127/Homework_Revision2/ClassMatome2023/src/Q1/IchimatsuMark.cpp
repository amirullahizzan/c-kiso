// *********************************
//	���̃t�@�C����ҏW���Ȃ�����
// *********************************
#include "IchimatsuMark.h"
#include <iostream>
using namespace std;

// �͈͊m�F�֐�
// �����œn���ꂽ���l��2�`25�܂ł̐��l����Ȃ��ꍇ�Atrue��Ԃ�
bool IchimatsuMark::CheckRange(int val_)
{
	return (val_ < 2 || val_ > 25);
}

// �R���X�g���N�^
IchimatsuMark::IchimatsuMark() :
	m_w(0), m_h(0)
{

}

// �o�͊֐�
// �T�C�Y���̖͗l���o�͂���
void IchimatsuMark::Show()
{
	// �T�C�Y��0�ȉ��ł���΃G���[���o�͂���
	if (m_w == 0 || m_h == 0) {
		cout << "ERROR: �T�C�Y���������ݒ肳��Ă��܂���!!" << endl;
		return;
	}

	// �o�͏���
	int mark_cnt = 0;
	for (int y = 0; y < m_h; ++y) {
		for (int x = 0; x < m_w; ++x) {
			const char* mark_str = (mark_cnt % 2 == 0) ? "��" : "��";

			cout << mark_str;
			++mark_cnt;
		}
		if (m_w % 2 == 0)	++mark_cnt;
		cout << endl;
	}
}

// �T�C�Y�Đݒ�֐�
// cin���g���ăT�C�Y��ݒ肷��
void IchimatsuMark::Resize()
{
	int w, h;
	while (true)
	{
		// ���T�C�Y�̓���
		cout << "�� > " << flush;
		cin >> w;
		// �G���[����
		if (CheckRange(w)) {
			// �G���[�ł���Γ��͂�蒼��
			cout << "ERROR: 2 �` 25 �܂ł̐��l" << endl;
			continue;
		}

		// �c�T�C�Y�̓���
		cout << "�c > " << flush;
		cin >> h;
		// �G���[����
		if (CheckRange(h)) {
			// �G���[������Γ��͂�蒼��
			cout << "ERROR: 2 �` 25 �܂ł̐��l" << endl;
			continue;
		}

		break;
	}

	// cin�œ��͂��ꂽ���l�������o�ϐ��ɃZ�b�g
	m_w = w;
	m_h = h;
}
