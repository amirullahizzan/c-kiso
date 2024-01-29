#include "WinMain.h"
#include "FontManager.h"
#include <cassert>
// =====================================================
//	�t�H���g�Ǘ��N���X�i�\�[�X�t�@�C���j
// =====================================================
// �R���X�g���N�^
FontManager::FontManager()
{
}

// �f�X�g���N�^
FontManager::~FontManager()
{
	unset();
}

// �t�H���g�̍쐬
int FontManager::create(int type)
{
	if (font_path_ != NULL)
	{
		unset();
	}

	switch (type)
	{
	case FONT::PIXEL_M:
		font_path_ = "data/font/PixelMplus10-Regular.ttf";
		font_name_ = "PixelMplus10";
		break;
	default:
		assert("miss type");
		return -1;
	}

	// �t�H���g�f�[�^�̃��[�h
	if (AddFontResourceEx(font_path_, FR_PRIVATE, NULL) > 0)
	{
	}
	else
	{
		MessageBox(NULL, "�t�H���g�̓ǂݍ��݂Ɏ��s...", "", MB_OK);
		return -1;
	}
	ChangeFont(font_name_, DX_CHARSET_DEFAULT);

	return 0;
}

// �쐬�����t�H���g�̍폜
void FontManager::unset()
{
	// �t�H���g�f�[�^�̃A�����[�h
	if (RemoveFontResourceEx(font_path_, FR_PRIVATE, NULL))
	{
	}
	else
	{
		MessageBox(NULL, "�t�H���g�̍폜�Ɏ��s...", "", MB_OK);
	}
	// ���̃t�H���g�ɖ߂�
	ChangeFont("�l�r �S�V�b�N", DX_CHARSET_DEFAULT);
}
