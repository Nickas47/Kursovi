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
	ifstream fin("�����.txt"); 
	while (fin.get(ch))
	{
		if (ch == '�' || ch == '�')
			s1++;
		else if(ch == '�' || ch == '�')
			s2++;
		else if (ch == '�' || ch == '�')
			s3++;
		else if (ch == '�' || ch == '�')
			s4++;
		else if (ch == '�' || ch == '�')
			s5++;
		else if (ch == '�' || ch == '�')
			s6++;
		else if (ch == '�' || ch == '�')
			s7++;
		else if (ch == '�' || ch == '�')
			s8++;
		else if (ch == '�' || ch == '�')
			s9++;
		else if (ch == '�' || ch == '�')
			s10++;
		else if (ch == '�' || ch == '�')
			s11++;
		else if (ch == '�' || ch == '�')
			s12++;
		else if (ch == '�' || ch == '�')
			s13++;
		else if (ch == '�' || ch == '�')
			s14++;
		else if (ch == '�' || ch == '�')
			s15++;
		else if (ch == '�' || ch == '�')
			s16++;
		else if (ch == '�' || ch == '�')
			s17++;
		else if (ch == '�' || ch == '�')
			s18++;
		else if (ch == '�' || ch == '�')
			s19++;
		else if (ch == '�' || ch == '�')
			s20++;
		else if (ch == '�' || ch == '�')
			s21++;
		else if (ch == '�' || ch == '�')
			s22++;
		else if (ch == '�' || ch == '�')
			s23++;
		else if (ch == '�' || ch == '�')
			s24++;
		else if (ch == '�' || ch == '�')
			s25++;
		else if (ch == '�' || ch == '�')
			s26++;
		else if (ch == '�' || ch == '�')
			s27++;
		else if (ch == '�' || ch == '�')
			s28++;
		else if (ch == '�' || ch == '�')
			s29++;
		else if (ch == '�' || ch == '�')
			s30++;
		else if (ch == '�' || ch == '�')
			s31++;
		else if (ch == '�' || ch == '�')
			s32++;
		else if (ch == '�' || ch == '�')
			s33++;
	
	}
	fin.close();
	
	cout << "��� ������, ������� ����� ����� ������� � ����� ����� �������� � ���� ʳ������ ����.�������� �� �����, ��� ����������� ����������";
	
	ofstream fout;
	fout.open("ʳ������ ����.txt");
	fout << "a=: " << s1 << endl;
	fout << "�=: " << s2 << endl;
	fout << "�=: " << s3 << endl;
	fout << "�=: " << s4 << endl;
	fout << "�=: " << s5 << endl;
	fout << "�=: " << s6 << endl;
	fout << "�=: " << s7 << endl;
	fout << "�=: " << s8 << endl;
	fout << "�=: " << s9 << endl;
	fout << "�=: " << s10 << endl;
	fout << "�=: " << s11 << endl;
	fout << "�=: " << s12 << endl;
	fout << "�=: " << s13 << endl;
	fout << "�=: " << s14 << endl;
	fout << "�=: " << s15 << endl;
	fout << "�=: " << s16 << endl;
	fout << "�=: " << s17 << endl;
	fout << "�=: " << s18 << endl;
	fout << "�=: " << s19 << endl;
	fout << "�=: " << s20 << endl;
	fout << "�=: " << s21 << endl;
	fout << "�=: " << s22 << endl;
	fout << "�=: " << s23 << endl;
	fout << "�=: " << s24 << endl;
	fout << "�=: " << s25 << endl;
	fout << "�=: " << s26 << endl;
	fout << "�=: " << s27 << endl;
	fout << "�=: " << s28 << endl;
	fout << "�=: " << s29 << endl;
	fout << "�=: " << s30 << endl;
	fout << "�=: " << s31 << endl;
	fout << "�=: " << s32 << endl;
	fout << "�=: " << s33 << endl;
	fout.close();
	_getch();
	
	return 0;
}

