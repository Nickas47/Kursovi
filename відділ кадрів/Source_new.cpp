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
		cout << "(E)Ввід\n";
		cout << "(D)Для запису у файл\n";
		cout << "(P)Пошук\n";
		cout << "(Z)Звільнення\n";
		cout << "(Q)Вихід\n";
		cout << "Виберіть команду: ";
		cin >> ch;
	} while (!strchr("edpzuq", tolower(ch)));

	return tolower(ch);
}

void input()
{
	system("cls");
	int i = Employee_Count++;

	cout << "Прізвище: ";
	cin >> Employee[i].first_name;

	cout << "Імя: ";
	cin >> Employee[i].second_name;

	cout << "Побатькові: ";
	cin >> Employee[i].family_name;

	cout << "Рік народження: ";
	cin >> Employee[i].g_date;

	cout << "Освіта: ";
	cin >> Employee[i].obr;

	cout << "Посада: ";
	cin >> Employee[i].spec;

	cout << "Дата початку роботи(Формат ДДММРР ): ";
	cin >> Employee[i].pdate;
}

void search()
{
	system("cls");
	int i = 0;
	struct Employee emp;
	string search_name, in_line, name;

	cout << "Введіть дані пошуку: ";
	cin >> search_name;

	ifstream in("Text.txt");
	while (!in.eof())
	{
		getline(in, in_line);

		if (!in_line.empty())
		{
			name = in_line.substr(string("Прізвище: ").length());
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
			emp.first_name = in_line.substr(string("Імя: ").length());
		else if (i == 2)
			emp.family_name = in_line.substr(string("По-батькові: ").length());
		else if (i == 3)
			emp.obr = in_line.substr(string("Освіта: ").length());
		else if (i == 4)
			emp.spec = in_line.substr(string("Посада: ").length());


		i++;
		if (!in_line.empty() && in_line.find("Прізвище: ") == 0)
		{
			break;
		}
	}

	if (i == 0)
		cout << "Нічого не знайдено." << endl;

	system("PAUSE");
}

void output()
{
	int t;
	ofstream out("Співробітники.txt", ios_base::app);
	for (t = 0; t < SIZE; t++)
	{
		if (!Employee[t].first_name.empty())
		{
			out << "Прізвище: " << Employee[t].second_name << endl;
			out << "Імя: " << Employee[t].first_name << endl;
			out << "По-батькові: " << Employee[t].family_name;
			out << "\nРік народження: " << Employee[t].g_date << endl;
			out << "Освіта: " << Employee[t].obr << endl;
			out << "Посада: " << Employee[t].spec << endl;
			out << "Дата початку роботи(Формат ДДММРР ): " << Employee[t].pdate << endl << endl;
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

	cout << "Введіть прізвище працівника: ";
	cin >> name;
	cout << "\nДата звільнення(Формат ДДММРР ): ";
	cin >> zdat;
	cout << "\n Причина звільнення: ";
	cin >> reason;
	ofstream out("Архів.txt", ios_base::app);
	for (i = 0; i < SIZE; i++)
	{
		if (name != Employee[i].first_name)
		{
			out << "Прізвище: " << Employee[i].second_name << endl;
			out << "Імя: " << Employee[i].first_name << endl;
			out << "Побатькові: " << Employee[i].family_name << endl;
			out << "Рік народження: ";
			out << Employee[i].g_date << endl;
			out << "Освіта: " << Employee[i].obr << endl;
			out << "Посада: ";
			out << Employee[i].spec << endl;
			out << "Дата початку роботи(Формат ДДММРР ): ";
			out << Employee[i].pdate << endl;
			out << "Дата звільнення(Формат ДДММРР ): ";
			out << zdat << endl;
			out << "Причина звільнення: ";
			out << reason << endl;
		}
	}

	out.close();
	system("PAUSE");
}