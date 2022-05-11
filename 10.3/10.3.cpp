#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
	string last_name;
	int prog;
	int math;
	int phys;
};

void enter_save(char* fname);
void load_print(char* fname);
int main()
{
	char fname[61];
	char ftelephone[151];
	char ch;
	do
	{
		cout << "--------------------------------\n";
		cout << "Main Menu\n";
		cout << "Please make your selection\n" << endl;
		cout << "[1] - Enter & Save Data\n" << endl;
		cout << "[2] - Load & Print Data\n" << endl;
		cout << "[0] - Exit\n";
		cout << "--------------------------------\n";
		cout << "Your Choise: "; cin >> ch;
		switch (ch)
		{
		case '0':
			cout << "Goodbye! See Ya Later, Aligator!!!";
			break;
		case '1':
			cout << "You Chosen [1] - Enter & Save Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			enter_save(fname);
			break;
		case '2':
			cout << "You Chosen [2] - Load & Print Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			load_print(fname);
			break;
		default:
			cout << endl;
			cout << "--------------------------------\n";
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "[1] - Enter & Save Data\n" << endl;
			cout << "[2] - Load & Print Data\n" << endl;
			cout << "[0] - Exit\n";
			cout << "--------------------------------\n";
			cout << "Your Choise: "; cin >> ch;
		}
	} while (ch != '0');
	return 0;
}
void enter_save(char* fname)
{
	ofstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}
	Student s;
	char ch;
	do
	{
		cout << endl;
		cout << "Last Name: "; cin.sync();
		cin >> s.last_name;
		cout << "Programming: ";
		cin >> s.prog;
		cout << "Mathematics: ";
		cin >> s.math;
		cout << "Physics: ";
		cin >> s.phys;

		if (!f.write((char*)&s, sizeof(Student)))
		{
			cerr << "Error writing file." << endl;
		}
		cout << "Continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}
void load_print(char* fname)
{
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << fname << "'" << endl;
		return;
	}

	Student s;
	while (f.read((char*)&s, sizeof(Student)))
	{
		cout << endl;
		cout << "Last Name: " << s.last_name << endl;
		cout << "Programming: " << s.prog << endl;
		cout << "Mathematics: " << s.math << endl;
		cout << "Physics: " << s.phys << endl;
	}
}