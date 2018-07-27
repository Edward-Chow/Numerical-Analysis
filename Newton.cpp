#include <iostream>
#include <cmath>
using namespace std;
double F(double x)
{
    double res;
    res = x * exp(x) - 1;
    return res;
}
double f(double x)
{
    double res;
    res = exp(x) + x * exp(x);
    return res;
}
int main()
{
    double x0, j;
    int N;
    cin >> x0 >> j;
    cin >> N;
    int k = 1;
    double x1;
    while (1)
    {
        if (f(x0) == 0)
        {
            cout << " " << endl;
            break;
        }
        x1 = x0 - F(x0) / f(x0);
        if (x1 - x0 < j && x1 - x0 > -j)
        {
            cout << x1 << endl;
            break;
        }
        if (k == N)
        {
            cout << "fail" << endl;
        }
        k = k + 1;
        x0 = x1;
    }
}