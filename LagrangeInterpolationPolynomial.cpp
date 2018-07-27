#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Please input the number of variable:" << endl;
	cin >> n;

	double x;
	cout << "Please input the value of x:" << endl;
	cin >> x;

	double a[n], b[n];
	cout << "Please input the value of Xi:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "Please input the value of Yi" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double k = 1.0;
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				k *= (x - a[j]) / (a[i] - a[j]);
			}
		}
		sum += k * b[i];
	}

	cout << "Pn(" << x << ") = " << sum << endl;
	return 0;
}