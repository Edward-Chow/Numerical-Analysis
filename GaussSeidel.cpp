#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
double a[3][3] = {{10, -1, -2}, { -1, 10, -2}, { -1, -1, 5}};
double b[3] = {7.2, 8.3, 4.2};
int main ()
{
	double x[3], y[3];
	double N;
	cin >> N;
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i];
		y[i] = x[i];
	}
	int k = 1;
	double j;
	cin >> j;
	while (k != N)
	{
		for (int i = 0; i < 3; i++)
		{
			double sum = 0;
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
				{
					sum += a[i][j] * x[j];
				}
			}
			y[i] = (b[i] - sum) / a[i][i];
			x[i] = y[i];
		}
		double max = 0;
		for (int i = 0; i < 3; i++)
		{
			if (fabs(x[i] - y[i]) > max)
			{
				max = fabs(x[i] - y[i]);
			}
		}
		if (max < j)
		{
			for (int i = 0; i < 3; i++)
			{
				cout << y[i] << " ";
			}
			cout << e
		}
		k++;
		for (int i = 0; i < 3; i++)
		{
			x[i] = y[i];
		}

	}
	return 0;
}