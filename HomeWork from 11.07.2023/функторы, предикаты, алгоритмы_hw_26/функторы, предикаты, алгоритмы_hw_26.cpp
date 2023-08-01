#include <iostream>
#include <iomanip> 
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class MinFinder {
public:
	int operator()(vector<int>& v);
};

class MaxFinder {
public:
	int operator()(vector<int>& v);
};

class CompareSort
{
public:
	bool operator () (int n1, int n2)
	{
		return n1 < n2;
	}
};

class DescendingSorter {
public:
	void operator()(vector<int>& v);
};

class AscendingSorter {
public:
	void operator()(std::vector<int>& v);
};

class AddConst {
private:
	int value;

public:
	AddConst(int val) : value(val) {}

	void operator()(vector<int>& v);
};

class SubstractionConst {
private:
	int value;

public:
	SubstractionConst(int val) : value(val) {}
	void operator()(vector<int>& v);
};

class ValueErase {
private:
	int value;

public:
	ValueErase(int val) : value(val) {}

	void operator()(vector<int>& v);
};

void Func_Main();


int main()
{
	Func_Main();
}

int MinFinder::operator()(vector<int>& v)
{
	try
	{
		if (v.empty()) {
			throw runtime_error("Error.v is empty!\n");
		}
		int min = v[0];
		for (int i = 1; i < v.size(); ++i) {
			if (v[i] < min) {
				min = v[i];
			}
		}
		return min;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
		system("pause");
	}
}

int MaxFinder::operator()(vector<int>& v)
{
	try
	{
		if (v.empty()) {
			throw runtime_error("Error.v is empty!\n");
		}
		int max = v[0];
		for (int i = 1; i < v.size(); ++i) {
			if (v[i] > max) {
				max = v[i];
			}
		}
		return max;
	}
	catch (const std::exception& e)
	{
		cout << e.what();
		system("pause");
	}
}

void DescendingSorter::operator()(vector<int>& v)
{
	CompareSort c_sort;
	sort(v.begin(), v.end(), c_sort);
}

void AscendingSorter::operator()(std::vector<int>& v)
{
	sort(v.begin(), v.end());
}

void AddConst::operator()(vector<int>& v)
{
	for (int& num : v) 
	{
		num += value;
	}
}

void SubstractionConst::operator()(vector<int>& v)
{
	for (int& num : v)
	{
		num -= value;
	}
}

void ValueErase::operator()(vector<int>& v)
{
	v.erase(remove(v.begin(), v.end(), value), v.end());
}

void Func_Main()
{
	vector<int> vector = { 5,8,-2,10,-6,36,100,56,99,-120,0 };
	cout << "Your vector :";
	for (int& i : vector)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "1.Find min and max element in vector\n";
	MinFinder minf;
	int min = minf(vector);
	cout << "Min value in vector : " << min << endl;
	MaxFinder maxf;
	int max = maxf(vector);
	cout << "Max value in vector : " << max << endl;
	system("pause");
	system("cls");
	cout << "Your vector :";
	for (int& i : vector)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "2.Sorting the vector in descending and ascending order\n";
	DescendingSorter d_sort;
	d_sort(vector);
	cout << "Sorting descending : ";
	for (int& i : vector)
	{
		cout << i << " ";
	}
	cout << "\n==============================================================\n";
	AscendingSorter a_sort;
	a_sort(vector);
	cout << "Sort ascending : ";
	for (int& i : vector)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << "Your vector :";
	for (int& i : vector)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "3.Increasing and decreasing values in a vector by a given constant\n";
	AddConst add(10);
	add(vector);
	cout << "Vector with increased values :";
	for (int& i : vector)
	{
		cout << i << " ";
	}
	cout << "\n=======================================================\n";
	SubstractionConst sub(15);
	sub(vector);
	cout << "Vector with reduced values :";
	for (int& i : vector)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
}
