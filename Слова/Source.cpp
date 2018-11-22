#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <cctype> // для ispunct()
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream f("input.txt");
	ofstream ot("output.txt");
	int n;
	int k = 0;
	cout << "Ведіть довжину слова:" << endl
		<< "N = ";
	cin >> n;
	do
	{

		char buff[30] = "\0"; // массив для считывания слова из файла 
		char rezult[30] = "\0"; // здесь будет слово уже без знаков пунктуации
		f >> buff; // чтение до пробельного символа 
		if (!f) break; // если конец файла
		// перебор символов в buff
		for (int i = 0; i < strlen(buff); i++)
		{
			if (!ispunct((unsigned char)(buff[i]))) rezult[i] = buff[i]; // если символ не знак пунктуации, то в rezult
			cout << rezult[i];
			ot << rezult[i];
		}
		cout <<"=" << strlen(rezult);
		ot << "=" << strlen(rezult);
		cout << endl; // здесь можно использовать считанное и обработанное слово из файла. 
		ot << endl;
		if (strlen(rezult) == n)
			k++; 
			

	} while (true);
	cout << "Заданої довжини слів: " << k << endl;
	ot << "Заданої довжини слів: " << k << endl;
	f.close();
	ot.close();
	system("pause");
	return 0;
}