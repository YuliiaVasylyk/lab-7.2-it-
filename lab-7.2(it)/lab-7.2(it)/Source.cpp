// Lab_07_2(it).cpp
// <Василик Юлія>
// Лабораторна робота №7.2(ітераційний спосіб)
// Опрацювання багатовимірних масивів
// Варіант 2


#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int k, const int n)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
}

int Max(int** a, const int n, int i)
{
	int max = a[0][0];
	for (int j = 0; j < n; j++)
	{
		if (a[i][j] > max)
			max = a[i][j];
	}
	return max;
}

int SumMax(int** a, const int k, const int n)
{
	int s = 0;

	int max = a[0][0];
	for (int i = 0; i < k; i++)
	{
		max = Max(a, n, i);
		s += max;
		cout << max << endl;
	}
	return s;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int Low, High;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	cout << "a[" << k << "][" << n << "] = " << endl;
	Print(a, k, n);

	cout << "Сума максимальних елементів по всіх рядках матриці = " << SumMax(a, k, n) << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
