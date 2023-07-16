#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iomanip> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Product
{
protected:
	string name_product;
	double price, weight;
public:
	Product();
	Product(const Product& obj);
	Product(string name, double price, double weight);
	~Product() { ; }
	friend ostream& operator << (ostream& os, Product& p);
	void Convert_price(double _price);
	void Convert_weight(double _weght);
	void Print_Product();
	string Get_name() { return name_product; }
	double Get_price() { return price; }
	double Get_weight() { return weight; }
	friend vector<Product> List_Products_Shop(vector <Product>& p);
};

