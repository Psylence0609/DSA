#include <bits/stdc++.h>
using namespace std;
/**
While the Euclidean algorithm calculates only the greatest common divisor (GCD) of two integers a and b,
the extended version also finds a way to represent GCD in terms of a and b, i.e. coefficients x and y for which:

a⋅x+b⋅y=gcd(a,b)
**/
int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int x, y;
    int ans = gcd(a, b, x, y);
    cout << ans << endl;
    cout << x << endl;
    cout << y;
}