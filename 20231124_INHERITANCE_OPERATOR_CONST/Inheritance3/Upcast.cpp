#include "Stream.h"
#include "InputStream.h"
#include <iostream>

using namespace std;

int main()
{
	InputStream stream;
	cout << ">" << endl;
	stream.Set();

	const Stream& ref = stream;
	cout << ref.Get() << endl;
	cout << "プログラムは終了しました" << endl;

	system("pause");
	return 0;
}

