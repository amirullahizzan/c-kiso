#include "InputStream.h"
#include "Stream.h"
#include <iostream>

int main()
{
	InputStream istream;
	std::cout << ">" << std::flush;
	istream.Set();
	std::cout << istream.Get() << std::endl;

	Stream stream;
	stream.Set();
	std::cout << stream.Get() << std::endl;

	system("pause");
	return 0;
}