#pragma once
// *********************************
//	このファイルを編集しないこと
// *********************************
class IchimatsuMark
{
	int m_w, m_h;					// サイズ - m_w(横), m_h(高さ)

	bool CheckRange(int val_);		// 引数で渡された数値が2～25までの数値じゃない場合、trueを返す

public:
	IchimatsuMark();				// コンストラクタ

	void Show();					// サイズ分の模様を出力する
	void Resize();					// サイズを再設定する
};


