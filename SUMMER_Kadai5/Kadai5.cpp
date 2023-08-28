#include <iostream>

using namespace std;

int RandLowerUpperCase()
{
	int randloweruppercase = rand() % 2;
	int charresult = 0;

	if (randloweruppercase == 0)
	{
		return charresult = rand()%(91-65)+65;
	}
	else if (randloweruppercase == 1)
	{
		return charresult = rand() % (123 - 97) + 97;
	}
}

int CountSelectedLetter(char selectedletter, int letterarray[], int MAXLETTERCOUNT)
{
	int selectedlettercount = 0;
	for (int i = 0; i < MAXLETTERCOUNT;i++)
	{
		if (letterarray[i] == (int)selectedletter)
		{
			selectedlettercount++;
		}
	}
	return selectedlettercount;
}


int main()
{
	srand((int)(unsigned int)(time (NULL) ));

	//max 200
	int letterarray[200] = {};
	const int MAXLETTERCOUNT = 200;
	int lettercount = 0;
	char randomletter;
	
	//az AZ rand
	for (;lettercount < MAXLETTERCOUNT;lettercount++)
	{
		
		letterarray[lettercount] = { RandLowerUpperCase() };
		
		cout << (char)letterarray[lettercount];
	}

	//az AZ pick 1
	randomletter = {(char)RandLowerUpperCase()};

	

	cout << endl << "•¶Žš—ñ‚Ì’†‚ÉA" << randomletter << " ‚ÍA"  <<CountSelectedLetter(randomletter, letterarray, MAXLETTERCOUNT) << "ŒÂ‚ ‚è‚Ü‚µ‚½" << endl << endl;



	system("pause");
	return 0;

}