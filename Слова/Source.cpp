#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <cctype> // ��� ispunct()
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream f("input.txt");
	ofstream ot("output.txt");
	int n;
	int k = 0;
	cout << "����� ������� �����:" << endl
		<< "N = ";
	cin >> n;
	do
	{

		char buff[30] = "\0"; // ������ ��� ���������� ����� �� ����� 
		char rezult[30] = "\0"; // ����� ����� ����� ��� ��� ������ ����������
		f >> buff; // ������ �� ����������� ������� 
		if (!f) break; // ���� ����� �����
		// ������� �������� � buff
		for (int i = 0; i < strlen(buff); i++)
		{
			if (!ispunct((unsigned char)(buff[i]))) rezult[i] = buff[i]; // ���� ������ �� ���� ����������, �� � rezult
			cout << rezult[i];
			ot << rezult[i];
		}
		cout <<"=" << strlen(rezult);
		ot << "=" << strlen(rezult);
		cout << endl; // ����� ����� ������������ ��������� � ������������ ����� �� �����. 
		ot << endl;
		if (strlen(rezult) == n)
			k++; 
			

	} while (true);
	cout << "������ ������� ���: " << k << endl;
	ot << "������ ������� ���: " << k << endl;
	f.close();
	ot.close();
	system("pause");
	return 0;
}