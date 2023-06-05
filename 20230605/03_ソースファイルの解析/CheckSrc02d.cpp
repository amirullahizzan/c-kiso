// CheckSrc02d.exe‚Æ“¯‚¶ÀsŒ‹‰Ê‚É‚È‚é‚æ‚¤‚É‚µ‚Ä‚­‚¾‚³‚¢
#include <iostream>
using namespace std;

// “ü—Í‚³‚ê‚½”’l‚ğæ“¾‚·‚éŠÖ”
int get_input_num()
{
	int n;
	cout << "”’l‚ğ“ü—Í > " << flush;
	cin >> n;
	return n;
}

int main()
{
	int num = 0;

	for (int i = 0; i < 5; ++i)
	{
		cout << i << ": " << (i + 1) * 2 << endl;
	}

	system("pause");
	return 0;
}