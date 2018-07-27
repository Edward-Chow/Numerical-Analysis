#include <iostream>
using namespace std;

double f(double x)
{
	return (x * x * x - x - 1);
}

int main()
{
	double a, b, precision;
	cout << "please cin the left coordinate and the right coordinate:" << endl;
	cin >> a;
	cin >> b;
	cout << "Please set the precision:" << endl;
	cin >> precision;

	double x, y, y0 = f(a);
	while ((b - a) >= precision)
	{
		x = (a + b) / 2;
		y = f(x);

		if (y * y0 <= 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}
	}

	cout << "x:" << x << "\ty:" << y << endl;
	return 0;
}