#include "Buy.h"
#include "Product.h"

ostream& operator << (ostream& os, Buy& b)
{
	b.Print_Product();
	cout << left << setw(5) << b.count;
	b.Convert_price(b.sum_price);
	b.Convert_weight(b.sum_weight);
	cout << "\n======================================================" <<
		"========================================\n";
	return os;
}

void Buy::Set_count(int _count)
{
	count = _count;
}

void Buy::Calculate_sum_price_weight()
{
	sum_price = 0; sum_weight = 0;
	sum_price = price * count;
	sum_weight = weight * count;
}

void Buy::Print_order()
{
	Print_Product();
	cout << left << setw(5) << count;
	Convert_price(sum_price);
	Convert_weight(sum_weight);
	cout << "\n======================================================" <<
		"========================================\n";
}
