#include <iostream>

using namespace std;

int score[] = {
		641, 703, 405, 598, 402, 752, 330,    0, 445, 662,
		254, 710, 467, 530, 548, 485, 244, 396, 601 , 510,
		532, 687, 623 ,420 , 647 , 587 , 490, 647, 575 , 688,
		764, 633, 712 ,312 , 655 , 425 , 722, 631, 680, 602,

};

int GetSum()
{
	int sum = 0;

	for (int i = 0; i < 40; i++)
	{
		sum += score[i];
	}

	return sum;
}



int main()
{
	int highestscore = -1;
	int lowestscore = 999;

	for (int i = 0; i < 40; i++)
	{
		if (score[i] > score[i+1] && score[i] > highestscore )
		{
			highestscore = score[i];
		}

		if (score[i] < score[i + 1] && score[i] < lowestscore)
		{
			lowestscore = score[i];
		}
	}


	cout << "最高スコアは " << highestscore <<endl;
	cout << "最小スコアは " << lowestscore <<endl <<endl;

	cout << "グラフの平均点は　" << GetSum() / 40.0 << "　点です。 " << endl;

}