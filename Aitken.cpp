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

	for (int k = 1; k < n; k++)
	{
		for (int i = k; i <= n; i++)
		{
			b[i] = b[k - 1] + (b[i] - b[k - 1]) / (a[i] - a[k - 1]) * (x - a[k - 1]);
		}
	}

	cout << "y = " << b[n - 1] << endl;
	return 0;
}