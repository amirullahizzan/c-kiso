#pragma once
// ----------------------------------------------
//	日にちクラス（ヘッダーファイル）
//	 1～31までの数値を管理する
// ----------------------------------------------
class Day
{
private:
	int day_ = 1;

	int CheckDay()
	{
		day_ %= 31;
		if (day_ < 1)
		{
			day_ += 31;
		}
		return day_;
	}

public:
	Day(int day = 1);

	// メンバ変数「day_」を取得する関数
	int get() const
	{
		return day_;
	}

	
	int operator+=(int value) { day_ += value; return CheckDay(); }
	int operator-=(int value) { day_ -= value; return CheckDay(); }
};