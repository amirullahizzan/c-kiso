#include <iostream>

using namespace std;

int main()
{

	int input = 0;
	int* arrays = nullptr;
	int* temparrays = nullptr;
	int count = 0;
	//arrays = new int[count];

	while (true)
	{
		arrays = new int[count + 1];
		for (int i = 0; i < count; i++)
		{
			if (temparrays)
				arrays[i] = temparrays[i];
		}
		if (temparrays)
			delete[] temparrays;

		cout << "“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > " << flush;
		cin >> input;

		if (input == -1)
		{
			break;
		}

		arrays[count] = input;
		count++;
		temparrays = new int[count];
		for (int i = 0; i < count; i++)
		{
			temparrays[i] = arrays[i];
		}

		// copy to temporary
		delete[] arrays;
		//arrays = nullptr;
	}

	for (int i = 0; i < count; i++)
	{
		cout << "[" << i << "]" << "     " << arrays[i] << "\n" << flush;
	}

	if (arrays)
	{
		delete[] arrays;
	}
	arrays = nullptr;

	system("pause");
	return 0;
}