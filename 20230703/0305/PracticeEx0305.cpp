#include <iostream>


using namespace std;


char chr1[124];
char chr2[124];

int lettercounter = 0;
int samecounter = 0;

int chr1_len = 0;
int chr2_len = 0;

void CheckLength1();
void CheckLength2();

void Input1()
{
	cout << 1 << "–Ú‚Ì•¶Žš—ñ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > ";
	cin >> chr1;
	cout << chr1 << endl;
	CheckLength1();
}

void CheckLength1()
{
	for (int i = 0; chr1[i] != '\0'; i++)
	{
		chr1_len++;
	}
}

void Input2()
{
	cout << 2 << "–Ú‚Ì•¶Žš—ñ‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > ";
	cin >> chr2;
	cout << chr2 << endl;
	CheckLength2();
}

void CheckLength2()
{
	for (int i = 0; chr2[i] != '\0'; i++)
	{
		chr2_len++;
	}
}

int main()
{

	Input1();
	Input2();

		if (chr1_len != chr2_len)
		{
			//jlmh huruf
			cout << "the amount of letter is not the same" << endl;
			cout << "•¶Žš”‚ª“¯‚¶‚Å‚Í‚ ‚è‚Ü‚¹‚ñ" << endl;
			return 0;
		}

		for (int i = 0; chr1[i]!= '\0'; i++)
		{
			if (chr1[i] != chr2[i])
			{
				cout << "Different letter detected\n";
				cout << "ˆá‚¤•¶Žš—ñ‚Å‚·\n";
				return 0;
			}
		}

		cout << "o—Í‚Í‚Ü‚Á‚½‚­“¯‚¶‚Å‚·";

}