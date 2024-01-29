#pragma once
// =====================================================
//	フォント管理クラス（ヘッダーファイル）
// =====================================================
class FontManager
{
private:
		  LPCSTR font_path_ = NULL;		// フォントデータ
	const char*  font_name_ = nullptr;	// フォント名

	void unset();
public:
	FontManager();
	virtual ~FontManager();

	int create(int type);

};