#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
#define SIZE 10

unsigned int Employee_Count = 0;

struct Employee
{
	string first_name;
	string second_name;
	string family_name;
	int g_date;
	string obr;
	string spec;
	int pdate;
	int zdate;
} Employee[SIZE];

void enter();
void input();
void output();
void search();
void dismissal();
int menu();

int main()
{
	setlocale(LC_ALL, "");

	char choice;

	for (;;)
	{
		choice = menu();
		switch (choice)
		{
		case 'e': input();
			break;
		case 'd': output();
			break;
		case 'p': search();
			break;
		case 'z': dismissal();
			break;
		case 'q': return 0;
		}
	}

	return 0;
}

int menu()
{
	system("cls");
	char ch;
	do {
		cout << "(E)���\n";
		cout << "(D)��� ������ � ����\n";
		cout << "(P)�����\n";
		cout << "(Z)���������\n";
		cout << "(Q)�����\n";
		cout << "������� �������: ";
		cin >> ch;
	} while (!strchr("edpzuq", tolower(ch)));

	return tolower(ch);
}

void input()
{
	system("cls");
	int i = Employee_Count++;

	cout << "�������: ";
	cin >> Employee[i].first_name;

	cout << "���: ";
	cin >> Employee[i].second_name;

	cout << "���������: ";
	cin >> Employee[i].family_name;

	cout << "г� ����������: ";
	cin >> Employee[i].g_date;

	cout << "�����: ";
	cin >> Employee[i].obr;

	cout << "������: ";
	cin >> Employee[i].spec;

	cout << "���� ������� ������(������ ������ ): ";
	cin >> Employee[i].pdate;
}

void search()
{
	system("cls");
	int i = 0;
	struct Employee emp;
	string search_name, in_line, name;

	cout << "������ ��� ������: ";
	cin >> search_name;

	ifstream in("Text.txt");
	while (!in.eof())
	{
		getline(in, in_line);

		if (!in_line.empty())
		{
			name = in_line.substr(string("�������: ").length());
			if (!name.empty() && name == search_name)
			{
				emp.second_name = name;
				cout << in_line << endl;
				i++;
				break;
			}
		}
	}

	while (!in.eof())
	{
		getline(in, in_line);
		cout << in_line << endl;

		if (i == 1)
			emp.first_name = in_line.substr(string("���: ").length());
		else if (i == 2)
			emp.family_name = in_line.substr(string("��-�������: ").length());
		else if (i == 3)
			emp.obr = in_line.substr(string("�����: ").length());
		else if (i == 4)
			emp.spec = in_line.substr(string("������: ").length());


		i++;
		if (!in_line.empty() && in_line.find("�������: ") == 0)
		{
			break;
		}
	}

	if (i == 0)
		cout << "ͳ���� �� ��������." << endl;

	system("PAUSE");
}

void output()
{
	int t;
	ofstream out("�����������.txt", ios_base::app);
	for (t = 0; t < SIZE; t++)
	{
		if (!Employee[t].first_name.empty())
		{
			out << "�������: " << Employee[t].second_name << endl;
			out << "���: " << Employee[t].first_name << endl;
			out << "��-�������: " << Employee[t].family_name;
			out << "\nг� ����������: " << Employee[t].g_date << endl;
			out << "�����: " << Employee[t].obr << endl;
			out << "������: " << Employee[t].spec << endl;
			out << "���� ������� ������(������ ������ ): " << Employee[t].pdate << endl << endl;
		}
	}

	out.close();
	system("PAUSE");
}
void dismissal()
{
	system("cls");

	int i;
	string name;
	string zdat;
	string reason;

	cout << "������ ������� ����������: ";
	cin >> name;
	cout << "\n���� ���������(������ ������ ): ";
	cin >> zdat;
	cout << "\n ������� ���������: ";
	cin >> reason;
	ofstream out("�����.txt", ios_base::app);
	for (i = 0; i < SIZE; i++)
	{
		if (name != Employee[i].first_name)
		{
			out << "�������: " << Employee[i].second_name << endl;
			out << "���: " << Employee[i].first_name << endl;
			out << "���������: " << Employee[i].family_name << endl;
			out << "г� ����������: ";
			out << Employee[i].g_date << endl;
			out << "�����: " << Employee[i].obr << endl;
			out << "������: ";
			out << Employee[i].spec << endl;
			out << "���� ������� ������(������ ������ ): ";
			out << Employee[i].pdate << endl;
			out << "���� ���������(������ ������ ): ";
			out << zdat << endl;
			out << "������� ���������: ";
			out << reason << endl;
		}
	}

	out.close();
	system("PAUSE");
}