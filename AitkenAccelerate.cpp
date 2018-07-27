#include <iostream>
#include <cmath>
using namespace std;
double f(double x)
{
    double res;
    res = exp(-x);
    return res;
}
int main()
{
    double x0, j;
    int N;
    cin >> x0 >> j;
    cin >> N;
    int k = 1;
    double x1, x2;
    while (1)
    {
        x1 = f(x0);
        x2 = f(x1);
        x2 = x2 - (x2 - x1) * (x2 - x1) / (x2 - 2 * x1 + x0);
        if (x2 - x0 < j && x2 - x0 > -j)
        {
            cout << x2 << endl;
            break;
        }
        if (k == N)
        {
            cout << "fail" << endl;
            break;
        }
        k = k + 1;
        x0 = x2;
    }
}