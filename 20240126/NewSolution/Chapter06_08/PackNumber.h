#pragma once
// --------------------------------------------------------
//	PackNumberクラス（ヘッダーファイル）
//	 指定されたサイズの配列を作成し、
//	 その配列に数値を保存していくクラス
// --------------------------------------------------------
class PackNumber
{
public:
	PackNumber(int size);			// コンストラクタ(配列のサイズを引数で指定)
	~PackNumber();					// デストラクタ

	void Set(int i, int value);		// 配列のi番に値を代入
	int  Get(int i) const;			// 配列のi番の値を取得

	const int  SIZE;				// 配列のサイズ

private:
	int* nums_ = nullptr;			// 動的確保した配列のアドレスを入れるポインタ型変数

	bool CheckIndex(int i) const;	// 配列のインデックスチェック（true: 正常, false: 不正）
};

