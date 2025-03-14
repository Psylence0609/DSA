#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return b * a / GCD(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    int gcd = GCD(a, b);
    cout << "GCD: " << gcd << endl;
    int lcm = LCM(a, b);
    cout << "LCM: " << lcm;
}