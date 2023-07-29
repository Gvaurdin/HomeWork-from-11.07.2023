#include "Product.h"

Product::Product()
{
	name_product = "";
	price = 0;
	weight = 0;

}

Product::Product(const Product& obj)
{
	name_product = obj.name_product;
	price = obj.price;
	weight = obj.weight;
}

Product::Product(string _name, double _price, double _weight)
{
	name_product = _name;
	price = _price;
	weight = _weight;
}


void Product::Convert_price(double _price)
{
	int rub{}, kop{};
	rub = (int)_price;
	kop = _price * 100;
	kop %= 100;
	cout << left << setw(4) << rub << left << setw(5) <<
		"rub. " << left << setw(2) << kop << left << setw(12) << "kop.";
}

void Product::Convert_weight(double _weight)
{
	int kg{}, g{};
	kg = (int)_weight;
	g = _weight * 100;
	g = (g % 100) * 10;
	if (kg == 0) cout << left << setw(4) << g << left << setw(13) << "g.";
	else if (kg != 0 && g != 0) cout << left << setw(3) << kg << left << setw(5) << "kg. " <<
		left << setw(4) << g << left << setw(5) << "g.";
	else cout << left << setw(2) << kg << left << setw(15) << "kg.";
}

void Product::Print_Product()
{
	cout << left << setw(15) << name_product;
	Convert_price(price);
	Convert_weight(weight);
}

ostream& operator<<(ostream& os, Product& p)
{
	cout << left << setw(15) << p.name_product;
	p.Convert_price(p.price);
	p.Convert_weight(p.weight);
	cout << "\n======================================================\n";
	return os;
}


vector<Product> List_Products_Shop(vector<Product>& p)
{
	p.push_back(Product("Milk", 84.35, 0.9));
	p.push_back(Product("Meat", 257.89, 1.0));
	p.push_back(Product("Lemonade", 110, 1.5));
	p.push_back(Product("Chocolate", 110, 0.1));
	p.push_back(Product("Doshirak", 70.50, 0.1));
	p.push_back(Product("Orange", 120.70, 1.0));

	return p;
}
