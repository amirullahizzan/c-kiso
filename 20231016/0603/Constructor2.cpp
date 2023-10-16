#include <iostream>

using namespace std;

class Integer
{
public:
	int m_value;

	//Integer();
	//Integer(int num = 0); //default args
	Integer(int num);
	void Show();
};

//Integer::Integer() { 	m_value = 0;} //default construct
//Integer::Integer(int num) { m_value = num; } //construct overload
Integer::Integer(int num = 0) { m_value = num; } //construct overload + default args


void Integer::Show()
{
	cout << m_value << endl;
}

int main()
{
	Integer a, 
		b(100), c(40), //multiple object declaration
	d = Integer(100);//copy constructor

	a.Show();
	b.Show();
	c.Show();


}
