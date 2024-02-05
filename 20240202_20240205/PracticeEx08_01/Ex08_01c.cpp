#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool IsIncorrectOperation(std::string _inputstring)
{
	string::size_type wrongPos = _inputstring.find("!");
	string::size_type wrongPos1 = _inputstring.find("%");
	string::size_type wrongPos2 = _inputstring.find("/");
	string::size_type wrongPos3 = _inputstring.find("*");
	return stoi(_inputstring) < 0 || 
		wrongPos != string::npos || 
		wrongPos1 != string::npos || 
		wrongPos2 != string::npos ||
		wrongPos3 != string::npos;
}

int main()
{
	cout << "�v�Z��:";
	string inputstr;
	getline(cin, inputstr);
	if ( IsIncorrectOperation(inputstr) )
	{
		cout << "ERROR: �v�Z�ł��Ȃ����Z�q���܂܂�Ă��܂�";
	}
	else
	{
		cout << inputstr << " = "; //����
		string::size_type plusMarkPos = inputstr.find("+");
		if(plusMarkPos != string::npos) { inputstr.replace(plusMarkPos, 1, ""); }
		stringstream inputSstr (inputstr);
		int x, y;
		inputSstr >> x >> y;
		while (inputSstr >> x)
		{
		cout << x + y; //����
		}
		//for (int i = 0; i < inputstr.size();i++)
		//{
		//}
	}
	
	
	cout << "\n�v���O�������I�����܂�..." << endl;

	system("pause");
	return 0;
}