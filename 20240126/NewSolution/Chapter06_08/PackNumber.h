#pragma once
// --------------------------------------------------------
//	PackNumber�N���X�i�w�b�_�[�t�@�C���j
//	 �w�肳�ꂽ�T�C�Y�̔z����쐬���A
//	 ���̔z��ɐ��l��ۑ����Ă����N���X
// --------------------------------------------------------
class PackNumber
{
public:
	PackNumber(int size);			// �R���X�g���N�^(�z��̃T�C�Y�������Ŏw��)
	~PackNumber();					// �f�X�g���N�^

	void Set(int i, int value);		// �z���i�Ԃɒl����
	int  Get(int i) const;			// �z���i�Ԃ̒l���擾

	const int  SIZE;				// �z��̃T�C�Y

private:
	int* nums_ = nullptr;			// ���I�m�ۂ����z��̃A�h���X������|�C���^�^�ϐ�

	bool CheckIndex(int i) const;	// �z��̃C���f�b�N�X�`�F�b�N�itrue: ����, false: �s���j
};

