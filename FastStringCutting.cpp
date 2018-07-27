#include <iostream>
#include <cmath>
using namespace std;
double F(double x)
{
	double res;
	res = x * exp(x) - 1;
	return res;
}
/*double f(double x)
{
    double res;
    res = exp(x) + x * exp(x);
    return res;
}*/
int main()
{
	double x0, x1, j;
	int N;
	cin >> x0 >> x1 >> j;
	cin >> N;
	int k = 1;
	double x2;
	while (k != N)
	{
		x2 = x1 - F(x1) / (F(x1) - F(x0)) * (x1 - x0);
		if (x1 - x0 < j && x1 - x0 > -j)
			cout << x2 << endl;
		k = k + 1;
		x0 = x1;
		x1 = x2;
	}

	return 0;
}