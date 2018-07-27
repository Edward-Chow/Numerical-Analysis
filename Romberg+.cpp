#include <stdio.h>
#include <math.h>

double Romberg(double a, double b, double eps, double f(double))
{
    int k = 1;
    double S, x, T1, T2, S1, S2, C1, C2, R1, R2, h = b - a;
    T1 = h * (f(a) + f(b)) / 2;
    while (1)
    {
        S = 0; x = a + h / 2;
        do
        {
            S += f(x); x += h;
        }
        while (x < b);
        T2 = (T1 + h * S) / 2.0;
        if (fabs(T2 - T1) < eps)return (T2);
        S2 = T2 + (T2 - T1) / 3.0;
        if (k == 1)
        {
            T1 = T2; S1 = S2; h /= 2; k += 1; continue;
        }
        C2 = S2 + (S2 - S1) / 15.0;
        if (k == 2)
        {
            C1 = C2; T1 = T2; S1 = S2; h /= 2.0; k += 1; continue;
        }
        R2 = C2 + (C2 - C1) / 63;
        if (k == 3)
        {
            R1 = R2; C1 = C2; T1 = T2; S1 = S2; h /= 2; k += 1; continue;
        }
        if (fabs(S1 - S2) < eps)
            return (S2);
        R1 = R2; C1 = C2; T1 = T2; S1 = S2;
        h /= 2;
        k += 1;
        return (R1);
    }
}
double func(double x)
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
    printf("%f\n", Romberg(0, 1, 1e-8, func));
    return 0;
}