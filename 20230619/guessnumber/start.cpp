#include <iostream>
#include "start.h"

using namespace std;

int main()
{
	Round2 round;

	while (true)
	{
		cout << "=======================================\n\n";
		round.AskUserInput();

		if (round.input < 0 || round.input > 99)
		{
			cout << "”’l‚Í 0`100 ˆÈŠO“ü—Í‚Å‚«‚Ü‚¹‚ñI \n";
			continue;
		}
		else if (round.input == round.trueanswer[round.trueanswer_ELEM])
		{
			round.CorrectAnswer();
			continue;
		}
		else if(round.input != round.trueanswer[round.trueanswer_ELEM])
		{
			round.WrongAnswer();
			continue;
		}
		
	}

}