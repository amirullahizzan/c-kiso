#pragma once

class ArrayNum
{
private : 
		int values_[5]; //�����^�̔z��ϐ��i�T�C�Y5�j
		int size_ = 0;//�z��ϐ��̃T�C�Y
public :
	ArrayNum();
	void set(int index, int newval);
	int get(int index);
	int getSize();
	void show();
		
	
};
