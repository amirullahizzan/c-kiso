#include "Num.h"
#include <iostream>
// ----------------------------------------------
//	���͂������l���Ǘ�����N���X�i�\�[�X�t�@�C���j
// ----------------------------------------------

void Num::Set()
{
	std::cout << "���l����� > " << std::flush;
	std::cin >> input;
}

void Num::Show()
{
	std::cout << input;
	std::cout << std::endl;
}
