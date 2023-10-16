// BookクラスのgetSaleNumメンバ関数を使用して、
// 最も売れた本を探すプログラムを完成させてください。
#include <iostream>
using namespace std;

// --------------------------------------------------
//	ここから編集禁止
class Book
{
private:
	const char* title_		 = nullptr;	// タイトル
	const char* author_name_ = nullptr;	// 著者名
		  int	year_		 = 0;		// 発売日(年)
		  int   sale_num_	 = 0;		// 販売部数

public:
	// メンバ変数にデータを渡して初期化する関数
	//	タイトル、著者名、発売日を指定引数に与える
	void init(const char* title, const char* author_name, int year, int sale_num);
	// 販売部数を取得する関数
	int  getSaleNum();
	// 本の情報を出力する関数
	void show();
};

// メンバ変数にデータを渡して初期化する関数
//	タイトル、著者名、発売日を指定引数に与える
void Book::init(const char* title, const char* author_name, int year, int sale_num)
{
	title_		 = title;
	author_name_ = author_name;
	year_		 = year;
	sale_num_	 = sale_num;
}
// 販売部数を取得する関数
int Book::getSaleNum()
{
	return sale_num_;
}
// 本の情報を出力する関数
void Book::show()
{
	printf_s("%s/%s 発刊日: %d年(%d万部)\n",
			 title_, author_name_, year_, sale_num_);
}
//	ここまで編集禁止
// --------------------------------------------------

int main()
{
	static int i;
	std::cout << i << endl;
	Book book[] = { {}, {}, {} };
	//Book book[3] = { };

	std::cout << "ハリーポッターシリーズで最も売れたタイトルは、" << endl;

	book[0].init("ハリーポッターと賢者の石", "J.K.ローリング", 1999, 508);
	book[1].init("ハリーポッターとHalf blood prince", "J.K.ローリング", 2009, 208);
	book[2].init("ハリーポッターとYamada taro", "J.K.ローリング", 2009, 5555);

	int highest = 0;
	int highestindex = 0;
	for (int i = 0;i<3;i++)
	{
		if (book[i].getSaleNum() >= highest)
		{
			highest = book[i].getSaleNum();
		}
	}

	for(int i = 0 ; i < 3 ; i++)
	{

	if (book[i].getSaleNum() == highest)
	{
	book[i].show();
	}

	}

	std::system("pause");
	return 0;
}