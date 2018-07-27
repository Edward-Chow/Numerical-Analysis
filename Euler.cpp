#include <cstdio>

double f(double x, double y)
{
	return y - 2 * x / y;
}

void Euler(double f(double x, double y), double x0, double y0, double h, double N)
{
	double x1, y1, yp, yc;
	for (int i = 1; i < N; i++, x0 = x1, y0 = y1)
	{
		x1 = x0 + h;
		yp = y0 + h * f(x0, y0);
		yc = y0 + h * f(x1, yp);
		y1 = (yp + yc) / 2;

		printf("x1 = %.1f y1 = %f \n", x1, y1);
	}
}

int main()
{
	Euler(f, 0, 1, 0.1, 10);
	return 0;
}