#include <iostream>
#include <string>
using namespace std;

void PrintPlusMark(std::string& _inputstring)
{
	for (size_t i = 0; i < _inputstring.size() + 2; i++)
	{
		cout << "+";
	}
}

int main()
{
	cout << "•¶Žš—ñ‚ð“ü—Í > " << flush;
	string inputstr; 
	getline(cin , inputstr);
	
	PrintPlusMark(inputstr); 
	cout << "\n+" << inputstr << "+\n";
	PrintPlusMark(inputstr);
	cout << endl;

	system("pause");
	return 0;
}