// Personクラスのオブジェクトを使用して、
// 女優「有村架純」さんの年齢情報を出力するプログラムを完成させてください。
#include <iostream>
using namespace std;

// --------------------------------------------------
//	ここから編集禁止
class Person
{
public:
	const char* name = nullptr;	// 名前
		  int   age	 = 0;		// 年齢

	void show();				// 名前と年齢を「名前(年齢)」の形式で出力
};
// 名前と年齢を「名前(年齢)」の形式で出力
void Person::show()
{
	printf_s("%s(%d)\n", name, age);
}
//	ここまで編集禁止
// --------------------------------------------------

