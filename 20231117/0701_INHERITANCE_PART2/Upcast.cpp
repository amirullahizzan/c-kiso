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
	cout << "ƒvƒƒOƒ‰ƒ€‚ÍI—¹‚µ‚Ü‚µ‚½" << endl;

	system("pause");
	return 0;
}

