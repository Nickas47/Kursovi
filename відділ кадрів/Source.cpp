#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <locale>

using namespace std;
const int SIZEZ = 10;

struct worker {
	char name[40];
	char initials_m[40];
	char initials_f[40];
	int gdate;
	char obr[40];
	char spec[40];
	int pdate;
	int zdate;
} worker[SIZEZ];

void enter(), init_list(), display();
void poisk(), input(int i), zvil();
int menu();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char choice;

	init_list();

	for (;;) {
		choice = menu();
		switch (choice) {
		case 'e': enter();
			break;
		case 'd': display();
			break;
		case 'p': poisk();
			break;
		case 'z': zvil();
			break;
		case 'q': return 0;
		}
	}

	_getch();
	return 0;
}

void init_list()
{
	int t;

	for (t = 0; t < SIZEZ; t++) *worker[t].name = '\0';

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

void enter()
{
	system("cls");
	int i;

	for (i = 0; i < SIZEZ; i++)
		if (!*worker[i].name) break;
	if (i == SIZEZ) {
		cout << "Список повний!\n";
		return;
	}

	input(i);
}

void input(int i)
{
	system("cls");
	cout << "Прізвище: ";
	cin >> worker[i].name;

	cout << "Імя: ";
	cin >> worker[i].initials_m;

	cout << "Побатькові: ";
	cin >> worker[i].initials_f;

	cout << "Рік народження: ";
	cin >> worker[i].gdate;

	cout << "Освіта: ";
	cin >> worker[i].obr;

	cout << "Посада: ";
	cin >> worker[i].spec;

	cout << "Дата початку роботи(Формат ДД.ММ.РР ): ";
	cin >> worker[i].pdate;
}

void poisk()
{
	system("cls");
	int i, count;
	string s;
	char search[80];
	cout << "Введіть дані пошуку: ";
	cin >> search;
	for (i = 0; i < SIZEZ; i++){
		if (strcmp(search, worker[i].name)) {
			continue;
		}
		cout << worker[i].name << '\n';
		cout << worker[i].initials_m << '\n';
		cout << worker[i].initials_f << '\n';
		cout << worker[i].gdate << '\n';
		cout << worker[i].obr << '\n';
		cout << worker[i].spec << '\n';
		cout << worker[i].pdate << '\n';	
		}
	for (i = 0; i < SIZEZ; i++) {
		if (strcmp(search, worker[i].initials_m)) {
			continue;
		}
		cout << worker[i].name << '\n';
		cout << worker[i].initials_m << '\n';
		cout << worker[i].initials_f << '\n';
		cout << worker[i].gdate << '\n';
		cout << worker[i].obr << '\n';
		cout << worker[i].spec << '\n';
		cout << worker[i].pdate << '\n';
	}
	for (i = 0; i < SIZEZ; i++) {
		if (strcmp(search, worker[i].initials_f)) {
			continue;
		}
		cout << worker[i].name << '\n';
		cout << worker[i].initials_m << '\n';
		cout << worker[i].initials_f << '\n';
		cout << worker[i].gdate << '\n';
		cout << worker[i].obr << '\n';
		cout << worker[i].spec << '\n';
		cout << worker[i].pdate << '\n';
	}
	for (i = 0; i < SIZEZ; i++) {
		if (strcmp(search, worker[i].obr)) {
			continue;
		}
		cout << worker[i].name << '\n';
		cout << worker[i].initials_m << '\n';
		cout << worker[i].initials_f << '\n';
		cout << worker[i].gdate << '\n';
		cout << worker[i].obr << '\n';
		cout << worker[i].spec << '\n';
		cout << worker[i].pdate << '\n';
	}
	for (i = 0; i < SIZEZ; i++) {
		if (strcmp(search, worker[i].spec)) {
			continue;
		}
		cout << worker[i].name << '\n';
		cout << worker[i].initials_m << '\n';
		cout << worker[i].initials_f << '\n';
		cout << worker[i].gdate << '\n';
		cout << worker[i].obr << '\n';
		cout << worker[i].spec << '\n';
		cout << worker[i].pdate << '\n';
	}
	system("PAUSE");
	
}

void display()
{
	int t;
	ofstream ut("Співробітники.txt", ios_base::app);
	for (t = 0; t < SIZEZ; t++) {
		if (*worker[t].name) {
			ut << "Прізвище: " << worker[t].name << endl;
			ut << "Імя: " << worker[t].initials_m << endl;
			ut << "Побатькові: " << worker[t].initials_f << endl;
			ut << "Рік народження: ";
			ut << worker[t].gdate << endl;
			ut << "Освіта: " << worker[t].obr << endl;
			ut << "Посада: " ;
			ut << worker[t].spec << endl;
			ut << "Дата початку роботи(ЧЧ:ММ:ГГГГ): ";
			ut << worker[t].pdate << '\n\n';
		}
	}
	ut.close();
	system("PAUSE");
}
void zvil()
{
	system("cls");
	int i;
	char name[80];
	char zdat[80];
	string prich;

	cout << "Введіть прізвище працівника: ";
	cin >> name;
	cout << "\nДата звільнення(Формат ДД.ММ.РР ): ";
	cin >> zdat;
	cout << "\n Причина звільнення: ";
	cin >> prich;
	ofstream out("Архів.txt", ios_base::app);
	for (i = 0; i < SIZEZ; i++)
		if (!strcmp(name, worker[i].name)) {
			out << "Прізвище: " << worker[i].name << '\n';
			out << "Імя: " << worker[i].initials_m << '\n';
			out << "Побатькові: " << worker[i].initials_m << '\n';
			out << "Рік народження: ";
			out << worker[i].gdate << '\n';
			out << "Освіта: " << worker[i].obr << '\n';
			out << "Посада: ";
			out << worker[i].spec << '\n';
			out << "Дата початку роботи(Формат ДД.ММ.РР ): ";
			out << worker[i].pdate << '\n';
			out << "Дата звільнення(Формат ДД.ММ.РР ): ";
			out << zdat << '\n';
			out << "Причина звільнення: ";
			out << prich << '\n\n';
		}
	out.close();
	system("PAUSE");

}