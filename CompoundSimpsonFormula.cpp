#include <iostream>
#include <cmath>
using namespace std;

double CompoundSimpson(double a, double b, double n, double f(double x))
{
	double h, xk, xj;
	h = (b - a) / n;
	double s1 = 0.0;
	double s2 = 0.0;
	for (int k = 0; k < n; k++)
	{
		xk = a + k * h;
		s1 += f(xk);
	}
	for (int j = 0; j < n; j++)
	{
		xj = a + (j + 0.5) * h;
		s2 += f(xj);
	}
	return h / 6 * (f(a) - f(b) + 2 * s1 + 4 * s2);
}

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
	double sim = CompoundSimpson(0, 1, 8, f);
	cout << "Simpsom :" << sim << endl;
	return 0;
}