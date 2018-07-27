#include <iostream>
using namespace std;
void SelectMainEle(double a[][4], double b[], int k)
{
    int n = sizeof(b);
    double d = a[k][k];
    int l = k;
    int i = k + 1;
    while (1)
    {
        if (a[i][k]*a[i][k] > d * d)
        {
            d = a[i][k];
            l = i;
        }
        if (i != n)
        {
            i = i + 1;
        }
        else
        {
            if (d == 0)
            {
                cout << "fail" << endl;
                return;
            }
            else
            {
                if (l != k)
                {
                    for (int j = k; j <= n; j++)
                    {
                        double t = a[l][j];
                        a[l][j] = a[k][j];
                        a[k][j] = t;
                    }
                    double t = b[k];
                    b[k] = b[l];
                    b[l] = t;
                }
            }
            break;
        }
    }
}
int main()
{
    double a[4][4] = {0, 0, 0, 0, 0, 2, -1, 3, 0, 4, 2, 5, 0, 1, 2, 0};
    double b[4] = {0, 1, 4, 7};
    int k = 1;
    int n = 3;
    double s = 0;
    while (1)
    {
        SelectMainEle(a, b, k);
        for (int j = k + 1; j <= n; j++)
        {
            a[k][j] = a[k][j] / a[k][k];
        }
        b[k] = b[k] / a[k][k];
        for (int i = k + 1; i <= n; i++)
        {
            for (int j = k + 1; j <= n; j++)
            {
                a[i][j] = a[i][j] - a[i][k] * a[k][j];
            }
        }
        for (int i = k + 1; i <= n; i++)
        {
            b[i] = b[i] - a[i][k] * b[k];
        }
        if (k != n)
        {
            k = k + 1;
        }
        else
        {
            for (int i = n - 1; i >= 1; i--)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    s = s + a[i][j] * b[j];
                }
                b[i] = b[i] - s;
                s = 0;
            }
            for (int i = 1; i <= n; i++)
            {
                cout << b[i] << endl;
            }
            break;
        }
    }
}