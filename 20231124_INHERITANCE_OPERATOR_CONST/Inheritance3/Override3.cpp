#include "Stream.h"
#include "InputStream.h"
#include <iostream>

using namespace std;

int main()
{
	//Cannot call abstract function directly.
	// 
	//Stream stream = { 5 };
	//Stream stream = 5;
	//Stream stream;
	//stream.Set();
	//cout << stream.Get() << endl;
	//exit(0);
	InputStream istream;
	cout << ">" << flush;
	istream.Set();
	cout << istream.Get() << endl;
	
	Stream& ref = istream;
	istream.Set();
	Stream* ref_ptr = &istream;

	system("pause");
	return 0;
}