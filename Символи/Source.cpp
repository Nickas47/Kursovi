#include <stdio.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0, s10 = 0;
	int s11 = 0, s12 = 0, s13 = 0, s14 = 0, s15 = 0, s16 = 0, s17 = 0, s18 = 0, s19 = 0, s20 = 0;
	int s21 = 0, s22 = 0, s23 = 0, s24 = 0, s25 = 0, s26 = 0, s27 = 0, s28 = 0, s29 = 0, s30 = 0;
	int s31 = 0, s32=0, s33 = 0;

	char ch;
	ifstream fin("Текст.txt"); 
	while (fin.get(ch))
	{
		if (ch == 'а' || ch == 'А')
			s1++;
		else if(ch == 'б' || ch == 'Б')
			s2++;
		else if (ch == 'в' || ch == 'В')
			s3++;
		else if (ch == 'г' || ch == 'Г')
			s4++;
		else if (ch == 'ґ' || ch == 'Ґ')
			s5++;
		else if (ch == 'д' || ch == 'Д')
			s6++;
		else if (ch == 'е' || ch == 'Е')
			s7++;
		else if (ch == 'є' || ch == 'Є')
			s8++;
		else if (ch == 'ж' || ch == 'Ж')
			s9++;
		else if (ch == 'з' || ch == 'З')
			s10++;
		else if (ch == 'и' || ch == 'И')
			s11++;
		else if (ch == 'і' || ch == 'І')
			s12++;
		else if (ch == 'ї' || ch == 'Ї')
			s13++;
		else if (ch == 'й' || ch == 'Й')
			s14++;
		else if (ch == 'к' || ch == 'К')
			s15++;
		else if (ch == 'л' || ch == 'Л')
			s16++;
		else if (ch == 'м' || ch == 'М')
			s17++;
		else if (ch == 'н' || ch == 'Н')
			s18++;
		else if (ch == 'о' || ch == 'О')
			s19++;
		else if (ch == 'п' || ch == 'П')
			s20++;
		else if (ch == 'р' || ch == 'Р')
			s21++;
		else if (ch == 'с' || ch == 'С')
			s22++;
		else if (ch == 'т' || ch == 'Т')
			s23++;
		else if (ch == 'у' || ch == 'У')
			s24++;
		else if (ch == 'ф' || ch == 'Ф')
			s25++;
		else if (ch == 'х' || ch == 'Х')
			s26++;
		else if (ch == 'ц' || ch == 'Ц')
			s27++;
		else if (ch == 'ч' || ch == 'Ч')
			s28++;
		else if (ch == 'ш' || ch == 'Ш')
			s29++;
		else if (ch == 'щ' || ch == 'Ш')
			s30++;
		else if (ch == 'ь' || ch == 'Ь')
			s31++;
		else if (ch == 'ю' || ch == 'Ю')
			s32++;
		else if (ch == 'я' || ch == 'Я')
			s33++;
	
	}
	fin.close();
	
	cout << "Все працює, кількість кожної букви алфавіту з файлу Текст записано у файл Кількість букв.Перейдіть до файлу, щоб переглянути результати";
	
	ofstream fout;
	fout.open("Кількість букв.txt");
	fout << "a=: " << s1 << endl;
	fout << "б=: " << s2 << endl;
	fout << "в=: " << s3 << endl;
	fout << "г=: " << s4 << endl;
	fout << "ґ=: " << s5 << endl;
	fout << "д=: " << s6 << endl;
	fout << "е=: " << s7 << endl;
	fout << "є=: " << s8 << endl;
	fout << "ж=: " << s9 << endl;
	fout << "з=: " << s10 << endl;
	fout << "и=: " << s11 << endl;
	fout << "і=: " << s12 << endl;
	fout << "ї=: " << s13 << endl;
	fout << "й=: " << s14 << endl;
	fout << "к=: " << s15 << endl;
	fout << "л=: " << s16 << endl;
	fout << "м=: " << s17 << endl;
	fout << "н=: " << s18 << endl;
	fout << "о=: " << s19 << endl;
	fout << "п=: " << s20 << endl;
	fout << "р=: " << s21 << endl;
	fout << "с=: " << s22 << endl;
	fout << "т=: " << s23 << endl;
	fout << "у=: " << s24 << endl;
	fout << "ф=: " << s25 << endl;
	fout << "х=: " << s26 << endl;
	fout << "ц=: " << s27 << endl;
	fout << "ч=: " << s28 << endl;
	fout << "ш=: " << s29 << endl;
	fout << "щ=: " << s30 << endl;
	fout << "ь=: " << s31 << endl;
	fout << "ю=: " << s32 << endl;
	fout << "я=: " << s33 << endl;
	fout.close();
	_getch();
	
	return 0;
}

