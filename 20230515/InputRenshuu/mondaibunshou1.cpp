#include <iostream>

using namespace std;

int main()
{
	int saikoro = 0;
	cout << "saikoro number 選んでください" <<endl;
	cin >> saikoro;
		if (saikoro < 1 || saikoro>6)
		{
			cout << "サイコロではないです" << endl;
		}
		else
		{
			int saikoro_ura = 1;
			saikoro_ura = (6 - saikoro) + 1 ;
			cout << "saikoro ga "<< saikoro << ", saikoro no ura ga " << saikoro_ura;
		}

}