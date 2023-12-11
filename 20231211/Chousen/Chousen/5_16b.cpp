#include <iostream>

using namespace std;

int main()
{

	int input = 0;
	int* arrays = nullptr;
	int count = 0;
	//arrays = new int[count];
	//int* newvalue = new int;
	while (true)
	{
		cout << "“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > " << flush;
		cin >> input;

		if (input == -1)
		{
			break;
		}



		if (arrays != nullptr)
		{
			// copy to temporary

			delete[] arrays;

		}
		count++;
		arrays = new int[count];

		arrays[count] = input;

		//count++;
	}

	for (int i = 0 ; i < count;i++)
	{
	cout << "[" << i <<"]" << "     " << arrays[i] << endl;
	}
	delete[] arrays;
	arrays = nullptr;
		system("pause");
		return 0;
}