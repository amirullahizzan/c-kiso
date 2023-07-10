#include <iostream>
#include <cmath>

using namespace std;

//•Ó = side
//Î•Ó = hypotenuse
//—×•Ó = adjacent
//•½•ûª = sqrt
int main()
{
	double a, b;
	cout << "’¼Šp‚ğ‹²‚Ş‚Q•Ó‚Ì’·‚³‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ > " << flush;
	cin >> a >> b;

	cout << "•Ó‚Ì’·‚³‚Í" << sqrtf(a * a + b * b) << " ‚Å‚·B" << endl;
}

//sqrt or sqrtf