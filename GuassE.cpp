#include <iostream>
#include <stdlib.h>
#define MAX 0xFFFFFFFFF
using namespace std;
int SelectMainElement(double** a, int number, int index)
{
	int maxindex = index;
	for (int i = index; i < number; i++)
	{
		if (a[i][index] > a[maxindex][index] )
		{
			maxindex = i;
		}
	}
	return maxindex;
}
double **ExchangetheRow(double** a, int number, int index, int Mainindex)
{
	for (int i = 0; i < number; i++)
	{
		double temp = a[index][i];
		a[index][i] = a[Mainindex][i];
		a[Mainindex][i] = temp;
	}
	return a;
}
int main(void)
{
	int number;
	cin >> number;
	double **a;
	a = new double *[number];
	for (int i = 0; i < number; i++)
	{
		a[i] = new double[number];
	}
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "————我是分割线啦啦啦————" << endl;
	double *b;
	b = new double[number];
	for (int i = 0; i < number ; i++)
	{
		cin >> b[i];
	}
	cout << "————我是分割线啦啦啦————" << endl;
	for (int i = 0; i < number; i++)
	{
		int index = SelectMainElement(a, number, i);
		a = ExchangetheRow(a, number, i, index);
		double temp = b[i];
		b[i] = b[index];
		b[index] = temp;
		for (int j = i + 1; j < number; j++)
		{
			a[i][j] = a[i][j] / a[i][i];
		}
		b[i] = b[i] / a[i][i];
		a[i][i] = 1;
		for (int j = i + 1; j < number; j++)
		{
			for (int k = i + 1; k < number; k++)
			{
				a[j][k] = a[j][k] - a[j][i] * a[i][k];
			}
			b[j] = b[j] - a[j][i] * b[i];
			a[j][i] = 0;
		}
	}
	for (int i = number - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < number; j++)
		{
			b[i] = b[i] - a[i][j] * b[j];
		}
	}
	for (int i = 0; i < number; i++)
	{
		cout << "x[" << i + 1 << "] = " << b[i] << endl;
	}
	system("pause");
	return 0;
}
