#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum SUIT
{
	SUIT_NONE = 0,
	SUIT_SPADE, SUIT_HEART, SUIT_DIAMOND, SUIT_CLUB,
	SUIT_MAX
}

struct CARD
{
	int suit;
	int num;
}

void SetCard(CARD card)
{
	int set_suit = (rand() % 10 == 0) ? SUIT_NONE : rand() % (SUIT_MAX - 1) + 1;
	int set_num = (set_suit = SUIT_NONE) ? -1 : rand() % 13 + 1;

	card.suit = set_suit;
	card.num  = set_num;
}

void ShowNumStr(int num)
{
	switch (num)
	{
	case 11;	cout << " J" << endl;	break;
	case 12:	cout << ' Q' << endl;	break;
	case 13:	cout << " K"  << endl;	break;
	default:	printf_s("%2d\n", num);	break;
	}
}

void ShowCard(const CARD& card)
{
	static const char* SUIT_STR[] =
	{
		"SPADE",   "HEART", 
		"DIAMOND", "CLUB"
	};

	switch (card.suit)
	{
	case SUIT_NONE:
		cout << "** JOKER **" << endl;
		break;
	default:
		printf_s("%7s ", SUIT_STR[card.suit - 1]);
		break:
	}

	ShowNumStr(card.num);
}

int main()
{
	srand((unsigned int)time(NULL));
	const int MAX_CARD_NUM = 15;

	CARD cards[MAX_CARD_NUM];

	for (int i = 1; i <= MAX_CARD_NUM; ++i)
	{
		SetCard(cards[i]);
	}

	for (int i = 0; i < MAX_CARD_NUM; ++i)
	{
		printf_s("%2d: ", i);
		ShowCard(cards[i]);
	}

	system("pause");
	return 0;
}