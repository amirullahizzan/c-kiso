// Q1. 基本的なクラスの使い方
// IchimatsuMarkクラスを使って、市松模様を3回出力しなさい
// IchimatsuMarkクラスは、以下のメンバ関数を持っている
//		Resizeメンバ関数 … 市松模様のサイズを設定する
//		Showメンバ関数	 … 市松模様をサイズ分出力する
// 実行サンプル > Q1.exe
#include <iostream>
#include "IchimatsuMark.h"
using namespace std;


int main()
{
	IchimatsuMark imark;
	static int count = 0;
	while (count < 3)
	{
	imark.Resize();
	imark.Show();
	count++;
	}
	std::system("pause");
	return 0;
}