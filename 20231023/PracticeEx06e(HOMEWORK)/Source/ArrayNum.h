#pragma once

class ArrayNum
{
private : 
		int values_[5]; //整数型の配列変数（サイズ5個）
		int size_ = 0;//配列変数のサイズ
public :
	ArrayNum();
	void set(int index, int newval);
	int get(int index);
	int getSize();
	void show();
		
	
};
