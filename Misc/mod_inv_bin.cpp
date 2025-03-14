#include <bits/stdc++.h>
using namespace std;
int pow_mod(int x, int n, int m) //similar to binpow_mod func in binary_exponentiation.cpp
{
    if (n == 0)
        return 1;
    int t = pow_mod(x, (int)floor(n / 2), m);
    if (n % 2 == 0)
        return (int)fmod(t * t, m);
    else
        return (int)fmod(t * t * x, m);
}

void modInverse(int a, int m)
{
    int g = __gcd(a, m);
    if (g != 1)
        cout << "No solution";
    else
        cout << pow_mod(a, m - 2, m);
}

int main()
{
    int a, m;
    cin >> a >> m;
    modInverse(a, m);
}