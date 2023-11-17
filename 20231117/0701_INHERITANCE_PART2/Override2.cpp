#include "InputStream.h"
#include "ArrayStream.h"

using namespace std;

bool Average(Stream& stream)
{
	int	count;
	double avg = 0;

	for (count = 0; stream.Set(); count++)
	{
		avg += stream.Get();
	}
	if (count == 0)
	{
		return false;
	}

	avg = avg / count;

	cout << count << "ŒÂ‚Ì’l‚Ì•½‹Ï’l‚Í " << avg << " ‚Å‚·B" << endl;
	return true;
}

int main()
{
	InputStream istream;
	cout << "INPUTSTREAM" << endl;
	Average(istream);
	
	static const double ARRAY[] = { 0.5,1.5,-1 };
	ArrayStream astream(ARRAY);
	cout << "ARRAYSTREAM" << endl;
	Average(astream);

	system("pause");
	return 0;
}