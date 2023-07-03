#include <iostream>


using namespace std;

int input = 1;
char chr = 97;

void UserInput()
{
	cout << "移動させる量(0 終了) > ";
	cin >> input;
}
void DetectOverload()
{
	if (input > 25)
	{
		input %= 26;
	}
	chr += (int)input;
}

int main()
{
	while(true)
	{
		UserInput();
	if (input == 0)
	{
		break;
	}
	cout << "a から " << input << " 移動すると、";
	DetectOverload();
	
	
	cout << chr << " です。\n";

	//reset
	chr = 97;
	}
	cout << "プログラム終了。";
}