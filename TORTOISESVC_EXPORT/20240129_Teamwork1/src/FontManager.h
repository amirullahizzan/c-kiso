#pragma once
// =====================================================
//	�t�H���g�Ǘ��N���X�i�w�b�_�[�t�@�C���j
// =====================================================
class FontManager
{
private:
		  LPCSTR font_path_ = NULL;		// �t�H���g�f�[�^
	const char*  font_name_ = nullptr;	// �t�H���g��

	void unset();
public:
	FontManager();
	virtual ~FontManager();

	int create(int type);

};