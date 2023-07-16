#include "Shop.h"
#include "Buy.h"
#include "Check.h"
#include "Product.h"


void Shop::Print_Price_list()
{
	cout << "=============PRICE LIST================\n";
	cout << left << setw(3) << "ID" << left << setw(20) << "Product" <<
		left << setw(22) << "Price" << "Weight\n" <<
		"------------------------------------------------------\n";
	int count = 1;
	for (Product& p : price_list)
	{
		cout << left << setw(3) << count << p;
		count++;
	}
}

void Shop::Print_Price_Element(int index)
{
}

void Shop::Print_Order_list()
{
	gotoxy(25, 0);
	cout << "=============ORDER LIST================\n\n";
	gotoxy(0, 1);
	cout << left << setw(3) << "ID" << left << setw(20) << "Product" <<
		left << setw(17) << "Price" << left << setw(16) << "Weight" <<
		left << setw(8) << "Count" << left << setw(18) << "Total price" << "Total weight" <<
		"\n----------------------------------------------------------" <<
		"------------------------------------\n";
	int count = 1;
	for (Buy& b : buy_order)
	{
		cout << left << setw(3) << count << b;
		count++;
	}
}

void Shop::Change_Order_list()
{
	int index{};
	cout << "Enter the item number of the product you want to change or delete :";
	cin >> index;
	index--;
	if (index < 0 || index > buy_order.size() - 1)
	{
		cout << "Error.No order with this index was found\n";
		return;
	}
	else
	{
		char action{};
		cout << "Enter 1 if you want to change the number of products in the item  " <<
			", enter 2 if you want to delete the item\n" <<
			"Enter action : ";
		cin >> action;
		while (action != '1' && action != '2')
		{
			cout << "Error input\n" <<
				"Try enter again : ";
			cin >> action;
		}
		if (action == '1')
		{
			short count{};
			cout << "Enter to new count of products for this position : ";
			cin >> count;
			try
			{
				if (count < 0 || count > 5)
				{
					throw invalid_argument("Error input\n");
				}
				else
				{
					buy_order.at(index).Set_count(count);
					buy_order.at(index).Calculate_sum_price_weight();
					cout << "The number of products for the selected " <<
						"item has been successfully changed\n";
					Sleep(1000);
				}
			}
			catch (const std::exception& e)
			{
				cout << e.what();
				system("pause");
				system("cls");
			}
		}
		else if (action == '2')
		{
			vector<Buy>::iterator it = buy_order.begin();
			buy_order.erase(it + (index));
			cout << "The selected position has been successfully deleted\n";
			Sleep(1000);
		}
	}
	system("cls");
}

double Shop::Total_sum_price()
{
	double total_sum_price{};
	for (Buy& b : buy_order)
	{
		total_sum_price += b.Get_count() * b.Get_price();
	}
	return total_sum_price;
}

void Shop::Print_Check()
{
	gotoxy(25, 0);
	cout << "============= CHECK ================\n\n";
	gotoxy(0, 1);
	cout << left << setw(3) << "ID" << left << setw(20) << "Product" <<
		left << setw(17) << "Price" << left << setw(16) << "Weight" <<
		left << setw(8) << "Count" << left << setw(18) << "Total price" << "Total weight" <<
		"\n----------------------------------------------------------" <<
		"------------------------------------\n";
	int count = 1;
	for (Check& c : check)
	{
		cout << left << setw(3) << count << c;
		count++;
	}
	Check tmp;
	cout << "Total price : ";
    tmp.Convert_price(this->Total_sum_price());

}

void Shop::Clear_order_check()
{
	buy_order.clear();
	check.clear();
}

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


