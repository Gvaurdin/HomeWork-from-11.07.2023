#include <iostream>
#include <vector>
#include <conio.h>
#include <iomanip> 
#include <string>
#include <algorithm>
#define ROWS 10
#define COLUMNS 10

using namespace std;

class Student {
private:
	string name, family;
	int course;
public:
	Student() { name = "", family = "", course = 0; }
	Student(string name, string family, int course);
	friend ostream& operator << (ostream& os, const Student& s);
	friend void template_vector_with_students(vector<Student>& s);
	friend void Print_vector_students(vector<Student>& s);
	friend bool Compare_Name(const Student& a, const Student& b);
	friend bool Compare_Family(const Student& a, const Student& b);
	friend bool Compare_course(const Student& a, const Student& b);
	friend void Sort_Names_vector(vector<Student>& s);
	friend void Sort_Family_vector(vector<Student>& s);
	friend void Sort_Course_vector(vector<Student>& s);
};

int main()
{
	cout << "Task 1. 10 squares of numbers in a vector\n\n";
	vector <int> vec;
	for (int i = 0, j = 2; i < ROWS; i++, j++)
	{
		vec.push_back(j * j);
	}

	for (int i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	system("cls");
	cout << "Task 2. Multiplication table in a two-dimensional vector\n\n";

	vector<vector<int>> multable(ROWS, vector<int>(COLUMNS));

	for (int i = 1; i <= ROWS; i++) {
		for (int j = 1; j <= COLUMNS; j++) {
			multable.at(i - 1).at(j - 1) = i * j;
		}
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			cout << multable.at(i).at(j) << "\t";
		}
		cout << endl;
	}
	cout << endl;
	system("pause");
	system("cls");

	cout << "Task 3. Class Student - Print, Sort, Vector\n\n";
	cout << "Create and print vector Students" <<
		"\n=====================================\n";
	vector<Student> st;
	template_vector_with_students(st);
	Print_vector_students(st);
	cout << "\n======================SORT_NAME=======================\n";
	Sort_Names_vector(st);
	Print_vector_students(st);
	cout << "\n======================SORT_FAMILY=======================\n";
	Sort_Family_vector(st);
	Print_vector_students(st);
	cout << "\n======================SORT_COURSE=======================\n";
	Sort_Course_vector(st);
	Print_vector_students(st);
	system("pause");
}

Student::Student(string name, string family, int course)
{
	this->family = family;
	this->name = name;
	this->course = course;
}

ostream& operator<<(ostream& os, const Student& s)
{
	os << left << setw(15) << s.name <<
		left << setw(12) << s.family << s.course << endl;
	return os;
}

void template_vector_with_students(vector<Student>& s)
{
	s.push_back(Student("Ivan", "Komarov", 1));
	s.push_back(Student("Arkadiy", "Petrov", 3));
	s.push_back(Student("Maxim", "Goncharov", 2));
	s.push_back(Student("Fedor", "Losev", 1));
	s.push_back(Student("Viktor", "Lukin", 2));
	s.push_back(Student("Nikolay", "Kuzmin", 1));
}

void Print_vector_students(vector<Student>& s)
{
	cout << left << setw(15) << "Name" <<
		left << setw(12) << "Family" << "Course" <<
		"\n======================================================\n";
	for (const Student& st : s)
	{
		cout << st;
	}
}

bool Compare_Name(const Student& a, const Student& b)
{
	return a.name < b.name;
}

bool Compare_Family(const Student& a, const Student& b)
{
	return a.family < b.family;
}

bool Compare_course(const Student& a, const Student& b)
{
	return a.course < b.course;
}

void Sort_Names_vector(vector<Student>& s)
{
	try
	{
		if (s.empty())
		{
			throw range_error("Your vector is empty\n");
		}
		else
		{
			sort(s.begin(), s.end(), Compare_Name);
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

void Sort_Family_vector(vector<Student>& s)
{
	try
	{
		if (s.empty())
		{
			throw range_error("Your vector is empty\n");
		}
		else
		{
			stable_sort(s.begin(), s.end(), Compare_Family);
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

void Sort_Course_vector(vector<Student>& s)
{
	try
	{
		if (s.empty())
		{
			throw range_error("Your vector is empty\n");
		}
		else
		{
			partial_sort(s.begin(), s.begin() + 3, s.end(), Compare_course);
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}


