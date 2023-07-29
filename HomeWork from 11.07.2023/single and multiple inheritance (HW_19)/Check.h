#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iomanip> 
#include <string>
#include "Buy.h"

using namespace std;

class Check : public Buy
{
public:
	Check() { ; }
	Check(const string& name, double price, double weight, int count): 
		Buy(name, price, weight, count ) {}
	friend ostream& operator << (ostream& os, Check& c);
};
