#include <bits/stdc++.h>
using namespace std;

//modular invser exists when a,m are relatively prime ie gcd(a,m)=1

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
    int a, m, x, y;
    cin >> a >> m;
    int g = gcd(a, m, x, y);
    if (g != 1)
    {
        cout << "No solution";
    }
    else
    {
        x = (x % m + m) % m;
        cout << x << endl;
    }
}