void func_menu()
{
	int k = 1;
	char en = 0;
	int count_price{};
	Shop shop;
	vector<Product> p;
	vector<Buy> b;
	vector <Check> ch;
	List_Products_Shop(p);
	for (Product& product : p)
	{
		shop.SetProduct(product);
	}
	do
	{
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 5)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 4;
		}
		if (en == 13)
		{
			if (k == 1)
			{
				system("cls");
				int _en = 0;
				int _k = 1;
				do
				{
					cout << endl;
					if (_en == 80)
					{
						_k++;
						if (_k == 8)
							_k = 1;
					}
					if (_en == 72)
					{
						_k--;
						if (_k == 0)
							_k = 8;
					}
					if (_en == 13)
					{
						if (_k == 1)
						{
							try
							{
								cout << "Enter to count this product : ";
								cin >> count_price;
								if (count_price < 0 || count_price > 5)
								{
									throw invalid_argument("Error input\n");
								}
								else
								{
									shop.SetOrder(Buy(p.at(0).Get_name(), p.at(0).Get_price(),
										p.at(0).Get_weight(), count_price));
									cout << "Product succefull add\n";
									count_price = 0;
									Sleep(1000);
									system("cls");
								}
							}
							catch (const std::exception& e)
							{
								cout << e.what();
								system("pause");
								system("cls");
							}
						}
						if (_k == 2)
						{
							try
							{
								cout << "Enter to count this product : ";
								cin >> count_price;
								if (count_price < 0 || count_price > 5)
								{
									throw invalid_argument("Error input\n");
								}
								else
								{
									shop.SetOrder(Buy(p.at(1).Get_name(), p.at(1).Get_price(),
										p.at(1).Get_weight(), count_price));
									cout << "Product succefull add\n";
									count_price = 0;
									Sleep(1000);
									system("cls");
								}
							}
							catch (const std::exception& e)
							{
								cout << e.what();
								system("pause");
								system("cls");
							}
						}


						if (_k == 3)
						{
							try
							{
								cout << "Enter to count this product : ";
								cin >> count_price;
								if (count_price < 0 || count_price > 5)
								{
									throw invalid_argument("Error input\n");
								}
								else
								{
									shop.SetOrder(Buy(p.at(2).Get_name(), p.at(2).Get_price(),
										p.at(2).Get_weight(), count_price));
									cout << "Product succefull add\n";
									count_price = 0;
									Sleep(1000);
									system("cls");
								}
							}
							catch (const std::exception& e)
							{
								cout << e.what();
								system("pause");
								system("cls");
							}

						}

						if (_k == 4)
						{

							try
							{
								cout << "Enter to count this product : ";
								cin >> count_price;
								if (count_price < 0 || count_price > 5)
								{
									throw invalid_argument("Error input\n");
								}
								else
								{
									shop.SetOrder(Buy(p.at(3).Get_name(), p.at(3).Get_price(),
										p.at(3).Get_weight(), count_price));
									cout << "Product succefull add\n";
									count_price = 0;
									Sleep(1000);
									system("cls");
								}
							}
							catch (const std::exception& e)
							{
								cout << e.what();
								system("pause");
								system("cls");
							}
						}
						if (_k == 5)
						{

							try
							{
								cout << "Enter to count this product : ";
								cin >> count_price;
								if (count_price < 0 || count_price > 5)
								{
									throw invalid_argument("Error input\n");
								}
								else
								{
									shop.SetOrder(Buy(p.at(4).Get_name(), p.at(4).Get_price(),
										p.at(4).Get_weight(), count_price));
									cout << "Product succefull add\n";
									count_price = 0;
									Sleep(1000);
									system("cls");
								}
							}
							catch (const std::exception& e)
							{
								cout << e.what();
								system("pause");
								system("cls");
							}
						}
						if (_k == 6)
						{

							try
							{
								cout << "Enter to count this product : ";
								cin >> count_price;
								if (count_price < 0 || count_price > 5)
								{
									throw invalid_argument("Error input\n");
								}
								else
								{
									shop.SetOrder(Buy(p.at(5).Get_name(), p.at(5).Get_price(),
										p.at(5).Get_weight(), count_price));
									cout << "Product succefull add\n";
									count_price = 0;
									Sleep(1000);
									system("cls");
								}
							}
							catch (const std::exception& e)
							{
								cout << e.what();
								system("pause");
								system("cls");
							}
						}
						if (_k == 7)
						{
							cout << "Close price list......\n";
							break;
						}

					}
					SetColor(11);
					gotoxy(0, 0);
					cout << "=============PRICE LIST================\n";
					gotoxy(0, 1);
					cout << left << setw(3) << "ID" << left << setw(20) << "Product" <<
						left << setw(22) << "Price" << "Weight\n" <<
						"------------------------------------------------------\n";
					SetColor(7);
					if (_k == 1)
						SetColor(13);
					gotoxy(0, 3);
					cout << p.at(0);
					SetColor(7);

					if (_k == 2)
						SetColor(13);
					gotoxy(0, 5);
					cout << p.at(1);
					SetColor(7);
					if (_k == 3)
						SetColor(13);
					gotoxy(0, 7);
					cout << p.at(2);
					SetColor(7);
					if (_k == 4)
						SetColor(13);
					gotoxy(0, 9);
					cout << p.at(3);
					SetColor(7);
					if (_k == 5)
						SetColor(13);
					gotoxy(0, 11);
					cout << p.at(4);
					SetColor(7);
					if (_k == 6)
						SetColor(13);
					gotoxy(0, 13);
					cout << p.at(5);
					SetColor(7);
					if (_k == 7)
						SetColor(13);
					gotoxy(0, 15);
					cout << "Close price list\n";
					SetColor(7);
				} while (_en = _getch());
			}
			system("cls");
			if (k == 2)
			{
				system("cls");
				char menu{};
				bool flag = true;
				if (!shop.Get_buy_order().empty())
				{
					while (flag)
					{
						shop.Print_Order_list();
						cout << "Enter 1 to change or delete the purchase position\n" <<
							"Enter 2 to exit from order list\n" <<
							"Enter action : ";
						cin >> menu;
						switch (menu)
						{
						case '1':
						{
							shop.Change_Order_list();
						}
						break;
						case '2':
						{
							system("cls");
							cout << "Exit from order list\n";
							flag = false;
						}
						break;
						default:
							cout << "Error!\n";
							break;
						}
					}
				}
				else
				{
					cout << "You not add products to order list!\n";
					Sleep(1500);
				}

				system("cls");
			}
			if (k == 3)
			{
				if (!shop.Get_buy_order().empty())
				{
					for (Buy b : shop.Get_buy_order())
					{
						shop.Set_Check(Check(b.Get_name(), b.Get_price(), b.Get_weight(),
							b.Get_count()));
					}

					shop.Print_Check();
					cout << "Suceffully operation\n";
					Sleep(1500);
					shop.Clear_order_check();
				}
				else
				{
					cout << "Order not created!\n";
					Sleep(1500);
				}
			}

			if (k == 4)
			{
				cout << "Exit from programm....\n";
				Sleep(1000);
				break;
			}

		}
		system("cls");
		gotoxy(28, 0);
		SetColor(11);
		cout << "Shop Magnit\n";
		SetColor(7);
		if (k == 1)
			SetColor(13);
		gotoxy(15, 2);
		cout << "1. Show the list of products and add the selected products to the order" << endl;
		SetColor(7);

		if (k == 2)
			SetColor(13);
		gotoxy(15, 3);
		cout << "2. Show an order with selected products " << endl;
		SetColor(7);
		if (k == 3)
			SetColor(13);
		gotoxy(15, 4);
		cout << "3. Place an order and make a purchase " << endl;
		SetColor(7);
		if (k == 4)
			SetColor(13);
		gotoxy(15, 5);
		cout << "4. Exit the shop " << endl;
		SetColor(7);
	} while (en = _getch());
}


