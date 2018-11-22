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

void enter()
{
	system("cls");
	int i;

	for (i = 0; i < SIZEZ; i++)
		if (!*worker[i].name) break;
	if (i == SIZEZ) {
		cout << "������ ������!\n";
		return;
	}

	input(i);
}

void input(int i)
{
	system("cls");
	cout << "�������: ";
	cin >> worker[i].name;

	cout << "���: ";
	cin >> worker[i].initials_m;

	cout << "���������: ";
	cin >> worker[i].initials_f;

	cout << "г� ����������: ";
	cin >> worker[i].gdate;

	cout << "�����: ";
	cin >> worker[i].obr;

	cout << "������: ";
	cin >> worker[i].spec;

	cout << "���� ������� ������(������ ��.��.�� ): ";
	cin >> worker[i].pdate;
}

void poisk()
{
	system("cls");
	int i, count;
	string s;
	char search[80];
	cout << "������ ��� ������: ";
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
	ofstream ut("�����������.txt", ios_base::app);
	for (t = 0; t < SIZEZ; t++) {
		if (*worker[t].name) {
			ut << "�������: " << worker[t].name << endl;
			ut << "���: " << worker[t].initials_m << endl;
			ut << "���������: " << worker[t].initials_f << endl;
			ut << "г� ����������: ";
			ut << worker[t].gdate << endl;
			ut << "�����: " << worker[t].obr << endl;
			ut << "������: " ;
			ut << worker[t].spec << endl;
			ut << "���� ������� ������(��:��:����): ";
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

	cout << "������ ������� ����������: ";
	cin >> name;
	cout << "\n���� ���������(������ ��.��.�� ): ";
	cin >> zdat;
	cout << "\n ������� ���������: ";
	cin >> prich;
	ofstream out("�����.txt", ios_base::app);
	for (i = 0; i < SIZEZ; i++)
		if (!strcmp(name, worker[i].name)) {
			out << "�������: " << worker[i].name << '\n';
			out << "���: " << worker[i].initials_m << '\n';
			out << "���������: " << worker[i].initials_m << '\n';
			out << "г� ����������: ";
			out << worker[i].gdate << '\n';
			out << "�����: " << worker[i].obr << '\n';
			out << "������: ";
			out << worker[i].spec << '\n';
			out << "���� ������� ������(������ ��.��.�� ): ";
			out << worker[i].pdate << '\n';
			out << "���� ���������(������ ��.��.�� ): ";
			out << zdat << '\n';
			out << "������� ���������: ";
			out << prich << '\n\n';
		}
	out.close();
	system("PAUSE");

}