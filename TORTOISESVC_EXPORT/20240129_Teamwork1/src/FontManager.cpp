#include "WinMain.h"
#include "FontManager.h"
#include <cassert>
// =====================================================
//	フォント管理クラス（ソースファイル）
// =====================================================
// コンストラクタ
FontManager::FontManager()
{
}

// デストラクタ
FontManager::~FontManager()
{
	unset();
}

// フォントの作成
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

	// フォントデータのロード
	if (AddFontResourceEx(font_path_, FR_PRIVATE, NULL) > 0)
	{
	}
	else
	{
		MessageBox(NULL, "フォントの読み込みに失敗...", "", MB_OK);
		return -1;
	}
	ChangeFont(font_name_, DX_CHARSET_DEFAULT);

	return 0;
}

// 作成したフォントの削除
void FontManager::unset()
{
	// フォントデータのアンロード
	if (RemoveFontResourceEx(font_path_, FR_PRIVATE, NULL))
	{
	}
	else
	{
		MessageBox(NULL, "フォントの削除に失敗...", "", MB_OK);
	}
	// 元のフォントに戻す
	ChangeFont("ＭＳ ゴシック", DX_CHARSET_DEFAULT);
}
