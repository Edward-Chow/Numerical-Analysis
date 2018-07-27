#include <cstdio>

double f(double x, double y)
{
	return y - 2 * x / y;
}

void RungeKutta(double f(double x, double y), double x0, double y0, double h, int N)
{
	double x1, y1, K1, K2, K3, K4;
	˙
	for (int i = 1; i < N; i++, x0 = x1, y0 = y1)
	{
		x1 = x0 + h;
		K1 = f(x0, y0);
		K2 = f(x0 + h / 2, y0 + h / 2 * K1);
		K3 = f(x0 + h / 2, y0 + h / 2 * K2);
		K4 = f(x1, y0 + h * K3);
		y1 = y0 + h / 6 * (K1 + 2 * K2 + 2 * K3 + K4);

		printf("x1 = %.1f, y1 = %f\n", x1, y1);
	}
}
˙
int main()
{
	RungeKutta(f, 0, 1, 0.2, 5);
	return 0;
}