#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iomanip> 
#include <string>
#include "Product.h"

using namespace std;

class Buy : public Product
{
	int count;
	float sum_price, sum_weight;
public:
	Buy() { count = 0; sum_price = 0, sum_weight = 0; }
	Buy(const string& _name, double _price, double _weight, int _count) :
		Product(_name, _price, _weight), count(_count)
	{
		sum_price = _price * count;
		sum_weight = _weight * count;
	}
	friend ostream& operator << (ostream& os, Buy& b);
	void Set_count(int _count);
	int Get_count() { return count; }
	void Calculate_sum_price_weight();
	void Print_order();
};

