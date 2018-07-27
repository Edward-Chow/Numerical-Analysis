#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "please input the value of n:" << endl;
	cin >> n;
	int a[n], x;
	cout << "please input the value of x:" << endl;
	cin >> x;

	cout << "please input the ai, every element divided by space" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int v = a[0];
	for (int i = 0; i <= n - 1; i++)
	{
		v = v * x + a[i + 1];
	}

	cout << "The value after the process Horner Algorithm:" << v << endl;
	return 0;
}