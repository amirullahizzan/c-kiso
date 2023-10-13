#include <iostream>

	using namespace std;

	const int MEMBER_NUM = 3;

class Member
{
public :
	
	const char* name_ = nullptr;
	int score1_ = 0;
	int score2_ = 0;
	int score3_ = 0;

	void ShowScore();
};

void Member::ShowScore()
{
	cout << "name: " << name_ << endl
		 << " score1: " << score1_ << flush
		 << ", score2: " << score2_ << flush
		 << ", score3: " << score3_ << endl;
}

int main()
{
	Member member[MEMBER_NUM] = {
		{"DominicHadley",15,3,5},{"CyrusBoece",3,5,12},{"AdamMcNamara",5,20,7}
	};

	

	for (int i = 0; i < MEMBER_NUM; ++i) {
		member[i].ShowScore();
	}

	system("pause");
	return 0;
}