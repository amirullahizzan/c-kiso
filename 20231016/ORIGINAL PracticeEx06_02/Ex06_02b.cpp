// AccountクラスのsetId関数を使用して、
// アカウントのIDを発行するプログラムを完成させてください。
#include <iostream>
#include <ctime>
using namespace std;

// --------------------------------------------------
//	ここから編集禁止
class Account
{
public:
	// メンバ変数
		  int	id_		   = 0;			// ID
	const char* user_name_ = nullptr;	// ユーザー名

	// メンバ関数
	void setId();	// IDの設定
	void show();	// アカウント情報の出力
};
// IDの設定
//	100 ～ 200 までの乱数をid_に割り振る
void Account::setId()
{
	id_ = 100 + rand() % 101;
}
// アカウント情報の出力
//	「ID: xxxx / User: xxxx」の形式で出力する
void Account::show()
{
	printf_s("ID: %3d / User: %s\n", id_, user_name_);
}
//	ここまで編集禁止
// --------------------------------------------------
