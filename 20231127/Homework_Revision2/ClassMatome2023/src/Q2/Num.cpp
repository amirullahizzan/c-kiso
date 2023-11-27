#include "Num.h"
#include <iostream>
// ----------------------------------------------
//	入力した数値を管理するクラス（ソースファイル）
// ----------------------------------------------

void Num::Set()
{
	std::cout << "数値を入力 > " << std::flush;
	std::cin >> input;
}

void Num::Show()
{
	std::cout << input;
	std::cout << std::endl;
}
