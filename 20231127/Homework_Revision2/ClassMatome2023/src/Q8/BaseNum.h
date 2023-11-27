#pragma once

class BaseNum
{
protected:
	int m_num;


public:
	virtual void Show();		// 数値を出力するメンバ関数
	BaseNum(int num_);	// 引数付きコンストラクタ

};

