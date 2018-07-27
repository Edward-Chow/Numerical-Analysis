#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	switch ((int)round(x * 8))
	{
	case 0: return 1;
	case 1: return .9973978;
	case 2: return .9896158;
	case 3: return .9767267;
	case 4: return .9588510;
	case 5: return .9361556;
	case 6: return .9088516;
	case 7: return .8771925;
	case 8: return .8414709;
	}
	return 0;
}

int main()
{
	double a, b, precision;
	a = 0;
	b = 1;
	precision = 0.0005;
	double h = b - a;
	double T1, T2;
	T1 = h / 2 * (f(a) + f(b));

	do
	{
		double S = 0;
		double x = a + h / 2;
		while (x < b)
		{
			S += f(x);
			x += h;
		}
		T2 = T1 / 2 + h / 2 * S;
		h = h / 2;
		T1 = T2;
	}
	while (fabs(T2 - T1) >= precision);

	cout << T2 << endl;
	return 0;
}