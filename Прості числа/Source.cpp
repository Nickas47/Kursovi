#include <iostream>
#include <iomanip>
#include <ctime>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr");
	cout << "Алгоритм Решето Сандарма" << endl << endl;
	int t = clock();
	// Алгоритм Решето Сандарма
	int no, io, jo, ko;
	cout << "n=";
	cin >> no;
	int *a = new int[no];
	for (io = 0; io < no; io++)
	{
		a[io] = 1;
	}
	for (io = 1; 3 * io + 1 < no; io++)
	{
		for (jo = 1; (ko = io + jo + 2 * io*jo) < no && jo <= io; jo++)
		{
			a[ko] = 0;
		}
	}
	int q = 0;
	for (io = 1; io < no; io++)
	{
		if (a[io] == 1)
		{
			cout << setw(5) << (2 * io + 1) << " ";
			q++;
			if (q % 5 == 0) cout << endl;
		}
	}
	int t1 = clock();
	float r = t1 - t;
	cout << "Time one = " << ((float)r / CLOCKS_PER_SEC) << endl << endl;

	cout << "Алгоритм Решето Аткина" << endl << endl;
	int t2 = clock();
	// Алгоритм Решето Аткина
	int limit;
	cout << "n=";
	cin >> limit;

	int sqr_lim;
	bool is_prime[101];
	int x2, y2;
	int i, j;
	int n;


	sqr_lim = (int)sqrt((long double)limit);
	for (i = 0; i <= limit; i++) is_prime[i] = false;
	is_prime[2] = true;
	is_prime[3] = true;


	x2 = 0;
	for (i = 1; i <= sqr_lim; i++) {
		x2 += 2 * i - 1;
		y2 = 0;
		for (j = 1; j <= sqr_lim; j++) {
			y2 += 2 * j - 1;

			n = 4 * x2 + y2;
			if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
				is_prime[n] = !is_prime[n];

			n -= x2;
			if ((n <= limit) && (n % 12 == 7))
				is_prime[n] = !is_prime[n];


			n -= 2 * y2;
			if ((i > j) && (n <= limit) && (n % 12 == 11))
				is_prime[n] = !is_prime[n];
		}
	}
	for (i = 5; i <= sqr_lim; i++) {
		if (is_prime[i]) {
			n = i * i;
			for (j = n; j <= limit; j += n) {
				is_prime[j] = false;
			}
		}
	}

	printf("2, 3, 5");
	for (i = 6; i <= limit; i++) {
		if ((is_prime[i]) && (i % 3 != 0) && (i % 5 != 0)) {
			printf(", %d", i);
		}
	}
	int t3 = clock();
	float r1 = t3 - t2;
	cout << "Time two = " << ((float)r1 / CLOCKS_PER_SEC) << endl << endl;

	cout << "Алгоритм Решето Ератосфена" << endl << endl;
	// Алгоритм Решето Ератосфена
	int t4 = clock();
	int w;
	cout << "n= ";
	cin >> w;
	int *aw = new int[w + 1];
	for (int i = 0; i < w + 1; i++)
		a[i] = i;
	for (int p = 2; p < w + 1; p++)
	{
		if (a[p] != 0)
		{
			cout << a[p] << endl;
			for (int j = p * p; j < w + 1; j += p)
				a[j] = 0;
		}
	}

	int t5 = clock();
	float r2 = t5 - t4;
	cout << "Time three = " << ((float)r2 / CLOCKS_PER_SEC) << endl << endl;
	cout << "Time 1 = " << ((float)r / CLOCKS_PER_SEC) << endl << endl;
	cout << "Time 2 = " << ((float)r1 / CLOCKS_PER_SEC) << endl << endl;
	cout << "Time 3  = " << ((float)r2 / CLOCKS_PER_SEC) << endl << endl;

	float Min;
	if (((float)r / CLOCKS_PER_SEC) > ((float)r1 / CLOCKS_PER_SEC)) {
		if (((float)r / CLOCKS_PER_SEC) > ((float)r2 / CLOCKS_PER_SEC)) Min = ((float)r / CLOCKS_PER_SEC);
		else Min = ((float)r2 / CLOCKS_PER_SEC);
	}
	else {
		if (((float)r1 / CLOCKS_PER_SEC) > ((float)r2 / CLOCKS_PER_SEC)) Min = ((float)r1 / CLOCKS_PER_SEC);
		else Min = ((float)r2 / CLOCKS_PER_SEC);
	}
	cout << "Найповiльнiший алгоритм - " << Min << endl << endl;
	float Max;
	if (((float)r / CLOCKS_PER_SEC) < ((float)r1 / CLOCKS_PER_SEC)) {
		if (((float)r / CLOCKS_PER_SEC) < ((float)r2 / CLOCKS_PER_SEC)) Max = ((float)r / CLOCKS_PER_SEC);
		else Max = ((float)r2 / CLOCKS_PER_SEC);
	}
	else {
		if (((float)r1 / CLOCKS_PER_SEC) < ((float)r2 / CLOCKS_PER_SEC)) Max = ((float)r1 / CLOCKS_PER_SEC);
		else Max = ((float)r2 / CLOCKS_PER_SEC);
	}
	cout << "Найшвидший алгоритм - " << Max << endl;
	system("pause");
	return  0;
}
