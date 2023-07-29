#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip> 
#include <string>
#include <vector>
#include <conio.h>
#include "Buy.h"
#include "Check.h"
#include "Product.h"

using namespace std;

void gotoxy(short x, short y);
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue,
	LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background = Black);

void func_menu();

class Shop
{
	vector <Product> price_list;
	vector <Buy> buy_order;
	vector <Check> check;
public:
	Shop() { ; }
	void SetProduct(const Product& product) { price_list.push_back(product); }
	void Print_Price_list();
	void Print_Price_Element(int index);
	void SetOrder(const Buy& order) { buy_order.push_back(order); }
	void Print_Order_list();
	void Change_Order_list();
	double Total_sum_price();
	void Set_Check(const Check& _check) { check.push_back(_check); }
	void Print_Check();
	const vector <Buy>& Get_buy_order() { return buy_order; }
	void Clear_order_check();

};

