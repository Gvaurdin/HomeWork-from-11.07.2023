#include <iostream>
#include <iomanip> 
#include <string>
#include<Windows.h>
#include <vector>
#include <map>

using namespace std;

void Func_Country();

int main()
{
	Func_Country();
}

void Func_Country()
{
	map<string,vector<string>> countries;
	countries["Russia"] = { "Moscow","Saint Peterburg","Kaliningrad","Kazan"};
	countries["USA"] = { "Washington","Los Angeles","New York", "Las Vegas"};
	countries["Germany"] = { "Berlin", "Munich", "Hamburg" };
	countries["China"] = { "Beijing", "Shanghai", "Guangzhou" };
	countries["Italy"] = { "Rome", "Milan", "Naples" };
	char menu{};
	while (menu != '5')
	{
		system("cls");
		cout << "Enter 1 to display a list of countries with cities\n" <<
			"Enter 2 to display the capital for a given country\n" <<
			"Enter 3 to find a country by a given city\n" <<
			"Enter 4 to add country, capital of cuontry and cities of the country\n" <<
			"Enter 5 to exit from programm\n" <<
			"Select action : ";
		cin >> menu;
		try
		{
			if (menu != '1' && menu != '2' && menu != '3' &&
				menu != '4' && menu != '5')
			{
				throw invalid_argument("Error input action....");
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what();
		}

		switch (menu)
		{
		case '1':
		{
			system("cls");
			cout << "List of countries and cities :\n";
			map<string, vector <string>>::iterator it;
			for (it = countries.begin(); it != countries.end(); it++)
			{
				cout << "Country : " << it->first << endl <<
					"Capital : " << it->second[0] << endl <<
					"Other cities of the country : ";
				for (int i = 1; i < it->second.size(); i++)
				{
					cout << it->second[i] << " , ";
					if (i == it->second.size() - 1) cout << it->second[i] << '.';
				}
				cout << "\n==========================================================\n";
			}
			system("pause");
		}
			break;
		case '2':
		{
			system("cls");
			string find_country;
			cout << "\nEnter the name of the country to find out the capital : ";
			cin >> find_country;
			map<string, vector <string>>::iterator it;
			it = countries.find(find_country);
			try
			{
				if (it != countries.end() && !it->second.empty()) 
				{
					cout << "The capital of " << find_country << " - " << it->second[0] << endl;
					system("pause");
				}
				else
				{
					throw invalid_argument("Error input country\n");
				}
			}
			catch (const std::exception& e)
			{
				cout << e.what() <<
					"Country " << find_country << " not found or incorrectly entered\n";
				system("pause");
			}
		}
		break;
		case '3':
		{
			system("cls");
			string in_city;
			cout << "\nEnter the name of the city to find the country : ";
			cin >> in_city;

			bool city = false;
			map<string, vector <string>>::iterator it;
			for (it = countries.begin(); it != countries.end(); it++) {
				for (int i = 0; i < it->second.size(); i++) {
					if (it->second[i] == in_city) {
						cout << "City " << in_city << " is located in the country of " << it->first << endl;
						city = true;
						break;
					}
				}
				if (city) {
					break;
				}
			}
			try
			{
				if (!city)
				{
					throw invalid_argument("No country found for the entered city\n");
				}
			}
			catch (const std::exception& e)
			{
				cout << e.what();
				system("pause");
			}
			system("pause");
		}
		break;
		case '4':
		{
			system("cls");
			string country, capital;
			vector <string> cities;
			int count{};
			cout << "Add a new country to the container.\n";
			cout << "Enter the name of the country : ";
			cin >> country;
			cout << "Enter the name capital of this country : ";
			cin >> capital;
			try
			{
				cout << "Enter to count cities of this country : ";
				cin >> count;
				if (count < 0 || count > 10 || !count)
				{
					cin.clear();
					throw invalid_argument("Error input count cities\n");
				}
			}
			catch (const std::exception& e)
			{
				cout << e.what();
				Sleep(2000);
				break;
			}
			for (int i = 0; i < count; i++)
			{
				string tmp;
				cout << "Enter name of " << " [" << i + 1 << "] " << "city : ";
				cin >> tmp;
				cities.push_back(tmp);
			}
			countries[country] = cities;
			countries[country].insert(countries[country].begin(), capital);
			cout << "Please, wait...........\n";
			Sleep(1500);
			system("cls");
			cout << "Updated list of countries and cities\n";
			map<string, vector <string>>::iterator it;
			for (it = countries.begin(); it != countries.end(); it++)
			{
				cout << "Country : " << it->first << endl <<
					"Capital : " << it->second[0] << endl <<
					"Other cities of the country : ";
				for (int i = 1; i < it->second.size(); i++)
				{
					if (i == it->second.size() - 1 ||
						i == it->second.size() - 1 &&
						it->second.size()-1 == 1) cout << it->second[i] << '.';
					else cout << it->second[i] << " , ";
				}
				cout << "\n==========================================================\n";
			}
			system("pause");
		}
		break;
		case '5':
		{
			system("cls");
			cout << "Exit from programm....\n";
			Sleep(1500);
		}
		break;
		}
	}
}
