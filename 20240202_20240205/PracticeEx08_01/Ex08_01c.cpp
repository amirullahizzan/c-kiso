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
	cout << "計算式:";
	string inputstr;
	getline(cin, inputstr);
	if ( IsIncorrectOperation(inputstr) )
	{
		cout << "ERROR: 計算できない演算子が含まれています";
	}
	else
	{
		cout << inputstr << " = "; //結果
		string::size_type plusMarkPos = inputstr.find("+");
		if(plusMarkPos != string::npos) { inputstr.replace(plusMarkPos, 1, ""); }
		stringstream inputSstr (inputstr);
		int x, y;
		inputSstr >> x >> y;
		while (inputSstr >> x)
		{
		cout << x + y; //結果
		}
		//for (int i = 0; i < inputstr.size();i++)
		//{
		//}
	}
	
	
	cout << "\nプログラムを終了します..." << endl;

	system("pause");
	return 0;
}