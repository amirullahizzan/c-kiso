// *********************************
//	このファイルを編集しないこと
// *********************************
#include "IchimatsuMark.h"
#include <iostream>
using namespace std;

// 範囲確認関数
// 引数で渡された数値が2～25までの数値じゃない場合、trueを返す
bool IchimatsuMark::CheckRange(int val_)
{
	return (val_ < 2 || val_ > 25);
}

// コンストラクタ
IchimatsuMark::IchimatsuMark() :
	m_w(0), m_h(0)
{

}

// 出力関数
// サイズ分の模様を出力する
void IchimatsuMark::Show()
{
	// サイズが0以下であればエラーを出力する
	if (m_w == 0 || m_h == 0) {
		cout << "ERROR: サイズが正しく設定されていません!!" << endl;
		return;
	}

	// 出力処理
	int mark_cnt = 0;
	for (int y = 0; y < m_h; ++y) {
		for (int x = 0; x < m_w; ++x) {
			const char* mark_str = (mark_cnt % 2 == 0) ? "◆" : "◇";

			cout << mark_str;
			++mark_cnt;
		}
		if (m_w % 2 == 0)	++mark_cnt;
		cout << endl;
	}
}

// サイズ再設定関数
// cinを使ってサイズを設定する
void IchimatsuMark::Resize()
{
	int w, h;
	while (true)
	{
		// 幅サイズの入力
		cout << "横 > " << flush;
		cin >> w;
		// エラー処理
		if (CheckRange(w)) {
			// エラーであれば入力やり直し
			cout << "ERROR: 2 ～ 25 までの数値" << endl;
			continue;
		}

		// 縦サイズの入力
		cout << "縦 > " << flush;
		cin >> h;
		// エラー処理
		if (CheckRange(h)) {
			// エラーがあれば入力やり直し
			cout << "ERROR: 2 ～ 25 までの数値" << endl;
			continue;
		}

		break;
	}

	// cinで入力された数値をメンバ変数にセット
	m_w = w;
	m_h = h;
}
