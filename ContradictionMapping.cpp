#include <iostream>
#include <cmath>
using namespace std;
double f(double x)
{
    double res;
    res = pow(x + 1, 1.0 / 3);
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
        x1 = f(x0);
        if (x1 - x0 < j && x1 - x0 > -j)
        {
            cout << x1 << endl;
            break;
        }
        if (k == N)
        {
            cout << "fail" << endl;
            break;
        }
        k = k + 1;
        x0 = x1;
    }
}